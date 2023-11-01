#include <SFML/Graphics.hpp>
#include "MENU_PRINCIPAL.h"
#include "Funciones.h"
#include <iostream>

#include<cstdlib>       //para rand y srand
#include <ctime>        //para time


using namespace std;

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));  //inicio semilla para rand


    MENU_PRINCIPAL menu(1220,800);

    menu.Opciones();

    return 0;
}

