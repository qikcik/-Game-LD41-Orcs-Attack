#include "wheatField.hpp"


WheatField::WheatField(sf::Vector2i pos)
{
    configure("objects/wheatField",pos);
    isClicked = true;

    //upgradeable1 = new Nothing(pos);
    //upgradeable2 = new LumberJack(pos);

    Object::name = "WheatField";
    Object::descrption = "produce food";
    Object::people = -2;
    Object::peoplePerSecond = 0;

    Object::resource =0;
    Object::resourcePerSecond =0;

    Object::food = 0;
    Object::foodPerSecond =5;

    Object::exp=0;

}

WheatField::~WheatField()
{

}

void WheatField::onDraw()
{
    render.window.draw(body);
}

void WheatField::onUpdate()
{
    updatePerSecond();
}



