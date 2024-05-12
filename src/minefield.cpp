#include "minefield.h"

Minefield::Minefield(sf::Vector2f position)
{
    if (!texture.loadFromFile("../../images/minesweeper.png"))
    {
        // error
    }
    for (int i = 0; i < CELLS_X; i++)
    {
        for (int j = 0; j < CELLS_Y; j++)
        {
            cells.push_back(Cell(texture,sf::Vector2f(i*CELL_SIZE,j*CELL_SIZE),HIDDEN));
        }
    }
}

void Minefield::Draw(sf::RenderWindow& window){
    for (Cell cell:cells){
        cell.Draw(window);
    }
}