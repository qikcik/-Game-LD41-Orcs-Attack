#include "gui.hpp"
#include <fstream>
#include "gameScene.hpp"


void Gui::onStart()
{
    view.reset(sf::FloatRect(0, 0, 1650, 50));
    view.setViewport(sf::FloatRect(0.01f,0.01f,1.f, 0.050));
    //enemy.initialize();
    for(int i =0;i!=4;i++)
    {
        ResourceApplet[i].background.setSize(sf::Vector2f(200,50));
        ResourceApplet[i].background.setTexture(asset.texture.load("gui"));
        ResourceApplet[i].background.setTextureRect(sf::IntRect(0,0,200,50));
        ResourceApplet[i].background.setPosition(sf::Vector2f(250*i,0));

        ResourceApplet[i].icon.setSize(sf::Vector2f(50,50));
        ResourceApplet[i].icon.setTexture(asset.texture.load("gui"));
        ResourceApplet[i].icon.setTextureRect(sf::IntRect(50*i,50,50,50));
        ResourceApplet[i].icon.setPosition(sf::Vector2f(250*i,0));

        ResourceApplet[i].text.setPosition(sf::Vector2f(250*i+50,5));
        ResourceApplet[i].text.setFont(asset.font);
        ResourceApplet[i].text.setString(std::to_string(i*100));
        ResourceApplet[i].text.setCharacterSize(30);
        ResourceApplet[i].text.setColor(sf::Color::Black);



    }
}


void Gui::onEvent()
{
    render.window.setView(view);
}

void Gui::onUpdate()
{
    render.window.setView(view);
    GameScene& s = *dynamic_cast <GameScene*>(scene.actual());
    ResourceApplet[0].text.setString(std::to_string((int)s.resource));
    ResourceApplet[1].text.setString(std::to_string((int)s.food));
    ResourceApplet[2].text.setString(std::to_string((int)s.people));
    ResourceApplet[3].text.setString(std::to_string((int)s.exp));

}

void Gui::onDraw()
{
    render.window.setView(view);
    for(int i =0;i!=4;i++)
    {
        render.window.draw(ResourceApplet[i].background);
        render.window.draw(ResourceApplet[i].icon);
        render.window.draw(ResourceApplet[i].text);
    }
}
