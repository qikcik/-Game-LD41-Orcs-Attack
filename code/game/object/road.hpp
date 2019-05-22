#pragma once

#include "../objectManager.hpp"

class Road :public Object
{
    public:
        Road(sf::Vector2i pos ,int type);
        ~Road();

        void onDraw();
        void onUpdate();
        void onDrawBullet() {}
};
