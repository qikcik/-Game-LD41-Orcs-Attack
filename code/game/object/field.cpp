#include "field.hpp"
#include "wheatField.hpp"


Field::Field(sf::Vector2i pos)
{
    configure("objects/field",pos);
    isClicked = true;

    upgradeable1 = new WheatField(pos);
    //upgradeable2 = new LumberJack(pos);

    Object::name = "Field";
    Object::descrption = "produce food";
    Object::people = 0;
    Object::peoplePerSecond = 0;

    Object::resource =0;
    Object::resourcePerSecond =0;

    Object::food = 0;
    Object::foodPerSecond =0;

    Object::exp=0;

}

Field::~Field()
{

}

void Field::onDraw()
{
    render.window.draw(body);
}

void Field::onUpdate()
{
    updatePerSecond();
}



