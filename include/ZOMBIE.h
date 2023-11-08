#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include"Colisionable.h"
#include "DISPARO.h"
#include "GESTOR_DISPAROS.h"
#include <iostream>
#include "Funciones.h"
#include "Lifebar.h"
#include "EnergyBar.h"
#include "Audio.h"



class ZOMBIE: public Colisionable//: public sf::Drawable
{
public:
    ZOMBIE(int opc, GESTOR_DISPAROS& gestor);
    enum ESTADOS
    {
        NACIMIENTO,
        QUIETO,
        QUIETO_IZQ,
        IZQ,
        CAMINANDO_DER,
        CAMINANDO_IZQ,
        SALTANDO,
        CAMINANDO_DER_SALTANDO,
        CAMINANDO_IZQ_SALTANDO,
        DISPARANDO,
        MURIENDO,

    };
    virtual ~ZOMBIE();
    void update();
    void mobility();
    sf::Sprite& getDraw();
    void suelo(float x, float y);
    Disparo* _disparo;
    Lifebar lb;
    Audio sound_2;
    Audio Sound_6;
    float getjump_force();
    sf::FloatRect getBounds() const override;
    bool isZPressed = false;
    bool yaDisparo = false;
    bool zombieIzquierda;
    sf::Vector2f getPositionPrev();
    void initAnimation();
    void updateAnimation();
    void update_muriendo();
    float gettimeshoot();
    void settimeshoot(sf::Time);
   /* void setvida(int v)
    {
        _vida=-v;
    }*/
    int getvida()
    {
        return _vida;
    }
    void setOpcion(int opc)
    {
        _opcion=opc;

    }
    int getOpcion()
    {
        return _opcion;
    }

protected:
    GESTOR_DISPAROS& _gestor_disparos;
private:


    sf::Sprite _sprite_zombie;
    sf::Texture _texture_zombie;

    ESTADOS _estado;
    int _xtexture=0;
    float _jump_force;
    bool _delaySalto;
    sf::Clock _energiaRegen;
    float _frame;
    sf::Vector2f _prevPos;
    sf::Clock _animationTimer;
    sf::Clock _spawn_shoot_timer;
    sf::Time segundos;
    sf::Time _time_shoot;
    int _vida=3;
    int _energia = 100;
    int _opcion;
    //float _time_shoot;






};

#endif // ZOMBIE_H
