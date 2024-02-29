#ifndef PLATAFORMA_H
#define PLATAFORMA_H

#include <SFML/Graphics.hpp>

#include "Colisionable.h"



class Plataforma : public Colisionable//: public sf::Drawable
{
public:
    Plataforma();
    virtual ~Plataforma();
    void update();
    void mobility();
    //void draw(sf::RenderTarget&target,sf::RenderStates states)const override;
    sf::Sprite& getDraw();
    sf::FloatRect getBounds() const override;


protected:

private:
    sf::Sprite _sprite_bloque;
    sf::Texture _texture_bloque;



};

#endif // PLATAFORMA_H
