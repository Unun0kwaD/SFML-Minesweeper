#include "cell.h"

Cell::Cell(sf::Texture& texture,sf::Vector2f position,int celltype){
    sprite.setPosition(position);
    sprite.setScale(sf::Vector2f(SCALE,SCALE));
    sprite.setTexture(texture);
    type=celltype;
    sprite.setTextureRect(this->getRectFromCellType());
}

sf::IntRect Cell::getRectFromCellType(){
    int rectLeft = type%4;
    int rectTop = type/4;
    return sf::IntRect(rectLeft*16,rectTop*16,16,16);
}
void Cell::Draw(sf::RenderWindow& window){
    window.draw(sprite);
}
int Cell::discover(){
    
    return 0;
}