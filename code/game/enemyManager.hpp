#pragma once


#include "../engine/renderManager.hpp"
#include "../engine/assetManager.hpp"
#include "../engine/sceneManager.hpp"
#include "../engine/logicManager.hpp"
#include "enemy/enemy.hpp"

#define MapX 16
#define MapY 9

class EnemyManager : public Renderable , public AssetController , public SceneController , public Logicable
{
    public:
        EnemyManager();
        virtual ~EnemyManager();

        void initialize();

        void onEvent();
        void onUpdate();
        void onDraw();

        void respawn(Enemy* New);

        float time = -10.f;
        int hp = 1;


        std::vector<sf::Vector2i> moves;
        std::vector <Enemy*> enemy;
};
