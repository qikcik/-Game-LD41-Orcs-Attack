#include "nothing.hpp"
#include "slingshot.hpp"
#include "house.hpp"

Nothing::Nothing(sf::Vector2i pos)
{
    configure("objects/background",pos);
    isClicked = true;

    upgradeable1 = new Slingshot(pos);
    upgradeable2 = new House(pos);

    Object::name = "field";
    Object::descrption = "for turret or house";
    Object::people = 0;
    Object::peoplePerSecond = 0;

    Object::resource =10;
    Object::resourcePerSecond =0;

    Object::food = 0;
    Object::foodPerSecond =0;

    Object::exp=0;

}

Nothing::~Nothing()
{

}

void Nothing::onDraw()
{
    render.window.draw(body);
}

void Nothing::onUpdate()
{
    updatePerSecond();
}



