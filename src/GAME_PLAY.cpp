#include "GAME_PLAY.h"
#include <iostream>

#include <SFML/Graphics.hpp>

GAME_PLAY::GAME_PLAY()
{
    _estado=ESTADOS_GAME_PLAY::ACTION;


    //1er nivel plats

    Plats[0].getDraw().setPosition(250,400);
    Plats[1].getDraw().setPosition(310,400);
    Plats[2].getDraw().setPosition(500,400);
    Plats[3].getDraw().setPosition(560,400);
    Plats[4].getDraw().setPosition(750,400);
    Plats[5].getDraw().setPosition(810,400);
    Plats[6].getDraw().setPosition(870,400);

    //2do nivel plats

    Plats[7].getDraw().setPosition(190,270);    //1era
    Plats[8].getDraw().setPosition(370,270);    //2da
    Plats[9].getDraw().setPosition(430,270);    //2da
    Plats[10].getDraw().setPosition(680,270);   //3ra
    Plats[11].getDraw().setPosition(740,270);   //3ra
    Plats[12].getDraw().setPosition(750,270);   //3ra
    Plats[13].getDraw().setPosition(900,270);   //4ta
    Plats[14].getDraw().setPosition(1040,270);  //5ta
    Plats[15].getDraw().setPosition(1100,270);  //5ta
    Plats[16].getDraw().setPosition(1160,270);  //5ta


    //3er nivel plats

    Plats[17].getDraw().setPosition(0,140);     //1era
    Plats[18].getDraw().setPosition(60,140);    //1era
    Plats[19].getDraw().setPosition(120,140);   //1era
    Plats[20].getDraw().setPosition(300,140);   //2da
    Plats[21].getDraw().setPosition(360,140);   //2da
    Plats[22].getDraw().setPosition(420,140);   //2da
    Plats[23].getDraw().setPosition(700,140);   //3ra
    Plats[24].getDraw().setPosition(760,140);   //3ra
    Plats[25].getDraw().setPosition(820,140);   //3ra
    Plats[26].getDraw().setPosition(880,140);   //3ra
    Plats[27].getDraw().setPosition(1040,140);  //4ta
    Plats[28].getDraw().setPosition(1100,140);  //4ta
    Plats[29].getDraw().setPosition(1160,140);  //4ta



    /*
    _array_plantas.push_back(new Planta(SUPER_GREEN,{400,500},LEFT,_shoot_manager));    //prueba posicion
    _array_plantas.push_back(new Planta(GREEN,{800,500},RIGHT,_shoot_manager));         //prueba posicion
    _array_plantas.push_back(new Planta(ICE,{400,200},LEFT,_shoot_manager));            //prueba posicion
    _array_plantas.push_back(new Planta(FIRE,{800,200},RIGHT,_shoot_manager));          //prueba posicion
    */
    _prize_timer.restart(); //inicializo el timer de premio
    _prize_generated=false;

    _is_dead=false;

    //inicio los valores aleatorios del generador y mezclo el vector de posiciones
    std::mt19937 g(rand());

    std::shuffle(_position.begin(), _position.end(), g);

    _plant_spawn_timer.restart();

}

GAME_PLAY::~GAME_PLAY()
{
    //dtor
}

void GAME_PLAY::draw(sf::RenderWindow& window)
{
    window.draw(Z1.getDraw());

    for(auto p : _plant_manager._array_plantas)
    {
        window.draw(*p);
    }
    /*
    for(auto plant : _array_plantas)
    {
        window.draw(*plant);
    }*/

    for(auto disparo : _shoot_manager._array_disparos)
    {
        window.draw(*disparo);
    }

    for(PLATAFORMA& Plat_1: Plats)
    {
        window.draw(Plat_1.getDraw());
    }

    if(_prize_generated)
        window.draw(*_prize);


    window.draw(_life_bar);

    window.draw(_text_pause);

}


void GAME_PLAY::cmd()
{
    if(_estado==ESTADOS_GAME_PLAY::ACTION)//SE EJECUTA SI EL JUEGO NO ESTÁ EN PAUSA
    {
        Z1.mobility();

        for(auto Plat_1: Plats)
        {
            Plat_1.mobility();
        }


        //...........comandos para poner en pausa el juego......

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        {
            _estado=ESTADOS_GAME_PLAY::PAUSE;

            if (!_font_pause.loadFromFile("font/Lethal Slime.ttf"))
            {
                std::cout<<"Error al cargar texto"<<std::endl;
            }
            std::cout<<"Pausa"<<std::endl;
            _text_pause.setFont(_font_pause);
            _text_pause.setString("PAUSA");
            _text_pause.setColor(sf::Color::Red);
            _text_pause.setPosition(488,228.50);

        }
    }
    else
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        {
            _estado=ESTADOS_GAME_PLAY::ACTION;
        }
    }
}
/////////////////////////////
void GAME_PLAY::check_collision_platform()
{

    for(PLATAFORMA& Plat_1: Plats)
    {
        if(Z1.getDraw().getGlobalBounds().intersects(Plat_1.getDraw().getGlobalBounds()) && Z1.getjump_force()<0)
        {
            //std::cout<<"Colision"<<std::endl;
            Z1.suelo(Z1.getDraw().getPosition().x,Plat_1.getDraw().getGlobalBounds().top-80); //80 es la altura del Sprite
        }
    }
}
///////////////////////////////////////
void GAME_PLAY::updatePlants()
{
    for(auto it=_array_plantas.begin(); it!=_array_plantas.end();)   //inicio el iterador IT en el principio del array y recorro hasta el final de array
    {
        Planta* planta = *it;       //defino el puntero a PLANTA llamado planta y apunta igual que IT, sera el objeto a actualizar y/o borrar
        planta->update();
        //chequeo colision zombie-planta
        if(Z1.isCollision(*planta))
        {
            _life_bar.setLifePoints(_life_bar.getLifePoints() - 1);

            delete planta;                  //libera memoria del objeto planta, pero ojo! el puntero planta aun tiene la direccion
                                            //de memoria del objeto eliminado, es decir, el objeto esta en la lista pero no es valido.
            it=_array_plantas.erase(it);    //con esto elimino completamente de la lista y el iterador IT queda apuntando al siguiente elemento

        }
        else
        {
            ++it;                           //Si no se elimina el enemigo, avanza al siguiente elemento
        }
    }
}

///////////////////////////////////////

void GAME_PLAY::updateShootAndLife(sf::RenderTarget& window)
{
    for(auto it=_shoot_manager._array_disparos.begin();it!=_shoot_manager._array_disparos.end();)
    {
        Disparo* disp = *it;
        disp->update();
        if(Z1.isCollision(*disp) || disp->checkWindowBounds(window))        //Para borrar el disparo, pregunto si el zombie lo toca o si sale fuera de pantalla
        {
            if(Z1.isCollision(*disp))
            {
                _life_bar.setLifePoints(_life_bar.getLifePoints() - 1);
            }

            delete disp;

            it=_shoot_manager._array_disparos.erase(it);
        }
        else
        {
            ++it;
        }
    }

    //validacion de lifebar
    if(_life_bar.getLifePoints()>5)
    {
        _life_bar.setLifePoints(5);
    }
    else if(_life_bar.getLifePoints() <= 0)
    {
        _life_bar.setLifePoints(0);
        _is_dead=true;  //se quedo sin puntos de vida
    }
}


///////////////////////////////////////

void GAME_PLAY::updatePrize()
{

    if(!_prize_generated)   //pregunto y entro si no hay premio generado
    {
        if(_prize_timer.getElapsedTime().asSeconds() >= 5) //pregunto si llego al tiempo de spawn de premio
        {
            _prize= new Prize((sf::Vector2f)getRandomPosition());     //Prueba posicion!!!
            _prize_generated=true;
            _prize_timer.restart();
        }
    }
    else                    //se genero un premio
    {
        if(Z1.isCollision(*_prize) || _prize_timer.getElapsedTime().asSeconds() >= 10)
        {
            if(Z1.isCollision(*_prize))
            {
                _life_bar.setLifePoints(_life_bar.getLifePoints() + 1);
            }
            _prize_generated=false;
            _prize_timer.restart();
            delete _prize;
        }
    }
}

//////////////////////////////////

void GAME_PLAY::update(sf::RenderTarget& window)
{
    if(_estado==ESTADOS_GAME_PLAY::ACTION) //SE EJECUTA SI EL JUEGO NO ESTÁ EN PAUSA
    {
        Z1.update();

        updatePrize();

        _life_bar.update();

        updatePlants2();

        updateShootAndLife(window);


        if(Z1.getDraw().getPosition().y>485) //Suelo... limite de caida
        {
            Z1.suelo(Z1.getDraw().getPosition().x,485);
        }

        for(PLATAFORMA& Plat_1: Plats)      //Recorro las plataformas ya creadas y no hago copias
        {
            Plat_1.update();
        }


        check_collision_platform();

    }
}

void GAME_PLAY::updatePlants2()
{
    updatePlantGeneration();
    updatePlantDeletion();
}

void GAME_PLAY::updatePlantGeneration()
{
    ///GENERACION DE PLANTAS
    _random_type=TIPO(rand() % 4);   //Genero un tipo aleatorio, casteo a TIPO
    bool look=rand()% 2;

    if(_plant_manager._array_plantas.size() <= 4)   //spawneo maximo 4 plantas
    {
        if(_plant_spawn_timer.getElapsedTime().asSeconds() >= 3)    //spawneo cada 3 seg
        {
            _plant_manager.agregarPlanta(new Planta(_random_type,getRandomPosition(),look,_shoot_manager));
            _plant_spawn_timer.restart();
        }
    }
}

void GAME_PLAY::updatePlantDeletion()
{
    ///DELETEO DE PLANTAS
    ////recorro el array de plantas del gestor y deleteo plantas si corresponde////
    for(auto it=_plant_manager._array_plantas.begin(); it!=_plant_manager._array_plantas.end();)   //inicio el iterador IT en el principio del array y recorro hasta el final de array
    {
        Planta* planta = *it;       //defino el puntero a PLANTA llamado planta y apunta igual que IT, sera el objeto a actualizar y/o borrar
        planta->update();
        //chequeo colision zombie-planta
        if(Z1.isCollision(*planta))
        {
            _life_bar.setLifePoints(_life_bar.getLifePoints() - 1);

            delete planta;                  //libera memoria del objeto planta, pero ojo! el puntero planta aun tiene la direccion
                                            //de memoria del objeto eliminado, es decir, el objeto esta en la lista pero no es valido.
            _plant_spawn_timer.restart();           //Tanto para la generacion como para el deleteo de plantas, reseteo el timer
            it=_plant_manager._array_plantas.erase(it);    //con esto elimino completamente de la lista y el iterador IT queda apuntando al siguiente elemento
        }
        else
        {
            ++it;                           //Si no se elimina el enemigo, avanza al siguiente elemento
        }
    }
}


sf::Vector2i GAME_PLAY::getRandomPosition()
{
    sf::Vector2i pos = _position.back();             //elemento que me interesa, el ultimo elemento del vector
    _position.insert(_position.begin(),pos);         //pongo al principio del vector el elemento que me interesa
    _position.pop_back();                            //saco el ultimo elemento del array
    return pos;
}

