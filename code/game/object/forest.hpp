#pragma once

#include "../objectManager.hpp"

class Forest :public Object
{
    public:
        Forest(sf::Vector2i pos);
        ~Forest();

        void onDraw();
        void onUpdate();
        void onDrawBullet() {}
};
