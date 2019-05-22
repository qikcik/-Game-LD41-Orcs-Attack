#pragma once

#include "../objectManager.hpp"

class Nothing :public Object
{
    public:
        Nothing(sf::Vector2i pos);
        ~Nothing();

        void onDraw();
        void onUpdate();
        void onDrawBullet() {}
};
