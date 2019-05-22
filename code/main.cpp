#define DEBUG

#include "engine/gameLoop.hpp"
#include "blankScene.hpp"
#include "engine/assetManager.hpp"
#include "game/gameScene.hpp"

#include <iostream>

sf::CircleShape shape(100);

void onDraw()
{
    RenderManager::get().window.setView(RenderManager::get().window.getDefaultView());
    sf::Text text;
    text.setColor(sf::Color::Blue);
    text.setFont(AssetManager::get().font);
    text.setString(std::to_string(1.f / LogicManager::get().deltaTime));
    text.setCharacterSize(10);
    RenderManager::get().window.draw(text);
}

int main()
{
    Gameloop game;

    RenderManager::get().window.create(sf::VideoMode(1280,720),"Orcs Attack");
    SceneManager::get().set(new GameScene());

    game.onDraw = &onDraw;

    //std::map<int,std::map<int,std::int>> lvl;

    game.run();
    return 0;
}
