#pragma once

#include "../engine/scene.hpp"
#include "../engine/renderManager.hpp"
#include "../engine/assetManager.hpp"
#include "../engine/sceneManager.hpp"
#include "../engine/logicManager.hpp"

#include "object/object.hpp"
#include "object/nothing.hpp"
#include "object/road.hpp"
#include "object/forest.hpp"
#include "object/field.hpp"
#include "object/castle.hpp"
#include "object/start.hpp"


class ObjectManager : public Renderable , public AssetController , public SceneController , public Logicable
{
    public:
        ObjectManager();
        virtual ~ObjectManager();

        void initialize();

        void onEvent();
        void onUpdate();
        void onDraw();

        Object* get(int x ,int y);
        Object* change(int x, int y , Object* New);

        Object *objects[MapX][MapY];
};
