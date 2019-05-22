#pragma once

#include "enemy.hpp"

class Orc :public Enemy
{
    public:
        Orc(int h);
        ~Orc();

        void onDraw();
        void onUpdate();

        sf::Vector2f getRealCenter();
};
