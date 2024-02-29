#ifndef PARTIDA_H
#define PARTIDA_H

#include <cstring>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Player.h"

#define Rank 10

class Partida
{
    public:
        Partida();
        Partida(int puntaje, std::string nombre);
        virtual ~Partida();
        std::string getName() const;
        void setName(std::string nombre);
        int getPuntos();// const;
        void setPuntos(int puntaje);
        int contarPartidas();
        void mostrarPlayer(/*sf::RenderWindow& window)*/);
        //void cargarRanking(Partida partida[10]);
        //Partida _ranking[10];

    protected:

    private:
        char _nombre[10];
        int _puntos;
        //std::string jugadores[10];



        //Player *player;
};


#endif // PARTIDA_H
