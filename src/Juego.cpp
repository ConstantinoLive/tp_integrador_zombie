#include "Funciones.h"
#include <SFML/Graphics.hpp>
#include "MENU_PRINCIPAL.h"
#include "SubMenu.h"
#include "Player.h"
#include <iostream>
#include "GAME_PLAY.h"


int numeroZombie = 0;
void Juego()
{
    sf::RenderWindow window(sf::VideoMode(1220, 800), "Zombies vs PlantaZ");
    window.setFramerateLimit(60);

    sf::Sprite fondo;
    sf::Texture _fondo;

    if (!_fondo.loadFromFile("img/background_zombie_1.png"))
    {
        std::cout << "Error al cargar la textura del fondo" << std::endl;
        return;
    }
    fondo.setTexture(_fondo);

    GAME_PLAY gp;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {


            if (event.type == sf::Event::Closed)
                window.close();
        }

        gp.update(window);
        gp.cmd();


        window.clear(sf::Color::Black);

        window.draw(fondo);
        gp.draw(window);


        window.display();
    }
}

int seleccionZombie(int numero)
{
    numeroZombie = numero;
}
int getZombie()
{
    return numeroZombie;
}
