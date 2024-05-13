#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "minefield.h"
#include "constants.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Minesweeper!");
    window.setVerticalSyncEnabled(true);
    sf::Clock clock;
    Minefield minefield;

    sf::Music music;
    if (!music.openFromFile("../../audio/alex-productions-cyberpunk-computer-game-idra.mp3"))
        return EXIT_FAILURE;

    // Play the music
    music.play();

    while (window.isOpen())
    {
        sf::Time elapsed = clock.getElapsedTime();
        std::cout << elapsed.asSeconds() << std::endl;
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
                    minefield.flag(x, y);
                }
            }
        }
        sf::Vector2i localPosition = sf::Mouse::getPosition(window);
        // std::cout<<localPosition.x<<" "<<localPosition.y<<std::endl;
        minefield.highlight(localPosition.x / CELL_SIZE, localPosition.y / CELL_SIZE);

        window.clear(sf::Color::White);
        minefield.Draw(window);
        window.display();
    }

    return 0;
}