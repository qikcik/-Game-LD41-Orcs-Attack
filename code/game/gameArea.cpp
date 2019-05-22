#include "gameArea.hpp"
#include <fstream>

GameArea::GameArea()
{
    view.reset(sf::FloatRect(-25, -25, 1650, 950));
    view.setViewport(sf::FloatRect(0.04f,0.075f,0.92,0.92f));
}

void GameArea::onStart()
{
    loadFromFile("1");
    object.initialize();
    enemy.initialize();
}

GameArea::~GameArea()
{

}

void GameArea::onEvent()
{
    render.window.setView(view);
    selector.onEvent();
}

void GameArea::onUpdate()
{
    render.window.setView(view);
    enemy.onUpdate();
    object.onUpdate();
    selector.onUpdate();
}

void GameArea::onDraw()
{
    render.window.setView(view);
    object.onDraw();
    enemy.onDraw();
    selector.onDraw();
}

void GameArea::loadFromFile(std::string patch)
{
    std::fstream file;
    file.open( "data/"+patch+".lvl", std::ios::in );
    if( file.good() == true )
    {
        for(int y=0 ; y != MapY ; y++)
        {
            std::string line;
            getline( file, line );
            for(int x=0; x!=MapX ; x++)
            {
                tileMap[x][y] = line[x];
                if (tileMap[x][y] == 'S')
                    {
                        tileStartX = x;
                        tileStartY = y;
                    }
            }
        }
        file.close();
    }
    else render.window.close();
}
