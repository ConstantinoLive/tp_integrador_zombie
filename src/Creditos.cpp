#include "Creditos.h"

Creditos::Creditos(float width, float height)
{
   if (!_fondo.loadFromFile("img/background_subMenu.png"))
    {
        std::cout << "Error al cargar la textura del fondo" << std::endl;
        return;
    }
    fondo.setTexture(_fondo);
    fondo.scale(1.36,1.25);

    if (!font_text.loadFromFile("font/TT Interphases Pro Trial Black.ttf"))
    {
         std::cout<<"Error al cargar texto"<<std::endl;
    }

    text[0].setFont(font_text);
    text[0].setFillColor(sf::Color(255,255,255,180));
    text[0].setString("U.T.N.");
    text[0].setCharacterSize(100);
    text[0].setPosition(500,50);

    text[1].setFont(font_text);
    text[1].setFillColor(sf::Color(255,255,255,180));
    text[1].setString("Laboratorio II");
    text[1].setCharacterSize(60);
    text[1].setPosition(450,150);

    text[2].setFont(font_text);
    text[2].setFillColor(sf::Color(255,255,255,180));
    text[2].setString("Proyecto realizado por:");
    text[2].setCharacterSize(40);
    text[2].setPosition(50,350);

    text[3].setFont(font_text);
    text[3].setFillColor(sf::Color(255,255,255,180));
    text[3].setString("Carlos Matias Marques_______________________ Legajo 28731");
    text[3].setCharacterSize(30);
    text[3].setPosition(60,420);

    text[4].setFont(font_text);
    text[4].setFillColor(sf::Color(255,255,255,180));
    text[4].setString("Andres Gonzalo Bianchini_____________________ Legajo 28599");
    text[4].setCharacterSize(30);
    text[4].setPosition(60,470);

    text[5].setFont(font_text);
    text[5].setFillColor(sf::Color(255,255,255,180));
    text[5].setString("Fernando Daniel Clingo_______________________ Legajo 26859");
    text[5].setCharacterSize(30);
    text[5].setPosition(60,520);




    if (!font_item.loadFromFile("font/Come With Us.ttf"))
    {
         std::cout<<"Error al cargar texto"<<std::endl;
    }

    menu_C[0].setFont(font_item);
    menu_C[0].setFillColor(sf::Color::Green);
    menu_C[0].setString("SALIR");
    menu_C[0].setCharacterSize(20);
    menu_C[0].setPosition(300,685);

    menu_C[1].setFont(font_item);
    menu_C[1].setFillColor(sf::Color(255,255,255,80));
    menu_C[1].setString("VOLVER AL MENU PRINCIPAL");
    menu_C[1].setCharacterSize(20);
    menu_C[1].setPosition(813,685);

    seleccion_item=0;
}

Creditos::~Creditos()
{
    //dtor
}

void Creditos::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(fondo,states);

    for(int x=0; x<Item_text; x++)
    {
        target.draw(text[x],states);
    }

    for(int x=0; x<Item; x++)
    {
        target.draw(menu_C[x],states);
    }
}

void Creditos::left()
{
    if(seleccion_item-1>=0)
    {
        menu_C[seleccion_item].setColor(sf::Color(255,255,255,80));
        seleccion_item--;
        menu_C[seleccion_item].setColor(sf::Color::Green);
    }
}

void Creditos::right()
{
   if(seleccion_item+1<Item)
    {
        menu_C[seleccion_item].setColor(sf::Color(255,255,255,80));
        seleccion_item++;
        menu_C[seleccion_item].setColor(sf::Color::Green);
    }
}


void Creditos::Opciones()
{
    sf::RenderWindow window(sf::VideoMode(1220, 800), "Zombies vs PlantaZ");
    window.setFramerateLimit(60);

    // *******************Menu************************
    Creditos cred(window.getSize().x, window.getSize().y);
    MENU_PRINCIPAL menu_p(window.getSize().x, window.getSize().y);

    // ***********************************************


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
                case sf::Keyboard::Left:
                    cred.left();
                    break;
                case sf::Keyboard::Right:
                    cred.right();
                    break;
                case sf::Keyboard::Return:
                    switch (cred.GetPressedItem())
                    {
                    case 0:
                       std::cout << "Salir" << std::endl;
                        window.close();

                        break;
                    case 1:
                        std::cout << "Menu principal" << std::endl;
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




        window.draw(cred);




        window.display();
    }


}
