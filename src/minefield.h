#ifndef MINEFIELD_H
#define MINEFIELD_H

#include <SFML/Graphics.hpp>
#include "cell.h"
#include "constants.h"

class Minefield
{
private:
    std::vector<Cell> cells;
    sf::Texture texture;
public:
    Minefield(sf::Vector2f position=sf::Vector2f(0.0f,0.0f));
    void Draw(sf::RenderWindow& window);
    int discover(sf::Vector2f position);
    int flag(sf::Vector2f position);
};
#endif