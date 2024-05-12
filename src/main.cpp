#include <SFML/Graphics.hpp>
#include <iostream>
#include "minefield.h"
#include "constants.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT), "SFML Minesweeper!");
    window.setVerticalSyncEnabled(true);
    sf::Clock clock;
    Minefield minefield;
    while (window.isOpen())
    {
        sf::Time elapsed = clock.getElapsedTime();
        std::cout << elapsed.asSeconds() << std::endl;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::White);
        minefield.Draw(window);
        window.display();
    }

    return 0;
}