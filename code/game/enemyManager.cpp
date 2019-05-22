#include "enemyManager.hpp"
#include "gameScene.hpp"
#include <iostream>

EnemyManager::EnemyManager()
{

}
EnemyManager::~EnemyManager()
{
    for (auto it : enemy)
        delete it;
}

void EnemyManager::initialize()
{
    GameScene& s = *dynamic_cast <GameScene*>(scene.actual());
    int x = s.gameArea.tileStartX;
    int y = s.gameArea.tileStartY;

    for(;;)
    {
        if(s.gameArea.tileMap[x][y] > '0' && s.gameArea.tileMap[x][y] < ':') s.gameArea.tileMap[x][y] = 'X';

        if( x > 0 && s.gameArea.tileMap[x-1][y] > '0' && s.gameArea.tileMap[x-1][y] < ':' )
            x-=  1;
        else if( x < MapX-1 && s.gameArea.tileMap[x+1][y] > '0' && s.gameArea.tileMap[x+1][y] < ':')
            x += 1;
        else if( y > 0 && s.gameArea.tileMap[x][y-1] > '0' && s.gameArea.tileMap[x][y-1] < ':')
            y -= 1;
        else if( y < MapY-1 && s.gameArea.tileMap[x][y+1] > '0' && s.gameArea.tileMap[x][y+1] < ':')
            y += 1;
        else break;


        moves.push_back(sf::Vector2i(x,y));

    }
}

void EnemyManager::onEvent()
{

}
void EnemyManager::onUpdate()
{
    GameScene& s = *dynamic_cast <GameScene*>(scene.actual());
    time += logic.deltaTime;

    if(time > 1.f)
    {
        time -= 1.f;
        hp += 1;
        respawn(new Orc(hp));
    }

    for (std::vector <Enemy*>::iterator it=enemy.begin(); it!=enemy.end(); /*it++*/)
    {
        (*it)->onUpdate();
        //std::cout << (*it)->hp  << " : "<< (*it)->realhp << std::endl;
        if((*it)->hp <= 0)
        {
            s.exp += (*it)->exp;
            delete (*it);
            it = enemy.erase(it);
        }
        else ++it;
    }
}
void EnemyManager::onDraw()
{
    for (auto it : enemy)
        it->onDraw();

    for (auto it : enemy)
        it->onDrawBullet();

}
void EnemyManager::respawn(Enemy* New)
{
    GameScene& s = *dynamic_cast <GameScene*>(scene.actual());
    enemy.push_back(New);
}

