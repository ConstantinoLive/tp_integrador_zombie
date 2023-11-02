//#define SFML_NO_DEPRECATED_WARNINGS
#include "SubMenu.h"

using namespace std;

SubMenu::SubMenu(float width, float height)
{
    if (!_fontItem.loadFromFile("font/Come With Us.ttf"))

    {
        // error...
    }
    _textureSubMenu.loadFromFile("img/background_subMenu.png");
    _spriteSubMenu.setTexture(_textureSubMenu);
    _spriteSubMenu.setScale(1.36,1.25);


    _subMenu[0].setFont(_fontItem);
    _subMenu[0].setString("JUGAR");
    _subMenu[0].setColor(sf::Color::Green);
    _subMenu[0].setPosition(sf::Vector2f(width / 6, height / 3.5 * 1));

    _subMenu[1].setFont(_fontItem);
    _subMenu[1].setString("INGRESAR NOMBRE");
    _subMenu[1].setColor(sf::Color(0,0,0 ));
    _subMenu[1].setPosition(sf::Vector2f(width / 6, height / 3.5 * 1.5));

    _subMenu[2].setFont(_fontItem);
    _subMenu[2].setString("SELECCIONAR TIPO ZOMBIE");
    _subMenu[2].setColor(sf::Color(0,0,0));
    _subMenu[2].setPosition(sf::Vector2f(width / 6, height / 3.5 * 2));

    _subMenu[3].setFont(_fontItem);
    _subMenu[3].setString("VOLVER AL MENU ANTERIOR");
    _subMenu[3].setColor(sf::Color(0,0,0));
    _subMenu[3].setPosition(sf::Vector2f(width / 6, height / 3.5 * 2.5));



    _seleccionItem = 0;

}


SubMenu::~SubMenu()
{
    //dtor
}

void SubMenu::draw(sf::RenderTarget& target, sf::RenderStates states)const
{

    target.draw(_spriteSubMenu,states);
    for (int x = 0; x < Item; x++)
    {
        target.draw(_subMenu[x], states);
    }
}

void SubMenu::up()
{

    if (_seleccionItem - 1 >= 0)
    {
        _subMenu[_seleccionItem].setColor(sf::Color(0,0,0));
        _seleccionItem--;

        _subMenu[_seleccionItem].setColor(sf::Color::Green);
    }
}

void SubMenu::down()
{

    if (_seleccionItem + 1 < Item)
    {
        _subMenu[_seleccionItem].setColor(sf::Color(0,0,0));

        _seleccionItem++;

        _subMenu[_seleccionItem].setColor(sf::Color::Green);
    }
}
void SubMenu::Opciones() {

    sf::RenderWindow window(sf::VideoMode(1220, 800), "Zombies vs PlantaZ");
    window.setFramerateLimit(60);

    // *******************Menu************************
    MENU_PRINCIPAL menu_p(window.getSize().x, window.getSize().y);
    SubMenu sub_menu(window.getSize().x, window.getSize().y);
    Seleccion_de_zombie selec_z(window.getSize().x, window.getSize().y);
 Audio Sound_3b(3);
    // *******************Titulo**********************
    sf::Font font;



    if (!font.loadFromFile("Font/Riot Act 2.otf"))
    {
        // error...
    }

    sf::Text Text;
    Text.setFont(font);
    Text.setPosition(sf::Vector2f(600 / 3.5, 40));
    Text.setCharacterSize(80);

    Sound_3b.audioON();
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                case sf::Keyboard::Up:

                    sub_menu.up();
                    break;
                case sf::Keyboard::Down:

                    sub_menu.down();
                    break;
                case sf::Keyboard::Return:
                    switch (sub_menu.GetPressedItem())
                    {
                    case 0:
                        cout << "Jugar" << endl;
                        window.close();
                        Juego();
                        break;
                    case 1:
                        cout << "INGRESAR NOMBRE" << endl;
                        window.close();
                        ingresoNombre();
                        break;
                    case 2:
                        cout << "SELECCIONAR ZOMBIE" << endl;
                         window.close();
                         selec_z.Opciones();

                        break;
                    case 3:
                        cout << "VOLVER AL MENU ANTERIOR" << endl;
                        window.close();
                        menu_p.Opciones();

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
        Text.setColor(sf::Color::Black);

        window.draw(sub_menu);
        window.draw(Text);



        window.display();
    }



}
