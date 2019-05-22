#pragma once

#include "../engine/logicManager.hpp"
#include "../engine/renderManager.hpp"
#include "../engine/assetManager.hpp"
#include "../engine/sceneManager.hpp"
#include "object/slingshot.hpp"


class Selector : public Renderable , public AssetController , public Logicable , public SceneController
{
    public:
        Selector();
        ~Selector ();

        void onDraw();
        void onUpdate();
        void onEvent();

        sf::RectangleShape mouse;
        sf::Sprite info;
        int tileSize;

        sf::Text infoText[10];

        bool drawing = false;

        int x ,y;

        int drawToBuild =0;
        sf::Sprite toBuild[2];
};
