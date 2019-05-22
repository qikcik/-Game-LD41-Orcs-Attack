#pragma once

#include "../engine/scene.hpp"
#include "../engine/renderManager.hpp"
#include "../engine/assetManager.hpp"
#include "../engine/sceneManager.hpp"
#include "../engine/logicManager.hpp"


class Gui : public Renderable , public AssetController , public Logicable , public SceneController
{
    public:
        Gui() = default;
        ~Gui() =default;

        void onStart();
        void onStop();

        void onEvent();
        void onUpdate();
        void onDraw();

        struct {
            sf::RectangleShape background;
            sf::RectangleShape icon;
            sf::Text text;
        } ResourceApplet[4];

        sf::View view;
};
