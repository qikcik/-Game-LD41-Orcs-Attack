#include "castle.hpp"

Castle::Castle(sf::Vector2i pos)
{
    configure("objects/castle",pos);
    //isClicked = true;

    //upgradeable1 = new Slingshot(pos);
    //upgradeable2 = new House(pos);

    Object::name = "not define";
    Object::descrption = "not define";
    Object::people = 0;
    Object::peoplePerSecond = 0;

    Object::resource =10;
    Object::resourcePerSecond =0;

    Object::food = 0;
    Object::foodPerSecond =0;

    Object::exp=0;

}

Castle::~Castle()
{

}

void Castle::onDraw()
{
    render.window.draw(body);
}

void Castle::onUpdate()
{
    updatePerSecond();
}



