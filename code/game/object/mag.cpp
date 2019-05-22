#include "mag.hpp"
#include "../gameScene.hpp"

Mag::Mag(sf::Vector2i pos)
{

    configure("objects/mag",pos);
    isClicked = true;

    //upgradeable1 = new (pos);

    Object::name = "Mag Turret";
    Object::descrption = "Epic Damage";
    Object::people = -1;
    Object::peoplePerSecond = 0;

    Object::resource =-150;
    Object::resourcePerSecond =0;

    Object::food = 0;
    Object::foodPerSecond =0;

    Object::exp=0;
}

Mag::~Mag()
{

}

void Mag::onDraw()
{
    render.window.draw(body);
}

void Mag::onUpdate()
{
    time += logic.deltaTime;
    if(time > cooldown)
    {
        time-= cooldown;
        GameScene& s = *dynamic_cast <GameScene*>(scene.actual());
        int mx = body.getPosition().x+50;
        int my = body.getPosition().y+50;

        for(Enemy* it : s.gameArea.enemy.enemy)
        {
            int dx = mx - it->getRealCenter().x;
            int dy = my - it->getRealCenter().y;

            float distSq = dx*dx + dy*dy;
            if(distSq < range*range)
            {
                if(it->realhp  > 0 )
                {
                    it->realhp -= damage;
                    it->shoot(new Bullet(speed, damage, &*it , sf::Vector2f(body.getPosition().x+50,body.getPosition().y+50) , *asset.texture.load("objects/ball")));
                    break;

                }
            }
        }
    }

    Object::updatePerSecond();
}



