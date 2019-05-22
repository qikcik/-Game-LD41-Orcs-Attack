#include "objectManager.hpp"
#include "gameScene.hpp"

ObjectManager::ObjectManager()
{

}
ObjectManager::~ObjectManager()
{
    for (int i=0;i!=MapX;i++)
        for(int j=0;j!=MapY;j++)
            delete objects[i][j];
}

void ObjectManager::initialize()
{
    GameScene& s = *dynamic_cast <GameScene*>(scene.actual());

    for(int y=0 ; y != MapY ; y++)
    {
        for(int x=0; x!=MapX ; x++)
        {

            if (s.gameArea.tileMap[x][y] == '1') objects[x][y] = new Road(sf::Vector2i(x,y) , 1);
            else if (s.gameArea.tileMap[x][y] == '2') objects[x][y] = new Road(sf::Vector2i(x,y) , 2);
            else if (s.gameArea.tileMap[x][y] == '3') objects[x][y] = new Road(sf::Vector2i(x,y) , 3);
            else if (s.gameArea.tileMap[x][y] == '4') objects[x][y] = new Road(sf::Vector2i(x,y) , 4);
            else if (s.gameArea.tileMap[x][y] == '6') objects[x][y] = new Road(sf::Vector2i(x,y) , 6);
            else if (s.gameArea.tileMap[x][y] == '7') objects[x][y] = new Road(sf::Vector2i(x,y) , 7);
            else if (s.gameArea.tileMap[x][y] == '8') objects[x][y] = new Road(sf::Vector2i(x,y) , 8);
            else if (s.gameArea.tileMap[x][y] == '9') objects[x][y] = new Road(sf::Vector2i(x,y) , 9);
            else if (s.gameArea.tileMap[x][y] == '&') objects[x][y] = new Forest(sf::Vector2i(x,y));
            else if (s.gameArea.tileMap[x][y] == '^') objects[x][y] = new Field(sf::Vector2i(x,y));
            else if (s.gameArea.tileMap[x][y] == 'S') objects[x][y] = new Start(sf::Vector2i(x,y));
            else if (s.gameArea.tileMap[x][y] == 'E') objects[x][y] = new Castle(sf::Vector2i(x,y));
            else objects[x][y] = new Nothing(sf::Vector2i(x,y));
            /*if (arr[x][y] == 'S')
            if (arr[x][y] == 'E')
            */
        }
    }
}

void ObjectManager::onEvent()
{

}
void ObjectManager::onUpdate()
{
    for (int i=0;i!=MapX;i++)
        for(int j=0;j!=MapY;j++)
            objects[i][j]->onUpdate();
}
void ObjectManager::onDraw()
{
    for (int i=0;i!=MapX;i++)
        for(int j=0;j!=MapY;j++)
            objects[i][j]->onDraw();
}

Object* ObjectManager::get(int x ,int y)
{
    if( x >= 0 && x < MapX && y >= 0 && y < MapY )
        return objects[x][y];
    return nullptr;
}
Object*  ObjectManager::change(int x, int y , Object* New)
{
    if( x >= 0 && x < MapX && y >= 0 && y < MapY )
    {
        delete objects[x][y];
        objects[x][y] = New;
    }
}
