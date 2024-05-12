#include "cell.h"

Cell::Cell(sf::Texture& texture,sf::Vector2f position,int celltype){
    sprite.setPosition(position);
    sprite.setScale(sf::Vector2f(SCALE,SCALE));
    sprite.setTexture(texture);
    type=celltype;
    sprite.setTextureRect(getRectFromCellType(celltype));
}

sf::IntRect Cell::getRectFromCellType(int n){
    int rectLeft = n%4;
    int rectTop = n/4;
    return sf::IntRect(rectLeft*16,rectTop*16,16,16);
}
void Cell::Draw(sf::RenderWindow& window){
    window.draw(sprite);
}
void Cell::ChangeTextureRect(int img)
{
    sprite.setTextureRect(getRectFromCellType(img));
}
int Cell::discover(){
    
    return 0;
}