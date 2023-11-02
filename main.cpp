#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
#include "MENU_PRINCIPAL.h"
#include "Funciones.h"
#include <iostream>
//#include "Audio.h"
#include<cstdlib>       //para rand y srand
#include <ctime>        //para time


using namespace std;

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));  //inicio semilla para rand
    //Audio Sound_3a(3);
    MENU_PRINCIPAL menu(1220,800);

    //Sound_3a.audioON();
    menu.Opciones();

    return 0;
}

