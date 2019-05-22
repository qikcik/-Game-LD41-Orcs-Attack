#pragma once

#include <vector>


#include "../../engine/renderManager.hpp"
#include "../../engine/assetManager.hpp"
#include "../../engine/logicManager.hpp"
#include "../../engine/sceneManager.hpp"

#include "../enemy/enemy.hpp"

class Bullet :public AssetController , public Renderable , public Logicable, public SceneController
{
    public:
        Bullet(int s, int d, Enemy *t, sf::Vector2f pos,sf::Texture &tex);
        ~Bullet();

        void onDraw();
        void onUpdate();

        int speed = 0;
        int damage = 0;
        Enemy* target = nullptr;
        sf::Sprite sprite;
        bool blocked = false;

        bool toDelete = false;
};

