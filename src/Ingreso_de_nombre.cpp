#include "Funciones.h"
#include <SFML/Graphics.hpp>
#include "MENU_PRINCIPAL.h"
#include "SubMenu.h"
#include "Player.h"

std::string _nombrePlayer = "Player";
void ingresoNombre()
{
    sf::RenderWindow window(sf::VideoMode(300, 50),"", sf::Style::None);
    window.setFramerateLimit(60);
    window.setPosition(sf::Vector2i(1000,510));

    // *******************Menu************************
    MENU_PRINCIPAL menu_p(window.getSize().x, window.getSize().y);
    SubMenu sub_menu(window.getSize().x, window.getSize().y);
    // *******************Titulo**********************
    sf::Font font;

    if (!font.loadFromFile("Font/TT Interphases Pro Trial Black.ttf"))
    {
        // error...
    }
    sf::Text Text;
    Text.setFont(font);
    //Text.setPosition(sf::Vector2f(600 / 3.5, 40));
    Text.setCharacterSize(40);
    sf::Text texto;
    texto.setFont(font);
    //texto.setPosition(sf::Vector2f(600 / 3.5, 40));
    texto.setCharacterSize(40);
    texto.setFillColor(sf::Color::White);

    std::string entrada = ""; // Aquí se almacenará el texto ingresado
    Player player(0, entrada);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::TextEntered) {
                // agrega una letra y no deja que sea mas de 10 caracteres
                if (event.text.unicode >= 32 && event.text.unicode <= 126 && entrada.size()<=10) {
                    entrada += static_cast<char>(event.text.unicode);
                }
                // borra la ultima letra al presionar la tecla retroceso
                else if (event.text.unicode == 8 && !entrada.empty()) {
                    entrada.pop_back();
                }

                // actualiza el texto
                texto.setString(entrada);
            }
        }

        window.clear();
        window.draw(texto);
        window.display();
        if (event.key.code == sf::Keyboard::Enter) {
            _nombrePlayer= entrada;
            //player.setNombre(entrada);
            window.close();
            //sub_menu.Opciones();


        }
    }


}

std::string setNombre(std::string nombre)
{
    _nombrePlayer = nombre;
}
std::string getNombre()
{
    return _nombrePlayer;
}

