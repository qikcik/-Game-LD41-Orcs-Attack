#include "object.hpp"
#include "../../engine/sceneManager.hpp"
#include "../gameScene.hpp"
#include "../../engine/logicManager.hpp"

void Object::configure(std::string texture , sf::Vector2i pos)
{
    this->texture=texture;
    body.setSize(sf::Vector2f(100,100));
    body.setTexture(asset.texture.load(texture));
    body.setPosition(sf::Vector2f(pos.x * 100,pos.y *100));
}

void Object::updatePerSecond()
{
    GameScene& s = *dynamic_cast <GameScene*>(SceneManager::get().actual());

    s.people += peoplePerSecond *LogicManager::get().deltaTime;
    s.food += foodPerSecond *LogicManager::get().deltaTime;
    s.resource += resourcePerSecond  *LogicManager::get().deltaTime;
}
