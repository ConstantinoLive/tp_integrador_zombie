#include "ZOMBIE.h"
#include <iostream>

ZOMBIE::ZOMBIE(GESTOR_DISPAROS& gestor) : _gestor_disparos(gestor)
{

    _frame = 0;
    _texture_zombie.loadFromFile("img/protagonista.png");
    _sprite_zombie.setTexture(_texture_zombie);
    _sprite_zombie.setTextureRect({0,0,378,890});
    _sprite_zombie.setOrigin(_sprite_zombie.getGlobalBounds().width/2, _sprite_zombie.getGlobalBounds().height/11);
    _sprite_zombie.setPosition(50, 485);
    _estado = ESTADOS::QUIETO;
    _jump_force=0; //Fuerza de salto inicial

    /*_texture_zombie.loadFromFile("img/zombie_DI3.png");
    _sprite_zombie.setTexture(_texture_zombie);
    _sprite_zombie.setPosition(0,485); // posicion inicial
    _estado=ESTADOS::QUIETO; //estado inicial
    _jump_force=0; //Fuerza de salto inicial
    */
}

ZOMBIE::~ZOMBIE()
{
    //dtor
}

void ZOMBIE::update()
{
    _frame += 0.2;
    if (_frame >= 4)
    {
        _frame = 0;
    }
    switch (_estado)
    {
    case QUIETO:

        _sprite_zombie.setTextureRect(sf::IntRect(0, 0, 380, 890));
        _sprite_zombie.setScale(0.095, 0.095);
        _jump_force -= 1.8;

        _sprite_zombie.move(0, -_jump_force);

        if (_energiaRegen.getElapsedTime().asSeconds()>=5)
        {
            if(_energia <=95)
                _energia += 5 ;
            zombieIzquierda = false;
        }

        break;
    case QUIETO_IZQ:
        _sprite_zombie.setTextureRect(sf::IntRect(0, 0, 380, 890));
        _sprite_zombie.setScale(-0.095, 0.095);
        _jump_force -= 1.8;

        _sprite_zombie.move(0, -_jump_force);

        if (_energiaRegen.getElapsedTime().asSeconds()>=5)
        {
            if(_energia <=95)
                _energia += 5 ;
            zombieIzquierda = true;
        }
        break;

    case CAMINANDO_DER: //desplazamiento a la derecha y animacion
        _sprite_zombie.setTextureRect({ 0 + int(_frame) * 590,885,590,885 });
        _sprite_zombie.setScale(0.095, 0.095);

        _sprite_zombie.move(2, 0);
        _jump_force -= 1.8;
        _sprite_zombie.move(0, -_jump_force);
        _estado = ESTADOS::QUIETO_IZQ;
        zombieIzquierda = false;
        break;

    case CAMINANDO_IZQ: //desplazamiento a la izquierda y animacion


        _sprite_zombie.move(-2, 0);
        _sprite_zombie.setTextureRect({ 0 + int(_frame) * 590,885,590,885 });
        _sprite_zombie.setScale(-0.095, 0.095);
        _estado = ESTADOS::QUIETO_IZQ;
        _jump_force -= 1.8;
        zombieIzquierda = true;

        _sprite_zombie.move(0, -_jump_force);


        break;

    case SALTANDO:
        if(zombieIzquierda)
        {
            _sprite_zombie.setScale(-0.095,0.095);
            _jump_force -= 1.8;
            _sprite_zombie.setTextureRect({ 0 + int(_frame) * 590,885,590,885 });
            _sprite_zombie.move(0, -_jump_force);

        }
        else
        {
            _sprite_zombie.setScale(0.095,0.095);
            _jump_force -= 1.8;
            _sprite_zombie.setTextureRect({ 0 + int(_frame) * 590,885,590,885 });
            _sprite_zombie.move(0, -_jump_force);
        }
        break;
    case CAMINANDO_DER_SALTANDO:
        _sprite_zombie.move(3, 0);
        _sprite_zombie.setScale(0.095,0.095);
        _jump_force -= 2.2;
        _sprite_zombie.setTextureRect({ 0 +  int(_frame) * 590,885,590,885 });
        _sprite_zombie.move(0, -_jump_force);
        zombieIzquierda = false;

        break;
    case CAMINANDO_IZQ_SALTANDO:
        _sprite_zombie.move(-3, 0);
        _sprite_zombie.setScale(-0.095,0.095);
        _sprite_zombie.setTextureRect({ 0 + int(_frame) * 590,885,590,885 });
        _jump_force -= 2.2;
        _sprite_zombie.move(0, -_jump_force);
        zombieIzquierda = true;
        break;


    case DISPARANDO:
        if(!yaDisparo)
        {
            if(_spawn_shoot_timer.getElapsedTime().asSeconds() >= 3 )
            {
                float positionX = _sprite_zombie.getPosition().x;
                float positionY = _sprite_zombie.getPosition().y;

                if(zombieIzquierda)
                {
                    positionX -= 30;
                    _disparo = new Disparo(TIPO::BRAIN, {positionX,positionY }, zombieIzquierda);
                    _gestor_disparos.agregarDisparo(_disparo);
                    _spawn_shoot_timer.restart();
                    _estado = ESTADOS::QUIETO_IZQ;
                    yaDisparo = true;
                }
                else
                {

                    positionX +=30;
                    //positionY -=30;



                    _disparo = new Disparo(TIPO::BRAIN, {positionX,positionY }, false);
                    _gestor_disparos.agregarDisparo(_disparo);
                    _spawn_shoot_timer.restart();
                    _estado = ESTADOS::QUIETO;
                    yaDisparo = true;
                }





            }


        }
        break;
    }

    /*switch (_estado)
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
    _jump_force-=1.5; //fuerza de gravedad. Se ejerse siempre
    _sprite_zombie.move(0,-_jump_force);
    */

}
/*
void ZOMBIE::draw(sf::RenderTarget&target,sf::RenderStates states)const
{
    target.draw(_sprite_zombie,states);
}*/

void ZOMBIE::mobility()
{
    if(_estado==ESTADOS::QUIETO|| _estado == ESTADOS::DISPARANDO || _estado == ESTADOS::QUIETO_IZQ)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            if (_energia >= 25)
            {
                _estado = ESTADOS::SALTANDO;
                _jump_force = 22;
                _energia -= 25;
            }

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            _estado=ESTADOS::CAMINANDO_DER;

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            _estado=ESTADOS::CAMINANDO_IZQ;

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            _estado = ESTADOS::CAMINANDO_DER_SALTANDO;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            _estado = ESTADOS::CAMINANDO_IZQ_SALTANDO;

        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)&& !isZPressed)
        {

            //std::cout<<"CEREBRO"<<std::endl;
            isZPressed = true;
            _estado = ESTADOS::DISPARANDO;



        }
        else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        {
            isZPressed =false;
            yaDisparo =false;
        }

    }


}

sf::Sprite& ZOMBIE::getDraw()
{
    return _sprite_zombie;
}

void ZOMBIE::suelo(float x, float y)
{

    if(zombieIzquierda)
    {
        _estado=ESTADOS::QUIETO_IZQ;
        _jump_force=0;
        _sprite_zombie.setPosition(x,y);
    }
    else
    {
        _estado=ESTADOS::QUIETO;
        _jump_force=0;
        _sprite_zombie.setPosition(x,y);
    }

    /*_estado=ESTADOS::QUIETO;
    _jump_force=0;
     _sprite_zombie.setPosition(x,y);*/
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

sf::Vector2f ZOMBIE::getPositionPrev()
{
    return _prevPos;
}
