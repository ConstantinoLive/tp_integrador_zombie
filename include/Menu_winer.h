#ifndef MENU_WINER_H
#define MENU_WINER_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "MENU_PRINCIPAL.h"



#define Item 2

class Menu_winer: public sf::Drawable
{
public:
    Menu_winer(float width, float height);
    virtual ~Menu_winer();
    void draw(sf::RenderTarget&target,sf::RenderStates states)const override;
    void left();
    void right();
    int GetPressedItem()
    {
        return seleccion_item;
    }
    void Opciones();

protected:

private:
    int seleccion_item;
    sf::Font font_item;
    sf::Font _datos;
    sf::Text menu_win[Item];
    sf::Sprite fondo;
    sf::Texture _fondo;
    sf::Text _win;
    sf::Text _name;
    sf::Text _score;
    std::string _namePlayer;
    //std::string _scorePlayer;
   // int _puntos;


};

#endif // MENU_WINER_H
