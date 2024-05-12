#include <SFML/Graphics.hpp>
#include <iostream>
#include "minefield.h"
#include "constants.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Minesweeper!");
    window.setVerticalSyncEnabled(true);
    sf::Clock clock;
    Minefield minefield;
    while (window.isOpen())
    {
        sf::Time elapsed = clock.getElapsedTime();
        // std::cout << elapsed.asSeconds() << std::endl;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    int x = event.mouseButton.x / CELL_SIZE;
                    int y = event.mouseButton.y / CELL_SIZE;
                    minefield.discover(x, y);
                }
                else if (event.mouseButton.button == sf::Mouse::Right)
                {
                    int x = event.mouseButton.x / CELL_SIZE;
                    int y = event.mouseButton.y / CELL_SIZE;
                    std::cout << x << " " << y << std::endl;
                    minefield.flag(x, y);
                }
            }
        }
        window.clear(sf::Color::White);
        minefield.Draw(window);
        window.display();
    }

    return 0;
}