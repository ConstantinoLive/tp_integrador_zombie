#ifndef MENU_GAME_OVER_H
#define MENU_GAME_OVER_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Audio.h"
#include "MENU_PRINCIPAL.h"

#define Item 2

class Menu_game_over: public sf::Drawable
{
public:
    Menu_game_over(float width, float height);
    virtual ~Menu_game_over();
    void draw(sf::RenderTarget&target,sf::RenderStates states)const override;
    void left();
    void right();
    int GetPressedItem()
    {
        return seleccion_item;
    }
    void Opciones();
   // Audio Sound_3d;

protected:

private:
    int seleccion_item;
    sf::Font font_item;
    sf::Text menu_GO[Item];
    sf::Sprite fondo;
    sf::Texture _fondo;
    sf::Text GO;




};

#endif // MENU_GAME_OVER_H


