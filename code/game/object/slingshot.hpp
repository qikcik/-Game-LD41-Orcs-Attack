#pragma once

#include "../objectManager.hpp"
#include "../../engine/sceneManager.hpp"
#include "../../engine/logicManager.hpp"

#include <math.h>

#include <SFML/Graphics.hpp>
#include "../enemy/enemy.hpp"
#include "bullet.hpp"



class Slingshot :public Object , public SceneController , public Logicable
{
    public:
        Slingshot(sf::Vector2i pos);
        ~Slingshot();

        int range = 120;
        float cooldown = 0.2;
        int damage =2;
        float time =0;
        int speed = 300;

        void onDraw();
        void onUpdate();
};
