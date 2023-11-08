#include "MENU_PRINCIPAL.h"


MENU_PRINCIPAL::MENU_PRINCIPAL(float width, float height)
{
    if (!font_item.loadFromFile("font/Come With Us.ttf"))
    {
        std::cout<<"Error al cargar texto"<<std::endl;
    }

    _texture_menu.loadFromFile("img/tumba.png");
    _fondo_menu.setTexture(_texture_menu);
    _fondo_menu.setScale(0.23,0.2);

    menu_p[0].setFont(font_item);
    menu_p[0].setString("INICIO");
    menu_p[0].setColor(sf::Color::Green);
    menu_p[0].setPosition(sf::Vector2f(width/2.08,height/5*1.2));

    menu_p[1].setFont(font_item);
    menu_p[1].setString("ESTADISTICA");
    menu_p[1].setColor(sf::Color(255,255,255,80));
    menu_p[1].setPosition(sf::Vector2f(width/2.3,height/5*1.7));

    menu_p[2].setFont(font_item);
    menu_p[2].setString("OPCIONES");
    menu_p[2].setColor(sf::Color(255,255,255,80));
    menu_p[2].setPosition(sf::Vector2f(width/2.2,height/5*2.2));

    menu_p[3].setFont(font_item);
    menu_p[3].setString("REGLAMENTO");
    menu_p[3].setColor(sf::Color(255,255,255,80));
    menu_p[3].setPosition(sf::Vector2f(width/2.25,height/5*2.7));

    menu_p[4].setFont(font_item);
    menu_p[4].setString("CREDITOS");
    menu_p[4].setColor(sf::Color(255,255,255,80));
    menu_p[4].setPosition(sf::Vector2f(width/2.17,height/5*3.2));


    seleccion_item=0;

}


MENU_PRINCIPAL::~MENU_PRINCIPAL()
{
    //dtor
}

void MENU_PRINCIPAL::draw(sf::RenderTarget& target, sf::RenderStates states)const
{

    target.draw(_fondo_menu,states);
    for(int x=0; x<Item; x++)
    {
        target.draw(menu_p[x],states);
    }

}

void MENU_PRINCIPAL::up()
{

    if(seleccion_item-1>=0)
    {
        menu_p[seleccion_item].setColor(sf::Color(255,255,255,80));
        seleccion_item--;

        menu_p[seleccion_item].setColor(sf::Color::Green);
    }
}

void MENU_PRINCIPAL::down()
{

    if(seleccion_item+1<Item)
    {
        menu_p[seleccion_item].setColor(sf::Color(255,255,255,80));
        seleccion_item++;

        menu_p[seleccion_item].setColor(sf::Color::Green);
    }
}

void MENU_PRINCIPAL::Opciones()
{
    sf::RenderWindow window(sf::VideoMode(1220, 800), "Zombies vs PlantaZ");
    window.setFramerateLimit(60);

    // *******************Menu************************
    MENU_PRINCIPAL menu_p(window.getSize().x, window.getSize().y);
    SubMenu sub_menu(window.getSize().x, window.getSize().y);
    Creditos creditos(window.getSize().x, window.getSize().y);
    Audio Sound_3c(3);
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

    Sound_3c.audioON();
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

                    menu_p.up();
                    break;
                case sf::Keyboard::Down:

                    menu_p.down();
                    break;
                case sf::Keyboard::Return:
                    switch (menu_p.GetPressedItem())
                    {
                    case 0:
                        std::cout << "INICIO" << std::endl;
                        window.close();
                        sub_menu.Opciones();

                        break;
                    case 1:
                        std::cout << "ESTADISTICA" << std::endl;

                        break;
                    case 2:
                        std::cout << "OPCIONES" << std::endl;

                        break;
                    case 3:
                        std::cout << "REGLAMENTO" << std::endl;

                        break;
                    case 4:
                        std::cout << "CRÉDITO" << std::endl;
                        window.close();
                        creditos.Opciones();

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


}
