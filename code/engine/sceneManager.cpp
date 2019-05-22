#include "sceneManager.hpp"

SceneManager::SceneManager()
{
    scene = nullptr;
}

SceneManager::~SceneManager()
{
    if(scene != nullptr)
        delete scene;
}

Scene* SceneManager::actual()
{
    return scene;
}

void SceneManager::set( Scene* New)
{
    if(scene != nullptr)
    {
        scene->onStop();
        delete scene;
    }
    scene = New;
    scene->onStart();

}
