#include "blankScene.hpp"
#include "engine/sceneManager.hpp"
#include "game/gameScene.hpp"

BlankScene::BlankScene()
{
    sprite.setTexture(*asset.texture.load("logoSfml"));
}

BlankScene::~BlankScene()
{

}

void BlankScene::onStart()
{

}

void BlankScene::onStop()
{
}

void BlankScene::onEvent()
{

}

void BlankScene::onUpdate()
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        SceneManager::get().set(new GameScene());
    }
}

void BlankScene::onDraw()
{
    render.window.draw(sprite);
}
