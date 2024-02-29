#ifndef PLAYER_H
#define PLAYER_H

#include <string.h>
#include <cstdlib>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Partida.h"

class Player
{
private:
	int _puntaje;
	std::string _nombre;
	char nombreP[10];

public:
	Player();
	Player(int puntaje, std::string nombre);
	Player(int puntaje, char nombreP);
	//sets()
	void setPuntaje(int puntaje);
	void setNombre(std::string nombre);
		//gets()
	int getPuntaje();

	std::string getNombre();
	std::string ingresarNombre();
};


#endif // PLAYER_H
