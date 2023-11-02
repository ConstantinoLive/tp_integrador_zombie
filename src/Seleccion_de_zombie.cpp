#include "Seleccion_de_zombie.h"


Seleccion_de_zombie::Seleccion_de_zombie(float width, float height)
{
    if (!_fontItem.loadFromFile("font/Come With Us.ttf"))

    {
        // error...
    }
    _texture_fondo.loadFromFile("img/background_subMenu.png");
    _sprite_fondo.setTexture(_texture_fondo);
    _sprite_fondo.setScale(1.36,1.25);

    sf::Color color_opaco(255,255,255,80); //opacidad
    sf::Color color_brillante(255,255,255,255);

    _nombre_zombie[0].setFont(_fontItem);
    _nombre_zombie[0].setString("MORTY");
    _nombre_zombie[0].setColor(sf::Color::Green);
    _nombre_zombie[0].setPosition(sf::Vector2f(width / 6, height / 3.5 * 2.5));


    _nombre_zombie[1].setFont(_fontItem);
    _nombre_zombie[1].setString("SALLY");
    _nombre_zombie[1].setColor(sf::Color(255,255,255,80));
    _nombre_zombie[1].setPosition(sf::Vector2f(width / 2.3, height / 3.5 * 2.5));

    _nombre_zombie[2].setFont(_fontItem);
    _nombre_zombie[2].setString("IGOR");
    _nombre_zombie[2].setColor(sf::Color(255,255,255,80));
    _nombre_zombie[2].setPosition(sf::Vector2f(width / 1.5, height / 3.5 * 2.5));


    _nombre_zombie[3].setFont(_fontItem);
    _nombre_zombie[3].setString("VOLVER AL MENU ANTERIOR");
    _nombre_zombie[3].setColor(sf::Color(255,255,255,80));
    _nombre_zombie[3].setCharacterSize(20);
    _nombre_zombie[3].setPosition(sf::Vector2f(width / 6, height / 3.5 * 3));

    _nombre_zombie[4].setFont(_fontItem);
    _nombre_zombie[4].setString("VOLVER AL MENU PRINCIPAL");
    _nombre_zombie[4].setColor(sf::Color(255,255,255,80));
    _nombre_zombie[4].setCharacterSize(20);
    _nombre_zombie[4].setPosition(sf::Vector2f(width / 1.5, height / 3.5 * 3));


    _texture_Morty.loadFromFile("img/Morty.png");
    _sprite_Morty.setTexture(_texture_Morty);
    _sprite_Morty.scale(0.5,0.5);
    _sprite_Morty.setPosition(200,260);

    _texture_Sally.loadFromFile("img/Sally.png");
    _sprite_Sally.setTexture(_texture_Sally);
    _sprite_Sally.scale(0.7,0.7);
    _sprite_Sally.setPosition(450,230);

    _texture_Igor.loadFromFile("img/Igor.png");
    _sprite_Igor.setTexture(_texture_Igor);
    _sprite_Igor.scale(0.37,0.37);
    _sprite_Igor.setPosition(770,230);




    //_seleccionItem = 0;
}

Seleccion_de_zombie::~Seleccion_de_zombie()
{
    //dtor
}

void Seleccion_de_zombie::draw(sf::RenderTarget& target, sf::RenderStates states)const
{

    target.draw(_sprite_fondo,states);
    for (int x = 0; x < Item; x++)
    {
        target.draw(_nombre_zombie[x], states);
    }

    target.draw(_sprite_Morty, states);
    target.draw(_sprite_Sally, states);
    target.draw(_sprite_Igor, states);
}

void Seleccion_de_zombie::up()
{

    sf::Color color_opaco(255,255,255,80); //opacidad
    sf::Color color_brillante(255,255,255,255);

    if (_seleccionItem - 1 >= 0)
    {
        _nombre_zombie[_seleccionItem].setColor(sf::Color(255,255,255,80));
        //_sprite_Z[_seleccionItem].setColor(color_opaco);
        _seleccionItem--;

        std::cout << _seleccionItem << std::endl;
        _nombre_zombie[_seleccionItem].setColor(sf::Color::Green);
        //_sprite_Z[_seleccionItem].setColor(color_brillante);
    }
}

void Seleccion_de_zombie::down()
{

    sf::Color color_opaco(255,255,255,80); //opacidad
    sf::Color color_brillante(255,255,255,255);

    if (_seleccionItem + 1 < Item)
    {
        _nombre_zombie[_seleccionItem].setColor(sf::Color(255,255,255,80));
        //_sprite_Z[_seleccionItem].setColor(color_opaco);
        _seleccionItem++;

        std::cout << _seleccionItem << std::endl;
        _nombre_zombie[_seleccionItem].setColor(sf::Color::Green);
        //_sprite_Z[_seleccionItem].setColor(color_brillante);
    }
}



void Seleccion_de_zombie::Opciones()
{
    sf::RenderWindow window(sf::VideoMode(1220, 800), "Zombies vs PlantaZ");
    window.setFramerateLimit(60);

    // *******************Menu************************
    MENU_PRINCIPAL menu_p(window.getSize().x, window.getSize().y);
    Seleccion_de_zombie selec_z(window.getSize().x, window.getSize().y);
    SubMenu sub_menu(window.getSize().x, window.getSize().y);
Audio Sound_3e(3);
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

    Sound_3e.audioON();
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

                    selec_z.up();
                    break;
                case sf::Keyboard::Down:

                    selec_z.down();
                    break;
                case sf::Keyboard::Return:

                    switch (selec_z.GetPressedItem())
                    {
                    case 0:
                        std::cout << "Morty" <<std:: endl;
                        seleccionZombie(selec_z.GetPressedItem());
                        window.close();
                        Juego();
                        break;
                    case 1:
                        std::cout << "Sally" <<std:: endl;
                        seleccionZombie(selec_z.GetPressedItem());
                        window.close();
                        Juego();
                        break;
                    case 2:
                        std::cout << "Igor" <<std:: endl;
                        seleccionZombie(selec_z.GetPressedItem());
                        window.close();
                        Juego();
                        break;
                    case 3:
                        std::cout << "Menu anterior" <<std:: endl;
                        window.close();
                        sub_menu.Opciones();

                        break;
                    case 4:
                        std::cout << "Menu principal" <<std:: endl;
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

        window.draw(selec_z);
        window.draw(Text);



        window.display();
    }



}
