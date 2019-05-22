#include "bullet.hpp"
#include "math.h"

Bullet::~Bullet()
{

}

Bullet::Bullet(int s, int d, Enemy *t, sf::Vector2f pos,sf::Texture &tex)
{
    speed =s;
    damage =d;
    target = t;
    sprite.setPosition(pos);
    sprite.setTexture(tex);
    sprite.setOrigin(sf::Vector2f(sprite.getGlobalBounds().width/2,sprite.getGlobalBounds().height/2));
}

void Bullet::onDraw(){
    render.window.draw(sprite);
}

void Bullet::onUpdate(){
    target =  (Enemy*)target;
    if(target == nullptr)
    {
        toDelete = true;
    }
    else
        {
        float dx = sprite.getPosition().x - target->getRealCenter().x;
        float dy = sprite.getPosition().y - target->getRealCenter().y;

        float d = fabs(dx) + fabs(dy);
        float movement = LogicManager::get().deltaTime * speed;
        if(movement >= d && target->hp > 0)
        {
            target->hp -= damage;
            toDelete = true;
        }
        else if (target->hp < 1)
        {
            toDelete = true;
        }
        else
        {
            if(dx < 0) sprite.move(sf::Vector2f(movement,0));
            if(dx > 0) sprite.move(sf::Vector2f(-movement,0));
            if(dy < 0) sprite.move(sf::Vector2f(0,movement));
            if(dy > 0) sprite.move(sf::Vector2f(0,-movement));

            sprite.rotate( d/100 );

        }
    }
}


