#include "GAME_PLAY.h"
#include <iostream>

GAME_PLAY::GAME_PLAY() :selec_zom(1220,800), Z1(getZombie(),_shoot_manager), Sound_4(4), Sound_5(5), Sound_7(7)//: Z1(_shoot_manager)
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




    /*_array_plantas.push_back(new Planta(SUPER_GREEN, {400,500},LEFT,_shoot_manager));  //prueba posicion
    _array_plantas.push_back(new Planta(GREEN, {800,500},RIGHT,_shoot_manager));  //prueba posicion
    _array_plantas.push_back(new Planta(ICE, {400,200},LEFT,_shoot_manager));  //prueba posicion
    _array_plantas.push_back(new Planta(FIRE, {800,200},RIGHT,_shoot_manager));  //prueba posicion*/

    _prize_timer.restart(); //inicializo el timer de premio
    _prize_generated=false;

    //inicio los valores aleatorios del generador y mezclo el vector de posiciones
    std::mt19937 g(rand());

    std::shuffle(_position.begin(), _position.end(), g);

    _plant_spawn_timer.restart();


    _is_dead=false;
    disparoZombie = new Disparo(TIPO::BRAIN, {400,400}, false);

    /*****************NOMBRE DE JUGADOR   **************/
    _namePlayer = getNombre();
    if (!_fontPlayer.loadFromFile("font/BITWA___.ttf"))
    {
        std::cout<<"Error al cargar texto"<<std::endl;
    }
    std::cout<<_namePlayer<<std::endl;
    _textPlayer.setFont(_fontPlayer);
    _textPlayer.setString(_namePlayer);
    _textPlayer.setColor(sf::Color::Red);
    _textPlayer.setPosition(400,710);
    /*****************PUNTAJE**************************/
    puntaje = 0 ;
    if (!_fontPuntaje.loadFromFile("font/BITWA___.ttf"))
    {
        std::cout<<"Error al cargar texto"<<std::endl;
    }
    std::cout<<puntaje<<std::endl;
    _textPuntaje.setFont(_fontPuntaje);
    _textPuntaje.setString(std::to_string(puntaje));
    _textPuntaje.setColor(sf::Color::Red);
    _textPuntaje.setPosition(500,740);

    /*********************Vidas*****************/

    _textvidas.setFont(_fontPlayer);
    _textvidas.setString("Vidas");
    _textvidas.setColor(sf::Color::Red);
    _textvidas.setPosition(930,710);
    /*****************vidas**************************/

    _cantvidas.setFont(_fontPuntaje);
    //_cantvidas.setString(std::to_string(vidas));
    _cantvidas.setColor(sf::Color::Red);
    _cantvidas.setPosition(940,740);


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

    /*for(auto plant : _array_plantas)
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
    {
        window.draw(*_prize);
    }





    window.draw(_life_bar);
    window.draw(_energy_bar);
    window.draw(_text_pause);

    window.draw(_textPlayer);
    window.draw(_textPuntaje);
    window.draw(_textvidas);
    window.draw(_cantvidas);


}


void GAME_PLAY::cmd()
{

    if(_estado==ESTADOS_GAME_PLAY::ACTION)//SE EJECUTA SI EL JUEGO NO ESTÁ EN PAUSA
    {
        Z1.mobility();

        /*for(auto it=_plant_manager._array_plantas.begin(); it!=_plant_manager._array_plantas.end();)   //inicio el iterador IT en el principio del array y recorro hasta el final de array
        {
            Planta* planta = *it;       //defino el puntero a PLANTA llamado planta y apunta igual que IT, sera el objeto a actualizar y/o borrar
            planta->update();


            for(auto Plat_1: Plats)
            {
                if(Plat_1->)
                {
                    std::cout<<"colision"<<std::endl;
                }
            }
        }*/




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
            _text_pause.setString("             ");
            _text_pause.setPosition(480,228.50);
        }
    }
}
/////////////////////////////
void GAME_PLAY::check_collision_platform()
{

    for(auto Plat_1: Plats)
    {
        if(Z1.getDraw().getGlobalBounds().intersects(Plat_1.getDraw().getGlobalBounds())&&Z1.getjump_force()<0)
        {
            if(numeroZombie==0||numeroZombie==1)
            {
                Z1.suelo(Z1.getDraw().getPosition().x,Plat_1.getDraw().getGlobalBounds().top-80); //80 es la altura del Sprite
            }
            else if(numeroZombie==2)
            {
                Z1.suelo(Z1.getDraw().getPosition().x,Plat_1.getDraw().getGlobalBounds().top-70);
            }
        }

    }

}
///////////////////////////////////////
/*void GAME_PLAY::updatePlants()
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
}*/

///////////////////////////////////////

void GAME_PLAY::updateShootAndLife(sf::RenderTarget& window)
{

    for(auto it=_shoot_manager._array_disparos.begin(); it!=_shoot_manager._array_disparos.end();)
    {
        Disparo* disp = *it;
        tipoDisparo = disp->getTipo(); // con esto le asignamos el tipo de disparo a la variable para poder validar las colisiones
        disp->update();


        //Para borrar el disparo, pregunto si el zombie lo toca o si sale fuera de pantalla
        if(Z1.isCollision(*disp)&& tipoDisparo !=TIPO::BRAIN || disp->checkWindowBounds(window))
        {
            if(Z1.isCollision(*disp)&& tipoDisparo != TIPO::BRAIN)
            {
                _life_bar.setLifePoints(_life_bar.getLifePoints() - 1);
                Sound_5.audioON();
            }

            delete disp;

            it=_shoot_manager._array_disparos.erase(it);
        }
        else
        {
            ++it;
        }
        //validacion de lifebar
        if(_life_bar.getLifePoints()>5)
        {
            _life_bar.setLifePoints(5);
        }
        else if(_life_bar.getLifePoints() <= 0)
        {
            _life_bar.setLifePoints(0);

            //_is_dead=true;  //se quedo sin puntos de vida
        }
    }
    for(auto it=_plant_manager._array_plantas.begin(); it!=_plant_manager._array_plantas.end();)
    {
        Planta* planta = *it;
        planta->update();
        colisionPlanta = false;
        for(auto itDisparo = _shoot_manager._array_disparos.begin(); itDisparo != _shoot_manager._array_disparos.end();)
        {
            Disparo* disp = *itDisparo;
            disp->update();

            tipoDisparo = disp->getTipo();
            if(disp->isCollision(*planta)&& tipoDisparo==TIPO::BRAIN)
            {
                colisionPlanta = true;
                puntaje += 45;
                itDisparo = _shoot_manager._array_disparos.erase(itDisparo);
                delete disp;
            }
            else
            {
                itDisparo++;
            }
        }
        if(colisionPlanta)
        {
            Sound_7.audioON();
            it =_plant_manager._array_plantas.erase(it);
            delete planta;
        }
        else
        {
            it++;
        }
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
                puntaje+=500;
                Sound_4.audioON();
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
    if(_game_over==false)
    {
        if(_estado==ESTADOS_GAME_PLAY::ACTION) //SE EJECUTA SI EL JUEGO NO ESTÁ EN PAUSA
        {

            if(_is_dead==false&&_dead.getElapsedTime().asSeconds()>0.01)
            {
                if(_life_bar.getLifePoints()<=5&&_life_bar.getLifePoints()>=1)
                {
                    //std::cout<<_life_bar.getLifePoints()<<std::endl;
                    Z1.update();
                    //std::cout<<Z1.getvida()<<std::endl;

                }
                else
                {
                    if(_is_dead==false)
                    {
                        _dead.restart();
                    }
                    if(_life_bar.getLifePoints()==0&&_dead.getElapsedTime().asSeconds()<1.5)
                    {
                        //std::cout<<_life_bar.getLifePoints()<<std::endl;
                        Z1.update_muriendo();
                        _is_dead=true;

                    }

                    if(_is_dead==true&&_dead.getElapsedTime().asSeconds()>1.5)
                    {

                        _dead.restart();
                        // Z1.setvida(1);
                        //std::cout<<Z1.getvida()<<std::endl;
                    }
                }

            }
            if(_is_dead==true&&_life_bar.getLifePoints()==0&&_dead.getElapsedTime().asSeconds()>1.5)
            {
                _is_dead=false;
                _life_bar.setLifePoints(5);
                _dead.restart();

            }
            if(Z1.getvida()>=1)
            {
                vidas=Z1.getvida();
                _game_over=false;

            }
            else
            {
                vidas=Z1.getvida();
                _game_over=true;

            }

            updatePrize();

            _life_bar.update();

            //std::cout<<Z1.gettimeshoot()<<std::endl;
            if(Z1.gettimeshoot() > 2.0)
            {
                _energy_bar.setEnergyPoints(5);

            }
            else
            {
                if(Z1.gettimeshoot()>= 0.0&&Z1.gettimeshoot()< 0.4)
                {
                    _energy_bar.setEnergyPoints(0);
                }
                else
                {
                    if(Z1.gettimeshoot()> 0.4&&Z1.gettimeshoot()< 0.8)
                    {
                        _energy_bar.setEnergyPoints(1);
                    }
                    else
                    {
                        if(Z1.gettimeshoot() > 0.8&&Z1.gettimeshoot()< 1.2)
                        {
                            _energy_bar.setEnergyPoints(2);
                        }
                        else
                        {
                            if(Z1.gettimeshoot() > 1.2&&Z1.gettimeshoot()< 1.6)
                            {
                                _energy_bar.setEnergyPoints(3);
                            }
                            else
                            {
                                if(Z1.gettimeshoot() > 1.6&&Z1.gettimeshoot()< 2.0)
                                {
                                    _energy_bar.setEnergyPoints(4);
                                }
                            }
                        }
                    }
                }
            }
            _energy_bar.update();
            // updatePlants();
            updatePlants2();

            updateShootAndLife(window);

            _textPuntaje.setString(std::to_string(puntaje));
            _cantvidas.setString(std::to_string(vidas));

            if(Z1.getDraw().getPosition().y>490) //485 Suelo... limite de caida
            {
                Z1.suelo(Z1.getDraw().getPosition().x,490);
            }

            for(PLATAFORMA& Plat_1: Plats)      //Recorro las plataformas ya creadas y no hago copias
            {
                Plat_1.update();
            }

            check_collision_platform();
        }
    }
    else
    {
        std::cout<<"GAME OVER!!!"<<std::endl;
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
        if(_plant_spawn_timer.getElapsedTime().asSeconds() >= 1.5)    //spawneo cada 3 seg
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
            Sound_5.audioON();

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

