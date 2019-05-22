#pragma once

#include "../objectManager.hpp"

class WheatField :public Object
{
    public:
        WheatField(sf::Vector2i pos);
        ~WheatField();

        void onDraw();
        void onUpdate();
        void onDrawBullet() {}
};
