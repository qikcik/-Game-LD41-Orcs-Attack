#pragma once

#include <SFML/Window/Event.hpp>

#define MapX 16
#define MapY 9

class LogicManager
{
    /// CLASS
    public:
        double deltaTime;
        sf::Event event;

    /// SINGLETON
        private:
            //Logic();
        public:
            //~Logic();
            static LogicManager& get() { static LogicManager d; return d;}
};

class Logicable
{
    public:
        LogicManager &logic = LogicManager::get();
};
