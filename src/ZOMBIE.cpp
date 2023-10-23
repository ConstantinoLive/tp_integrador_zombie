#include "ZOMBIE.h"
#include <iostream>

ZOMBIE::ZOMBIE()
{
    _texture_zombie.loadFromFile("img/zombie_DI3.png");
    _sprite_zombie.setTexture(_texture_zombie);
    _sprite_zombie.setPosition(0,485); // posicion inicial
    _estado=ESTADOS::QUIETO; //estado inicial
    _jump_force=0; //Fuerza de salto inicial

}

ZOMBIE::~ZOMBIE()
{
    //dtor
}

void ZOMBIE::update()
{
    switch (_estado)
    {
    case QUIETO:

        _sprite_zombie.setTextureRect(sf::IntRect(0,189.50,56.55,94.75)); //Textura quieto.... x,y,

        break;

    case CAMINANDO_DER: //desplazamiento a la derecha y animacion

        _xtexture = (int)_sprite_zombie.getPosition().x/10 % 8;
        _xtexture = _xtexture*56.60;
        //std::cout<<_xtexture<<std::endl;
        _sprite_zombie.setTextureRect(sf::IntRect(_xtexture,189.50,56.55,94.75));
        _sprite_zombie.move(4,0);
        _estado=ESTADOS::QUIETO;

        break;

    case CAMINANDO_IZQ: //desplazamiento a la izquierda y animacion

        _xtexture = (int)_sprite_zombie.getPosition().x/10 % 8;
        _xtexture = _xtexture*56.60;
        //std::cout<<_xtexture<<std::endl;
        _sprite_zombie.setTextureRect(sf::IntRect(_xtexture,284.25,56.55,94.75));
        _sprite_zombie.move(-4,0);
        _estado=ESTADOS::QUIETO;

        break;

    case SALTANDO:

        _sprite_zombie.setTextureRect(sf::IntRect(113.2,94.75,56.55,94.75));


        break;
    }
    _jump_force-=2; //fuerza de gravedad. Se ejerse siempre
    _sprite_zombie.move(0,-_jump_force);
}
/*
void ZOMBIE::draw(sf::RenderTarget&target,sf::RenderStates states)const
{
    target.draw(_sprite_zombie,states);
}*/

void ZOMBIE::mobility()
{
    if(_estado==ESTADOS::QUIETO)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            _estado=ESTADOS::SALTANDO;
            _jump_force=25;

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            _estado=ESTADOS::CAMINANDO_DER;

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            _estado=ESTADOS::CAMINANDO_IZQ;

        }

    }


}

sf::Sprite& ZOMBIE::getDraw()
{
    return _sprite_zombie;
}

void ZOMBIE::suelo(float x, float y)
{
    _estado=ESTADOS::QUIETO;
    _jump_force=0;
     _sprite_zombie.setPosition(x,y);
    //_sprite_zombie.setPosition(_sprite_zombie.getPosition().x,485);
}

float ZOMBIE::getjump_force()
{
    return _jump_force;
}


sf::FloatRect ZOMBIE::getBounds()const
{
    return _sprite_zombie.getGlobalBounds();
}

