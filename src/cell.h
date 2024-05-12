#ifndef CELL_H
#define CELL_H

#include <SFML/Graphics.hpp>
#include "constants.h"

class Cell
{
private:
    sf::Sprite sprite;
    sf::IntRect getRectFromCellType(int celltype);
public:
    bool mine=false;
    bool flagged=false;
    bool discovered=false;
    Cell(sf::Texture& texture,sf::Vector2f position,int type);
    void Draw(sf::RenderWindow& window);
    void ChangeTextureRect(int img);
    int discover();
    int highlight();
    int unhighlight();
    int flag();
    int reset(sf::Vector2f position, int celltype);
    int type;
    int adjacent_mines=0;
};
#endif