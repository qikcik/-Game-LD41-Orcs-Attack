#pragma once

#include "../objectManager.hpp"

class House :public Object
{
    public:
        House(sf::Vector2i pos);
        ~House();

        void onDraw();
        void onUpdate();
        void onDrawBullet() {}
};
