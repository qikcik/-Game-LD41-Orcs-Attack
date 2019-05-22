#include "road.hpp"

Road::Road(sf::Vector2i pos, int type)
{
    configure("objects/road",pos);
    if(type == 9)
        body.setTextureRect(sf::IntRect(200,0,100,100));
    else if(type == 8 || type == 2)
        body.setTextureRect(sf::IntRect(100,0,100,100));
    else if(type == 7)
        body.setTextureRect(sf::IntRect(0,0,100,100));
    else if(type == 6 || type == 4)
        body.setTextureRect(sf::IntRect(0,100,100,100));
    else if(type == 3)
        body.setTextureRect(sf::IntRect(200,200,100,100));
    else if(type == 1)
        body.setTextureRect(sf::IntRect(0,200,100,100));
}

Road::~Road()
{

}

void Road::onDraw()
{
    render.window.draw(body);
}

void Road::onUpdate()
{

}



