#include "Menu_game_over.h"

Menu_game_over::Menu_game_over(float width, float height)
{
    if (!_fondo.loadFromFile("img/mano_zombie.jpg"))
    {
        std::cout << "Error al cargar la textura del fondo" << std::endl;
        return;
    }
    fondo.setTexture(_fondo);
    fondo.scale(0.23,0.2);
    if (!font_item.loadFromFile("font/Come With Us.ttf"))
    {
         std::cout<<"Error al cargar texto"<<std::endl;
    }

    GO.setFont(font_item);
    GO.setString("GAME    OVER");
    GO.setColor(sf::Color(255,255,255,80));
    GO.setCharacterSize(150);
    GO.setPosition(sf::Vector2f(150,400));

    menu_GO[0].setFont(font_item);
    menu_GO[0].setFillColor(sf::Color::Green);
    menu_GO[0].setString("SALIR");
    menu_GO[0].setCharacterSize(20);
    menu_GO[0].setPosition(300,685);

    menu_GO[1].setFont(font_item);
    menu_GO[1].setFillColor(sf::Color(255,255,255,80));
    menu_GO[1].setString("VOLVER AL MENU PRINCIPAL");
    menu_GO[1].setCharacterSize(20);
    menu_GO[1].setPosition(813,685);



    seleccion_item=0;

}

Menu_game_over::~Menu_game_over()
{
    //dtor
}




void Menu_game_over::draw(sf::RenderTarget& target, sf::RenderStates states)const
{

    target.draw(fondo,states);
    target.draw(GO,states);
    for(int x=0; x<Item; x++)
    {
        target.draw(menu_GO[x],states);
    }

}

void Menu_game_over::left()
{

    if(seleccion_item-1>=0)
    {
        menu_GO[seleccion_item].setColor(sf::Color(255,255,255,80));
        seleccion_item--;

        menu_GO[seleccion_item].setColor(sf::Color::Green);
    }
}

void Menu_game_over::right()
{

    if(seleccion_item+1<Item)
    {
        menu_GO[seleccion_item].setColor(sf::Color(255,255,255,80));
        seleccion_item++;

        menu_GO[seleccion_item].setColor(sf::Color::Green);
    }
}

void Menu_game_over::Opciones()
{
    sf::RenderWindow window(sf::VideoMode(1220, 800), "Zombies vs PlantaZ");
    window.setFramerateLimit(60);

    // *******************Menu************************
    Menu_game_over mgo(window.getSize().x, window.getSize().y);
    MENU_PRINCIPAL menu_p(window.getSize().x, window.getSize().y);
Audio Sound_3d(3);
    // ***********************************************

 Sound_3d.audioON();
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

                    mgo.left();
                    break;
                case sf::Keyboard::Right:

                    mgo.right();
                    break;
                case sf::Keyboard::Return:
                    switch (mgo.GetPressedItem())
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




        window.draw(mgo);




        window.display();
    }


}
