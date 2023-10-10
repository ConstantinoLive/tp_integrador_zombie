#ifndef GAME_PLAY_H
#define GAME_PLAY_H
#include "ZOMBIE.h"
#include "PLATAFORMA.h"

#include "PLANTA.h"

#include "DISPARO.h"

#include "GESTOR_DISPAROS.h"

#include "Prize.h"

#include "Lifebar.h"


class GAME_PLAY
{
public:
    GAME_PLAY();
    virtual ~GAME_PLAY();
    void draw(sf::RenderWindow& window);
    void cmd();
    void check_collision_platform();
    void updatePlants();
    void updateShootAndLife(sf::RenderTarget& window);
    void updatePrize();
    void update(sf::RenderTarget& window);

protected:

private:
    ZOMBIE Z1;

    std::vector<Planta*> _array_plantas;

    Prize* _prize=nullptr;
    sf::Clock _prize_timer;
    bool _prize_generated;

    Lifebar _life_bar;

    GESTOR_DISPAROS _shoot_manager;

    bool _is_dead;      //bandera para ver si la vida llego al final,puede servir, revisar posible getter()


    PLATAFORMA Plats[30];

    enum ESTADOS_GAME_PLAY{
        ACTION,
        PAUSE
    };

    ESTADOS_GAME_PLAY _estado;
    sf::Font _font_pause;
    sf::Text _text_pause;

};

#endif // GAME_PLAY_H
