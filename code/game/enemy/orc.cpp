#include "orc.hpp"
#include <math.h>
#include <iostream>
#include "../gameScene.hpp"

Orc::Orc(int h)
{
    configureMove();
    body.setTexture(asset.texture.load("enemies/orc"));
    //body.setSize(sf::Vector2f(100,100));
    //body.setPosition(0,0);

    Enemy::speed = 200;
    Enemy::hp =h;
    Enemy::exp = 20;
    Enemy::realhp = h;
}

Orc::~Orc()
{

}

void Orc::onUpdate()
{
    body.move(move());
    //std::cout << move().x << std::endl;
}

void Orc::onDraw()
{
    render.window.draw(body);
    render.window.draw(live2);
    render.window.draw(live);
}

sf::Vector2f Orc::getRealCenter()
{
    return sf::Vector2f(body.getPosition().x  + 50 , body.getPosition().y + 50  );
}

