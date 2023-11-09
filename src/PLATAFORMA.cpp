#include "PLATAFORMA.h"

PLATAFORMA::PLATAFORMA()
{
    _texture_bloque.loadFromFile("img/Plataforma_ind1.png");
    _sprite_bloque.setTexture(_texture_bloque);
   // _sprite_bloque.setPosition(x,y);
}

PLATAFORMA::~PLATAFORMA()
{
    //dtor
}

void PLATAFORMA::update()
{

}

sf::Sprite& PLATAFORMA::getDraw()
{
    return _sprite_bloque;
}

void PLATAFORMA::mobility()
{

}

sf::FloatRect PLATAFORMA::getBounds()const
{
    return _sprite_bloque.getGlobalBounds();
}
