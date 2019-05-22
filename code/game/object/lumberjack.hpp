#pragma once

#include "../objectManager.hpp"

class LumberJack :public Object
{
    public:
        LumberJack(sf::Vector2i pos);
        ~LumberJack();

        void onDraw();
        void onUpdate();
        void onDrawBullet() {}
};
