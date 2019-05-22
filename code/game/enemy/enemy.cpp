#include "enemy.hpp"
#include <math.h>
#include "../gameScene.hpp"
#include "../../blankScene.hpp"
#include <iostream>

Enemy::Enemy()
{
    realhp =hp;
    //live.setSize(sf::Vector2f(25,hp));
    live.setFillColor(sf::Color::Red);
    live2.setFillColor(sf::Color::White);
}

Enemy::~Enemy()
{
    for (Bullet* b: bullets)
        delete b;
}

void Enemy::onDrawBullet()
{
    for (Bullet* b: bullets)
        b->onDraw();
}

void Enemy::shoot(Bullet *New)
{
    bullets.push_back(New);
}

sf::Vector2f Enemy::move()
{
    GameScene& s = *dynamic_cast <GameScene*>(scene.actual());
    sf::Vector2f x;
    if(m < s.gameArea.enemy.moves.size())
    {
        float dx = body.getPosition().x - s.gameArea.enemy.moves[m].x*100;
        float dy = body.getPosition().y - s.gameArea.enemy.moves[m].y*100;

        float d = fabs(dx) + fabs(dy);
        float movement = logic.deltaTime * speed;
        if(logic.deltaTime * speed >= d)
            m++;
        else
        {

            if(dx < 0) x+= sf::Vector2f(movement,0);
            if(dx > 0) x+= sf::Vector2f(-movement,0);
            if(dy < 0) x+= sf::Vector2f(0,movement);
            if(dy > 0) x+= sf::Vector2f(0,-movement);
        }

    }
    else {std::cout << std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl
            << "Unfortunately, I did not have enough time to finish the game :( "<< std::endl << "created by Qikcik(querk) for Ludum Dare 41 in C++ and SFMl , using font arial" << std::endl << "score: " << s.exp << std::endl ; render.window.close();}
    live2.setSize(sf::Vector2f(hp/4+4,14));
    live2.setPosition(body.getPosition() + sf::Vector2f(50 - live.getSize().x /4 - 2,5));
    live.setSize(sf::Vector2f(hp/4,10));
    live.setPosition(body.getPosition() + sf::Vector2f(50 - live.getSize().x /4,7));


    for (std::vector <Bullet*>::iterator it=bullets.begin(); it!=bullets.end();)
    {
        (*it)->onUpdate();
        if((*it)->toDelete)
        {
            delete (*it);
            it = bullets.erase(it);
        }
        else ++it;
    }

    return x;
}

void Enemy::configureMove()
{
    GameScene& s = *dynamic_cast <GameScene*>(scene.actual());
    body.setSize(sf::Vector2f(100,100));
    //body.setTexture(asset.texture.load("enemies/orc"));
    body.setPosition(sf::Vector2f(s.gameArea.tileStartX*100,s.gameArea.tileStartY*100));
    m = 0;
}
