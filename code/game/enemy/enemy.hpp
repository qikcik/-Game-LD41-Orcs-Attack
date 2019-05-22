#pragma once

#include "../../engine/renderManager.hpp"
#include "../../engine/assetManager.hpp"
#include "../../engine/logicManager.hpp"
#include "../../engine/sceneManager.hpp"
//#include "../object/bullet.hpp"

class Bullet;

class Enemy :public AssetController , public Renderable , public Logicable, public SceneController
{
    public:
        Enemy();
        ~Enemy();

        virtual void onDraw() =0;
        virtual void onUpdate() =0;
        void onDrawBullet();

        void shoot(Bullet *New);

        virtual sf::Vector2f getRealCenter()=0;
        void configureMove() ;
        sf::Vector2f move();

        int m =0;
        float speed = 200;
        int hp =0;
        int exp = 20;
        int realhp =0;
        bool blocked = false;

        //int initHp;

        sf::RectangleShape live;
        sf::RectangleShape live2;
        sf::RectangleShape body;

        std::vector<Bullet*> bullets;
};

#include "../object/bullet.hpp"
