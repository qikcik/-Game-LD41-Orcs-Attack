#pragma once

#include "../objectManager.hpp"

class Castle :public Object
{
    public:
        Castle(sf::Vector2i pos);
        ~Castle();

        void onDraw();
        void onUpdate();
        void onDrawBullet() {}
};
