#include "house.hpp"
//#include ".hpp"


House::House(sf::Vector2i pos)
{
    configure("objects/house",pos);
    isClicked = true;

    //upgradeable1 = new WheatHouse(pos);
    //upgradeable2 = new LumberJack(pos);

    Object::name = "House";
    Object::descrption =  "...";
    Object::people = 5;
    Object::peoplePerSecond = 0;

    Object::resource =-10;
    Object::resourcePerSecond =0;

    Object::food = -1;
    Object::foodPerSecond =-1;

    Object::exp=0;

}

House::~House()
{

}

void House::onDraw()
{
    render.window.draw(body);
}

void House::onUpdate()
{
    updatePerSecond();
}



