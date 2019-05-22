#pragma once

#include "../engine/scene.hpp"
#include "../engine/renderManager.hpp"
#include "../engine/assetManager.hpp"

#include "enemy/orc.hpp"
#include "gameArea.hpp"
#include "gui.hpp"

class GameScene : public Scene , public Renderable , public AssetController
{
    public:
        GameScene();
        virtual ~GameScene();

        void onStart();
        void onStop();

        void onEvent();
        void onUpdate();
        void onDraw();

        float exp=0;
        float resource=0;
        float people=2;
        float food=0;

        Gui gui;
        GameArea gameArea;

        sf::Sprite background;
        sf::View backgroundView;
};
