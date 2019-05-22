#pragma once

#include <SFML/Graphics.hpp>

class RenderManager
{
    /// CLASS
    public:
         sf::RenderWindow window;
    /// SINGLETON
        private:
            //RenderManager();
        public:
            //~RenderManager();
            static RenderManager& get() { static RenderManager d; return d;}
};

class Renderable
{
    public:
        RenderManager &render = RenderManager::get();
};
