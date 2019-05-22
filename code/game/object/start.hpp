#pragma once

#include "../objectManager.hpp"

class Start :public Object
{
    public:
        Start(sf::Vector2i pos);
        ~Start();

        void onDraw();
        void onUpdate();
        void onDrawBullet() {}
};
