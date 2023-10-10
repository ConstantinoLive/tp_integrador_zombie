#include <SFML/Graphics.hpp>
#include "MENU_PRINCIPAL.h"
#include "Funciones.h"
#include <iostream>

#include<cstdlib>       //para rand y srand
#include <ctime>        //para time

//prueba commit



using namespace std;

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));  //inicio semilla para rand

    sf::RenderWindow window(sf::VideoMode(1220, 800), "Zombies vs PlantaZ");
    window.setFramerateLimit(60);
    MENU_PRINCIPAL menu(window.getSize().x,window.getSize().y);
    //SubMenu sub_menu(window.getSize().x, window.getSize().y);
    menu.Opciones();
}
   /* sf::RenderWindow window(sf::VideoMode(1220, 800), "Zombies vs PlantaZ");
    window.setFramerateLimit(60);

    // *******************Menu************************
    MENU_PRINCIPAL menu_p(window.getSize().x,window.getSize().y);
    // *******************Titulo**********************
    sf::Font font;
    if (!font.loadFromFile("font/Riot Act 2.otf"))
    {
        std::cout<<"Error al cargar texto"<<std::endl;
    }
    sf::Text Text;
    Text.setFont(font);
    Text.setPosition(sf::Vector2f(600/3.5,40));
    Text.setCharacterSize(80);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
            case sf::Event::KeyReleased:
                switch(event.key.code)
                {
                case sf::Keyboard::Up:
                    menu_p.up();
                    break;
                case sf::Keyboard::Down:
                    menu_p.down();
                    break;
                case sf::Keyboard::Return:
                    switch(menu_p.GetPressedItem())
                    {
                    case 0:
                        cout<<"INICIO"<<endl;
                        window.close();
                        Juego();
                        break;
                    case 1:
                        cout<<"ESTADISTICA"<<endl;
                        break;
                    case 2:
                        cout<<"OPCIONES"<<endl;
                        break;
                    case 3:
                        cout<<"REGLAMENTO"<<endl;
                        break;
                    case 4:
                        cout<<"CREDITO"<<endl;
                        break;
                    }
                    break;

                }
                break;

            }

            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        Text.setString("Zombies VS PlantaZ");


        window.draw(menu_p);
        window.draw(Text);



        window.display();
    }

    return 0;
}
*/
