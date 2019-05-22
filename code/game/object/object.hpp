#pragma once

#include "../../engine/renderManager.hpp"
#include "../../engine/assetManager.hpp"
#include "../../engine/assetManager.hpp"

class Object :public AssetController , public Renderable
{
    public:
        //Object() = default;
        ~Object() {
            if( noDelete != 1)
                delete upgradeable1;
            if( noDelete != 2)
                delete upgradeable2;
        };

        virtual void onDraw() = 0;
        virtual void onUpdate() = 0;

        //virtual void setPosition(sf::Vector2f pos) =0;
        //virtual sf::Vector2f getPosition() =0;

        bool isClicked = false;


        Object* upgradeable1 = nullptr;
        Object* upgradeable2 = nullptr;
        int noDelete =0;

        std::string name = "not define";
        std::string descrption = "not define";
        std::string texture = "object/nothing";
        int people = 0;
        int peoplePerSecond = 0;

        int resource =0;
        int resourcePerSecond =0;

        int food = 0;
        int foodPerSecond =0;

        int exp=0;


        void configure(std::string texture , sf::Vector2i pos);
        void updatePerSecond();

        sf::RectangleShape body;
};
