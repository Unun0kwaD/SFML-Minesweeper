#include "minefield.h"
#include <iostream>
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
        if (!cells[x * CELLS_Y + y].mine)
        {
            cells[x * CELLS_Y + y].mine = true;

            // display all mines
            // cells[x * CELLS_Y + y].ChangeTextureRect(MINE);
            cells[x * CELLS_Y + y].adjacent_mines = 0;
            count++;

            for (int dy = -1; dy <= 1; dy++)
            {
                for (int dx = -1; dx <= 1; dx++)
                {
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx >= 0 && nx < CELLS_X && ny >= 0 && ny < CELLS_Y && cells[nx * CELLS_Y + ny].mine != true)
                    {
                        cells[nx * CELLS_Y + ny].adjacent_mines++;

                        // display all numbers
                        //  cells[nx * CELLS_Y + ny].ChangeTextureRect(++cells[nx * CELLS_Y + ny].adjacent_mines-1);
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

int Minefield::discover(int x, int y)
{
    if (!cells[x * CELLS_Y + y].discovered && !cells[x * CELLS_Y + y].flagged)
    {
        int result = cells[x * CELLS_Y + y].discover();
        if (result == 0)
        {
            for (int dy = -1; dy <= 1; dy++)
            {
                for (int dx = -1; dx <= 1; dx++)
                {
                    int nx = x + dx;
                    int ny = y + dy;
                    if ((dx != 0 || dy != 0) && nx >= 0 && nx < CELLS_X && ny >= 0 && ny < CELLS_Y)
                    {
                        std::cout << nx << " " << ny << std::endl;
                        this->discover(nx, ny);
                        // cells[nx * CELLS_Y + ny].discover();
                    }
                }
            }
        }
        else
        {
            // TODO:
            //  count adjacent flags and bombs
            //  if num of adjecent flags == num of adjecent bombs
            //        discover all the adjecent fields
        }
        return result;
    }
    return -2;
}

int Minefield::flag(int x, int y)
{
    int result = cells[x * CELLS_Y + y].flag();
    if (result == -1)
        ;
    // TODO: gameover();
    return result;
}
int Minefield::highlight(int x, int y)
{
    if ((x != highlight_x || y != highlight_y) &&
        x >= 0 && x < CELLS_X && y >= 0 && y < CELLS_Y)
    {
        cells[highlight_x * CELLS_Y + highlight_y].unhighlight();
        cells[x * CELLS_Y + y].highlight();
        highlight_x = x;
        highlight_y = y;
    }
    return 0;
}