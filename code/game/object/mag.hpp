#pragma once

#include "../objectManager.hpp"
#include "../../engine/sceneManager.hpp"
#include "../../engine/logicManager.hpp"

#include <math.h>

#include <SFML/Graphics.hpp>
#include "../enemy/enemy.hpp"
#include "bullet.hpp"



class Mag :public Object , public SceneController , public Logicable
{
    public:
        Mag(sf::Vector2i pos);
        ~Mag();

        int range = 250;
        float cooldown = 1;
        int damage =30;
        float time =0;
        int speed = 350;

        void onDraw();
        void onUpdate();
};
