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
    int discover(int x, int y);
    int flag(int x, int y);
};
#endif