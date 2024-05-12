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
            cells.push_back(Cell(texture, sf::Vector2f(i * CELL_SIZE, j * CELL_SIZE), HIDDEN));
        }
    }
    srand(time(NULL));
    int count = 0;
    while (count < MINES)
    {
        int x = rand() % CELLS_X;
        int y = rand() % CELLS_Y;
        if (!cells[y * CELLS_X + x].mine)
        {
            cells[y * CELLS_X + x].mine = true;
            cells[y * CELLS_X + x].ChangeTextureRect(MINE);
            cells[y * CELLS_X + x].adjacent_mines = 0;
            count++;

            for (int dy = -1; dy <= 1; dy++)
            {
                for (int dx = -1; dx <= 1; dx++)
                {
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx >= 0 && nx < CELLS_X && ny >= 0 && ny < CELLS_Y && cells[y * CELLS_X + x].mine != true)
                    {
                        cells[ny * CELLS_X + nx].adjacent_mines++;
                    }
                }
            }
        }
    }
}

void Minefield::Draw(sf::RenderWindow &window)
{
    for (Cell cell : cells)
    {
        cell.Draw(window);
    }
}