#include "Menu_winer.h"

Menu_winer::Menu_winer(float width, float height)
{
    _nombrePlayer=getNombre();
    /* _scorePlayer=n;
    _puntos=n;*/
    if (!_fondo.loadFromFile("img/background_subMenu.png"))
    {
        std::cout << "Error al cargar la textura del fondo" << std::endl;
        return;
    }
    fondo.setTexture(_fondo);
    fondo.scale(1.36,1.25);
    if (!font_item.loadFromFile("font/Come With Us.ttf"))
    {
        std::cout<<"Error al cargar texto"<<std::endl;
    }

    if (!_datos.loadFromFile("font/TT Interphases Pro Trial Black.ttf"))
    {
        std::cout<<"Error al cargar texto"<<std::endl;
    }

    _win.setFont(font_item);
    _win.setString("WINER!!!");
    _win.setColor(sf::Color(255,255,255,80));
    _win.setCharacterSize(150);
    _win.setPosition(sf::Vector2f(420,80));

    menu_win[0].setFont(font_item);
    menu_win[0].setFillColor(sf::Color::Green);
    menu_win[0].setString("SALIR");
    menu_win[0].setCharacterSize(20);
    menu_win[0].setPosition(300,685);

    menu_win[1].setFont(font_item);
    menu_win[1].setFillColor(sf::Color(255,255,255,80));
    menu_win[1].setString("VOLVER AL MENU PRINCIPAL");
    menu_win[1].setCharacterSize(20);
    menu_win[1].setPosition(813,685);

    _name.setFont(_datos);
    _name.setFillColor(sf::Color(255,255,255,180));
    _name.setString(_nombrePlayer);
    _name.setCharacterSize(40);
    _name.setPosition(150,350);

   /* _score.setFont(_datos);
    _score.setFillColor(sf::Color(255,255,255,180));
    _score.setString(_scorePlayer);
    _score.setCharacterSize(40);
    _score.setPosition(500,350);*/

    seleccion_item=0;

}

Menu_winer::~Menu_winer()
{
    //dtor
}

void Menu_winer::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(fondo,states);
    target.draw(_win,states);
    target.draw(_name,states);
   // target.draw(_score,states);
    for(int x=0; x<Item; x++)
    {
        target.draw(menu_win[x],states);
    }
}

void Menu_winer::left()
{

    if(seleccion_item-1>=0)
    {
        menu_win[seleccion_item].setColor(sf::Color(255,255,255,80));
        seleccion_item--;

        menu_win[seleccion_item].setColor(sf::Color::Green);
    }
}

void Menu_winer::right()
{

    if(seleccion_item+1<Item)
    {
        menu_win[seleccion_item].setColor(sf::Color(255,255,255,80));
        seleccion_item++;

        menu_win[seleccion_item].setColor(sf::Color::Green);
    }
}

void Menu_winer::Opciones()
{
    sf::RenderWindow window(sf::VideoMode(1220, 800), "Zombies vs PlantaZ");
    window.setFramerateLimit(60);

    // *******************Menu************************
    Menu_winer mwn(window.getSize().x, window.getSize().y);
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
                    mwn.left();
                    break;
                case sf::Keyboard::Right:
                    mwn.right();
                    break;
                case sf::Keyboard::Return:
                    switch (mwn.GetPressedItem())
                    {
                    case 0:
                        std::cout << "Salir" << std::endl;
                        Sound_3d.audioOFF();
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


        window.draw(mwn);


        window.display();
    }


}

