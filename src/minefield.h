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
    int highlight_x=-1,highlight_y=-1;
public:
    Minefield(sf::Vector2f position=sf::Vector2f(0.0f,0.0f));
    void Draw(sf::RenderWindow& window);
    int highlight(int x, int y);
    int discover(int x, int y);
    int flag(int x, int y);
};
#endif