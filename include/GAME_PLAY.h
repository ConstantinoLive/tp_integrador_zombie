#ifndef GAME_PLAY_H
#define GAME_PLAY_H
#include "ZOMBIE.h"
#include <random>
#include "PLATAFORMA.h"
#include "Colisionable.h"
#include "PLANTA.h"
#include "DISPARO.h"
#include "GESTOR_DISPAROS.h"
#include "GESTOR_PLANTAS.h"
#include "Prize.h"
#include "Lifebar.h"
#include "Seleccion_de_zombie.h"
#include <iostream>
#include "EnergyBar.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Audio.h"



class GAME_PLAY
{
public:
    GAME_PLAY();
    virtual ~GAME_PLAY();
    void draw(sf::RenderWindow& window);
    void cmd();
    void check_collision_platform();
    //void updatePlants();
    void updateShootAndLife(sf::RenderTarget& window);
    void updatePrize();
    void update(sf::RenderTarget& window);
    bool getGameOver()
    {
        return _game_over;
    }
    void updatePlants2();
    void updatePlantGeneration();
    void updatePlantDeletion();
    sf::Vector2i getRandomPosition();

    std::vector<sf::Vector2i> _position=
    {
        {30,80},
        {60,80},
        {90,80},
        {120,80},
        {310,80},
        {330,80},
        {350,80},
        {380,80},
        {720,80},
        {750,80},
        {800,80},
        {1050,80},
        {1100,80},
        {1150,80},
        //14
        {200,210},
        {390,210},
        {410,210},
        {700,210},
        {710,210},
        {730,210},
        {920,210},
        {1050,210},
        {1100,210},
        {1120,210},
        //10
        {260,340},
        {280,340},
        {300,340},
        {530,340},
        {540,340},
        {780,340},
        {800,340},
        {820,340},
        {850,340},
        //9
        {100,500},
        {200,500},
        {300,500},
        {400,500},
        {500,500},
        {600,500},
        {700,500},
        {800,500},
        {900,500},
        {1000,500},
        {1100,500},
        //11
    };

protected:

private:
    GESTOR_DISPAROS _shoot_manager;
    ZOMBIE Z1;
    Seleccion_de_zombie selec_zom;
    EnergyBar _energy_bar;
    Disparo* disparoZombie;
    std::string _namePlayer;
    int puntaje = 0;
    int vidas;

    TIPO tipoDisparo;

    std::vector<Planta*> _array_plantas;
    GESTOR_PLANTAS _plant_manager;
    sf::Clock _plant_spawn_timer;


    Prize* _prize=nullptr;
    sf::Clock _prize_timer;
    sf::Clock _dead;
    bool _prize_generated;
    bool colisionPlanta ;
    Lifebar _life_bar;
 Audio Sound_4;
 Audio Sound_5;
Audio Sound_7;



    bool _is_dead=false;      //bandera para ver si la vida llego al final,puede servir, revisar posible getter()
    bool _game_over=false;
    TIPO _random_type;

    PLATAFORMA Plats[30];


    enum ESTADOS_GAME_PLAY{
        ACTION,
        PAUSE
    };

    ESTADOS_GAME_PLAY _estado;
    sf::Font _font_pause;
    sf::Text _text_pause;
    sf::Font _fontPlayer;
    sf::Text _textPlayer;
    sf::Font _fontPuntaje;
    sf::Text _textPuntaje;
    sf::Text _textvidas;
    sf::Text _cantvidas;



};

#endif // GAME_PLAY_H
