#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include<iostream>
#include <cstring>

void Juego();
void ingresoNombre();
extern int numeroZombie;
int seleccionZombie(int numero);
int getZombie();
extern std::string _nombrePlayer;
std::string setNombre(std::string nombre);
std::string getNombre();


#endif // FUNCIONES_H_INCLUDED
