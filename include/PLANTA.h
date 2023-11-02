#ifndef PLANTA_H
#define PLANTA_H

#include <SFML/Graphics.hpp>
#include"Colisionable.h"
#include"DISPARO.h"
#include "PLATAFORMA.h"
#include"GESTOR_DISPAROS.h"
#include <iostream>


/*  //esto lo meto en la clase disparo directamente
enum TIPO
{
    FIRE,
    GREEN,
    ICE,
    SUPER_GREEN
};
*/

#define LEFT    true
#define RIGHT   false
class Planta: public Colisionable, public sf::Drawable
{
public:
    Planta(TIPO tipo,sf::Vector2i pos,bool look, GESTOR_DISPAROS& gestor);
    virtual ~Planta();

    void draw(sf::RenderTarget& target,sf::RenderStates states) const override;   //reescribimos el metodo DRAW por haberlo heredado de DRAWABLE
    //sf::Sprite& getDraw();
    sf::FloatRect getBounds() const override;                                     //reescribimos el metodo getBounds por haberlo heredado de COLISIONABLE
    void escala(float esc);
    void movement(float x,float y);
    bool isLookingLeft();               //devuelve true si la planta mira a la izquierda
    void updateShooting();
    void updateMovement();
    void updateAnimation();
    void update();




protected:
    sf::Texture _plant_texture;
    sf::Sprite _plant_sprite;
    sf::IntRect _current_frame;
    sf::IntRect _first_frame_of_sheet;      //me sirve para saber las coordenadas donde arranca el frame de cada tipo de disparo
    int _end_of_frames_sheet;               //me sirve para saber hasta donde va cada sprite en los distintos tipos de disparos
    float _frame;                           //es un multiplicador que me permite pasar de cuadro a cuadro para la animacion

    int _width_texture;
    int _height_texture;
    sf::Vector2f _speed;
    int _damage;
    sf::Vector2i _position;
    bool _looking_left;                     //booleano que indica si la planta mira a la izquierda o derecha(default:izq)
    TIPO _type;
    sf::Clock _animationTimer;
    sf::Clock _spawn_shoot_timer;



    GESTOR_DISPAROS& _gestor_disparos;      //es una referencia al gestor disparos que gestionara todos los disparos generados por las plantas

    PLATAFORMA plataform;


    //funciones privadas


    void initVariables();
    void initTexture();
    void initAnimation();
    void initShooting();


};

#endif // PLANTA_H
