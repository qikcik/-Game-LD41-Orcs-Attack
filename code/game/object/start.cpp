#include "start.hpp"
#include "slingshot.hpp"
#include "house.hpp"

Start::Start(sf::Vector2i pos)
{
    configure("objects/start",pos);
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

Start::~Start()
{

}

void Start::onDraw()
{
    render.window.draw(body);
}

void Start::onUpdate()
{
    updatePerSecond();
}



