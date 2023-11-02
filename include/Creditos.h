#ifndef CREDITOS_H
#define CREDITOS_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "MENU_PRINCIPAL.h"

#define Item 2
#define Item_text 6

class Creditos: public sf::Drawable
{
public:
    Creditos(float width, float height);
    virtual ~Creditos();
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
    sf::Font font_text;
    sf::Text menu_C[Item];
    sf::Sprite fondo;
    sf::Texture _fondo;
    sf::Text text[Item_text];




};

#endif // CREDITOS_H




