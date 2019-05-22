#include "selector.hpp"
#include <iostream>
#include "gameScene.hpp"

#define MapX 16
#define MapY 9

Selector::Selector()
{
    this->tileSize = tileSize;
    mouse.setSize(sf::Vector2f(150,150));
    mouse.setTexture(asset.texture.load("objects/selector"));
    mouse.setOrigin(sf::Vector2f(25,25));

    toBuild[0].setScale(sf::Vector2f(0.5,0.5));
    toBuild[1].setScale(sf::Vector2f(0.5,0.5));

    info.setTexture(*asset.texture.load("tileInfo"));
    info.setPosition(sf::Vector2f(0,900-300));
    for(int i=0;i!=10;i++)
    {
        infoText[i].setCharacterSize(30);
        infoText[i].setFont(asset.font);
        //infoText[i].text.setPosition(sf::Vector2f(200*int(i/4)+50+,200*(int)i/2+200));
        infoText[i].setColor(sf::Color::Black);
    }
}

Selector::~Selector()
{

}

void Selector::onDraw()
{
    if(drawing)
    {
        render.window.draw(mouse);
        if(drawToBuild > 0) render.window.draw(toBuild[0]);
        if(drawToBuild > 1) render.window.draw(toBuild[1]);

        sf::Vector2f m = render.window.mapPixelToCoords((sf::Vector2i)sf::Mouse::getPosition(render.window));
        GameScene& s = *dynamic_cast <GameScene*>(scene.actual());

        if(drawToBuild > 0 && toBuild[0].getGlobalBounds().contains(m))
        {
            /// info
            infoText[9].setString(s.gameArea.object.get(x,y)->upgradeable1->name);
            infoText[8].setString(s.gameArea.object.get(x,y)->upgradeable1->descrption);

            infoText[0].setString(std::to_string(s.gameArea.object.get(x,y)->upgradeable1->resource));
            infoText[1].setString(std::to_string(s.gameArea.object.get(x,y)->upgradeable1->food));
            infoText[2].setString(std::to_string(s.gameArea.object.get(x,y)->upgradeable1->people));
            //infoText[3].setString(s.gameArea.object.get(x,y)->upgradeable1->exp);

            infoText[4].setString(std::to_string(s.gameArea.object.get(x,y)->upgradeable1->resourcePerSecond));
            infoText[5].setString(std::to_string(s.gameArea.object.get(x,y)->upgradeable1->foodPerSecond));
            infoText[6].setString(std::to_string(s.gameArea.object.get(x,y)->upgradeable1->peoplePerSecond));
            //infoText[7].setString(s.gameArea.object.get(x,y)->upgradeable1->exp);

            render.window.draw(info);

            for(int i=0;i!=10;i++)
                render.window.draw(infoText[i]);
        }

        if(drawToBuild > 1 && toBuild[1].getGlobalBounds().contains(m))
        {
            /// info
            infoText[9].setString(s.gameArea.object.get(x,y)->upgradeable2->name);
            infoText[8].setString(s.gameArea.object.get(x,y)->upgradeable2->descrption);

            infoText[0].setString(std::to_string(s.gameArea.object.get(x,y)->upgradeable2->resource));
            infoText[1].setString(std::to_string(s.gameArea.object.get(x,y)->upgradeable2->food));
            infoText[2].setString(std::to_string(s.gameArea.object.get(x,y)->upgradeable2->people));
            //infoText[3].setString(s.gameArea.object.get(x,y)->upgradeable1->exp);

            infoText[4].setString(std::to_string(s.gameArea.object.get(x,y)->upgradeable2->resourcePerSecond));
            infoText[5].setString(std::to_string(s.gameArea.object.get(x,y)->upgradeable2->foodPerSecond));
            infoText[6].setString(std::to_string(s.gameArea.object.get(x,y)->upgradeable2->peoplePerSecond));
            //infoText[7].setString(s.gameArea.object.get(x,y)->upgradeable1->exp);

            render.window.draw(info);

            for(int i=0;i!=10;i++)
                render.window.draw(infoText[i]);
        }
    }
}

void Selector::onEvent()
{
    GameScene& s = *dynamic_cast <GameScene*>(scene.actual());
    if(logic.event.type == sf::Event::MouseButtonPressed && logic.event.mouseButton.button == sf::Mouse::Left)
    {
        if(drawing == false)
        {
            if(s.gameArea.object.get(x,y)->isClicked)
            {
                drawing = true;
                if(s.gameArea.object.get(x,y)->upgradeable1 != nullptr)
                {
                    drawToBuild =1; /// TO DO
                    toBuild[0].setTexture(
                    *asset.texture.load( s.gameArea.object.get(x,y)->upgradeable1->texture));
                }
                if(s.gameArea.object.get(x,y)->upgradeable2 != nullptr)
                {
                    drawToBuild =2; /// TO DO
                    toBuild[1].setTexture(
                    *asset.texture.load( s.gameArea.object.get(x,y)->upgradeable2->texture));
                }

                if(x > 6)
                {
                    info.setPosition(sf::Vector2f(0,900-300));
                    infoText[9].setPosition(info.getPosition()+sf::Vector2f(10,10));
                    infoText[8].setPosition(info.getPosition()+sf::Vector2f(10,50));

                    infoText[0].setPosition(info.getPosition()+sf::Vector2f(80,100));
                    infoText[1].setPosition(info.getPosition()+sf::Vector2f(80,150));
                    infoText[2].setPosition(info.getPosition()+sf::Vector2f(80,200));

                    infoText[4].setPosition(info.getPosition()+sf::Vector2f(330,100));
                    infoText[5].setPosition(info.getPosition()+sf::Vector2f(330,150));
                    infoText[6].setPosition(info.getPosition()+sf::Vector2f(330,200));
                }
                else
                {
                    info.setPosition(sf::Vector2f(1600-500,900-300));
                    infoText[9].setPosition(info.getPosition()+sf::Vector2f(10,10));
                    infoText[8].setPosition(info.getPosition()+sf::Vector2f(10,50));

                    infoText[0].setPosition(info.getPosition()+sf::Vector2f(80,100));
                    infoText[1].setPosition(info.getPosition()+sf::Vector2f(80,150));
                    infoText[2].setPosition(info.getPosition()+sf::Vector2f(80,200));

                    infoText[4].setPosition(info.getPosition()+sf::Vector2f(330,100));
                    infoText[5].setPosition(info.getPosition()+sf::Vector2f(330,150));
                    infoText[6].setPosition(info.getPosition()+sf::Vector2f(330,200));
                }
                //drawToBuild = 1;
            }
        }
        else
        {
            sf::Vector2f m = render.window.mapPixelToCoords((sf::Vector2i)sf::Mouse::getPosition(render.window));
            if(drawToBuild > 0 && toBuild[0].getGlobalBounds().contains(m))
            {
                if(s.people + s.gameArea.object.get(x,y)->upgradeable1->people  >= 0 &&
                    s.resource + s.gameArea.object.get(x,y)->upgradeable1->resource >= 0 &&
                    s.food + s.gameArea.object.get(x,y)->upgradeable1->food  >= 0 &&
                    s.exp + s.gameArea.object.get(x,y)->upgradeable1->exp>= 0 )
                {
                    s.people += s.gameArea.object.get(x,y)->upgradeable1->people;
                    s.food += s.gameArea.object.get(x,y)->upgradeable1->food;
                    s.exp += s.gameArea.object.get(x,y)->upgradeable1->exp;
                    s.resource += s.gameArea.object.get(x,y)->upgradeable1->resource;

                    s.gameArea.object.get(x,y)->noDelete = 1;
                    s.gameArea.object.change(x,y, s.gameArea.object.get(x,y)->upgradeable1 );
                }
            }

            if(drawToBuild > 1 && toBuild[1].getGlobalBounds().contains(m))
            {
                if(s.people + s.gameArea.object.get(x,y)->upgradeable2->people  >= 0 &&
                    s.resource + s.gameArea.object.get(x,y)->upgradeable2->resource >= 0 &&
                    s.food + s.gameArea.object.get(x,y)->upgradeable2->food  >= 0 &&
                    s.exp + s.gameArea.object.get(x,y)->upgradeable2->exp>= 0 )
                {
                    s.people += s.gameArea.object.get(x,y)->upgradeable2->people;
                    s.food += s.gameArea.object.get(x,y)->upgradeable2->food;
                    s.exp += s.gameArea.object.get(x,y)->upgradeable2->exp;
                    s.resource += s.gameArea.object.get(x,y)->upgradeable2->resource;

                    s.gameArea.object.get(x,y)->noDelete = 2;
                    s.gameArea.object.change(x,y, s.gameArea.object.get(x,y)->upgradeable2 );
                }
            }



            drawing = false;
            drawToBuild = 0;
        }
    }
}

void Selector::onUpdate()
{

    /*if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && s.gameArea.object.get(x,y) != nullptr)
    {
        if(s.gameArea.object.get(x,y)->isClicked)
        {
            s.gameArea.object.change(x,y,new Archers(sf::Vector2i(x,y)));

        }
    }*/

    GameScene& s = *dynamic_cast <GameScene*>(scene.actual());

        sf::Vector2f m = render.window.mapPixelToCoords((sf::Vector2i)sf::Mouse::getPosition(render.window));
        if(!drawing && m.x < 100*MapX && m.y < 100*MapY && m.x > 0 && m.y > 0)
        {
            x = int(m.x / 100);
            y = int(m.y / 100);
            m = sf::Vector2f ( x*100, y*100 );
            mouse.setPosition(m);
        }

    toBuild[0].setPosition(mouse.getPosition()+sf::Vector2f(-18,-20));
    toBuild[1].setPosition(mouse.getPosition()+sf::Vector2f(68,-20));
}
