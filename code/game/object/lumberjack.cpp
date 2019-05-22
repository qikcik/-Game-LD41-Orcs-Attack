#include "lumberjack.hpp"
#include "slingshot.hpp"

LumberJack::LumberJack(sf::Vector2i pos)
{
    configure("objects/lumberjack",pos);
    isClicked = true;

    //upgradeable1 = new Nothing(pos);

    Object::name = "LumberJack";
    Object::descrption = "Product some resources";
    Object::people = -1;
    Object::peoplePerSecond = 0;

    Object::resource =-15;
    Object::resourcePerSecond =1;

    Object::food = 0;
    Object::foodPerSecond =0;

    Object::exp=0;

}

LumberJack::~LumberJack()
{

}

void LumberJack::onDraw()
{
    render.window.draw(body);
}

void LumberJack::onUpdate()
{
    updatePerSecond();
}



