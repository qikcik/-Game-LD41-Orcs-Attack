#pragma once

#include "../objectManager.hpp"

class Field :public Object
{
    public:
        Field(sf::Vector2i pos);
        ~Field();

        void onDraw();
        void onUpdate();
        void onDrawBullet() {}
};
