#include "forest.hpp"
#include "slingshot.hpp"

#include "lumberjack.hpp"

Forest::Forest(sf::Vector2i pos)
{
    configure("objects/forest",pos);
    isClicked = true;

    upgradeable1 = new Nothing(pos);
    upgradeable2 = new LumberJack(pos);

    Object::name = "Forest";
    Object::descrption = "Just a forrest :)";
    Object::people = 0;
    Object::peoplePerSecond = 0;

    Object::resource =0;
    Object::resourcePerSecond =0;

    Object::food = 0;
    Object::foodPerSecond =0;

    Object::exp=0;

}

Forest::~Forest()
{

}

void Forest::onDraw()
{
    render.window.draw(body);
}

void Forest::onUpdate()
{
    updatePerSecond();
}



