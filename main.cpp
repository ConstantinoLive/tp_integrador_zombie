#include <SFML/Graphics.hpp>
//#include "MENU_PRINCIPAL.h"
//#include "Funciones.h"
#include <iostream>
#include<cstdlib>       //para rand y srand
#include <ctime>        //para time

#include "Menu.h"
#include "GAME_PLAY.h"
#include "Juego2.h"


//using namespace std;

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));  //inicio semilla para rand

    Juego2 zombies_vs_plantas;

    zombies_vs_plantas.run();
    return 0;
}

