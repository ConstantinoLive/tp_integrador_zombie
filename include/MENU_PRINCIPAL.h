#ifndef MENU_PRINCIPAL_H
#define MENU_PRINCIPAL_H

#include <SFML/Graphics.hpp>
#include "SubMenu.h"
#include<iostream>
#include "Creditos.h"

#define Item 5


class MENU_PRINCIPAL: public sf::Drawable
{
public:
    MENU_PRINCIPAL(float width, float height);
    virtual ~MENU_PRINCIPAL();

    void draw(sf::RenderTarget&target,sf::RenderStates states)const override;
    void up();
    void down();
    int GetPressedItem()
    {
        return seleccion_item;
    }
     void Opciones();

protected:

private:
    int seleccion_item;
    sf::Font font_item;
    sf::Text menu_p[Item];
    sf::Sprite _fondo_menu;
    sf::Texture _texture_menu;
};

#endif // MENU_PRINCIPAL_H
