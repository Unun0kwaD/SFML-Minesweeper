#include "cell.h"

Cell::Cell(sf::Texture &texture, sf::Vector2f position, int celltype)
{
    sprite.setPosition(position);
    sprite.setScale(sf::Vector2f(SCALE, SCALE));
    sprite.setTexture(texture);
    type = celltype;
    sprite.setTextureRect(getRectFromCellType(celltype));
}

sf::IntRect Cell::getRectFromCellType(int n)
{
    int rectLeft = n % 4;
    int rectTop = n / 4;
    return sf::IntRect(rectLeft * 16, rectTop * 16, 16, 16);
}
void Cell::Draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}
void Cell::ChangeTextureRect(int img)
{
    type=img;
    sprite.setTextureRect(getRectFromCellType(img));
}
int Cell::discover()
{
    if (!discovered)
    {
        discovered = true;
        if (mine)
        {
            this->ChangeTextureRect(MINE);
            return -1;
        }
        if (adjacent_mines == 0)
        {
            this->ChangeTextureRect(EMPTY);
        }
        else
            this->ChangeTextureRect(adjacent_mines - 1);

        return adjacent_mines;
    }
    return -2;
}
int Cell::flag()
{
    if (!flagged && !discovered)
    {
        flagged = true;
        this->ChangeTextureRect(FLAG);
        return 0;
    }
    else if (!discovered){
        flagged = false;
        this->ChangeTextureRect(HIDDEN);
        return 0;
    }
    return -2;
}
int Cell::reset(sf::Vector2f position, int celltype){
    sprite.setPosition(position);
    type = celltype;
    sprite.setTextureRect(getRectFromCellType(celltype));
    return 0;
}
int Cell::highlight(){
    sprite.setColor(sf::Color(255, 255, 255, 192));
    return 0;
}
int Cell::unhighlight(){
    // ChangeTextureRect(type);
    sprite.setColor(sf::Color(255, 255, 255, 255));
    return 0;
}