#pragma once

#include "../engine/scene.hpp"
#include "../engine/renderManager.hpp"
#include "../engine/assetManager.hpp"

#include "enemyManager.hpp"
#include "objectManager.hpp"
#include "selector.hpp"


#include "enemy/orc.hpp"



class GameArea : public Renderable , public AssetController
{
    public:
        GameArea();
        virtual ~GameArea();

        void onStart();
        void onStop();

        void onEvent();
        void onUpdate();
        void onDraw();

        std::array<std::array<char,MapY>,MapX> tileMap;
        int tileStartX,tileStartY;

        sf::View view;

        bool spawn = true; //todelete

        ObjectManager object;
        EnemyManager enemy;
        Selector selector;

    private:
        void loadFromFile(std::string patch);
};
