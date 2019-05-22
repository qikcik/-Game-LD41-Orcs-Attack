#include "gameScene.hpp"
#include "fstream"
#include "iostream"

GameScene::GameScene()
{
    //background.setSize(sf::Vector2f(render.window.getSize().x,render.window.getSize().y));
    //backgroundView.reset(sf::FloatRect(-25, -25, 1650, 950));
    //backgroundView.setViewport(sf::FloatRect(0.04f,0.075f,0.92,0.92f));

    //asset.texture.load("objects/background")->setRepeated(true);
    //background.setTexture(*asset.texture.load("objects/background"));
    //background.setTextureRect(sf::IntRect(0,0,2000,2000));

}

GameScene::~GameScene()
{

}

void GameScene::onStart()
{
    gameArea.onStart();
    gui.onStart();
}

void GameScene::onStop()
{
    //gameArea.onStop();
    //gui.onStop();
}

void GameScene::onEvent()
{
    gameArea.onEvent();
    gui.onEvent();
}

void GameScene::onUpdate()
{
    gameArea.onUpdate();
    gui.onUpdate();
}

void GameScene::onDraw()
{
    //render.window.setView(backgroundView);
    //render.window.draw(background);
    gameArea.onDraw();
    gui.onDraw();
}
