#pragma once

#include "engine/scene.hpp"
#include "engine/renderManager.hpp"
#include "engine/assetManager.hpp"

class BlankScene : public Scene , public Renderable , public AssetController
{
    public:
        BlankScene();
        virtual ~BlankScene();

        void onStart();
        void onStop();

        void onEvent();
        void onUpdate();
        void onDraw();


        sf::Sprite sprite;
};
