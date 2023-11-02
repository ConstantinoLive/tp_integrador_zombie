#ifndef PLATAFORMA_H
#define PLATAFORMA_H
#include <SFML/Graphics.hpp>
#include "Colisionable.h"



class PLATAFORMA//: public Colisionable//: public sf::Drawable
{
public:
    PLATAFORMA();
    virtual ~PLATAFORMA();
    void update();
    void mobility();
    //void draw(sf::RenderTarget&target,sf::RenderStates states)const override;
    sf::Sprite& getDraw();
    sf::FloatRect getBounds();


protected:

private:
    sf::Sprite _sprite_bloque;
    sf::Texture _texture_bloque;



};

#endif // PLATAFORMA_H
