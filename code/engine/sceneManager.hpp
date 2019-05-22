#pragma once

class Scene;

class SceneManager
{
    /// CLASS
    public:
        Scene* actual();
        void set( Scene* New);

    private:
        Scene* scene = nullptr;

     /// SINGLETON
        private:
            SceneManager();
        public:
            ~SceneManager();
            static SceneManager& get() { static SceneManager d; return d;}
};

class SceneController
{
    public:
        SceneManager &scene = SceneManager::get();
};

#include "scene.hpp"
