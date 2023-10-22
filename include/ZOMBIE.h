#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <SFML/Graphics.hpp>
#include"Colisionable.h"
#include "DISPARO.h"
#include "GESTOR_DISPAROS.h"
#include <iostream>


class ZOMBIE: public Colisionable//: public sf::Drawable
{
public:
    ZOMBIE(GESTOR_DISPAROS& gestorv);
    enum ESTADOS
    {
        QUIETO,
        QUIETO_IZQ,
        IZQ,
        CAMINANDO_DER,
        CAMINANDO_IZQ,
        SALTANDO,
        CAMINANDO_DER_SALTANDO,
        CAMINANDO_IZQ_SALTANDO,
        DISPARANDO

    };
    virtual ~ZOMBIE();
    void update();
    //void draw(sf::RenderTarget&target,sf::RenderStates states)const override;
    void mobility();
    sf::Sprite& getDraw();
    void suelo(float x, float y);
    Disparo* _disparo;
    float getjump_force();
    sf::FloatRect getBounds() const override;
    bool isZPressed = false;
    bool yaDisparo = false;
    bool zombieIzquierda;
    sf::Vector2f getPositionPrev();

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
    sf::Clock _spawn_shoot_timer;
    int _vida;
    int _energia = 100;



};

#endif // ZOMBIE_H
