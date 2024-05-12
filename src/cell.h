#ifndef CELL_H
#define CELL_H

#include <SFML/Graphics.hpp>
#include "constants.h"

class Cell
{
private:
    sf::Sprite sprite;
    int type;
    sf::IntRect getRectFromCellType();
public:
    bool mine=false;
    Cell(sf::Texture& texture,sf::Vector2f position,int type);
    void Draw(sf::RenderWindow& window);
    int discover();
};
#endif