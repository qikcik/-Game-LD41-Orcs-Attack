#include "gameLoop.hpp"
#include <iostream>

Gameloop::Gameloop()
{
    //BLANK
}

Gameloop::~Gameloop()
{
    //BLANK
}

void Gameloop::run()
{
    double last = 0;

    while( render.window.isOpen() )
    {
        logic.deltaTime = clock.restart().asSeconds();
        last = (logic.deltaTime + last) / 2;

        //std::cout <<  1.f / last << " \n";


        while (render.window.pollEvent(logic.event))
        {
            if (logic.event.type == sf::Event::Closed)
                render.window.close();
            scene.actual()->onEvent();
        }

        scene.actual()->onUpdate();

        render.window.clear(sf::Color(136, 160, 38));
            scene.actual()->onDraw();
            onDraw();
        render.window.display();
    }
}
