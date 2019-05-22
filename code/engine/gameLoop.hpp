#pragma once

#include "renderManager.hpp"
#include "logicManager.hpp"
#include "sceneManager.hpp"


class Gameloop
    : public virtual Renderable ,
      public virtual Logicable ,
      public virtual SceneController
{
    public:
        Gameloop();
        ~Gameloop();
        void run();

        void (*onDraw)();

    private:
        sf::Clock clock;

};
