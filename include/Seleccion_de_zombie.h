#ifndef SELECCION_DE_ZOMBIE_H
#define SELECCION_DE_ZOMBIE_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<iostream>
#include "Funciones.h"
#include "MENU_PRINCIPAL.h"
#include "Audio.h"
#include "SubMenu.h"
#include "ZOMBIE.h"


#define Item 5

class Seleccion_de_zombie: public sf::Drawable
{
public:
    Seleccion_de_zombie(float width, float height);
    //Seleccion_de_zombie();
    virtual ~Seleccion_de_zombie();
    void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
    void up();
    void down();
    int& GetPressedItem()
    {
        return _seleccionItem;
    }
    void Opciones();
    // Audio Sound_3e;

protected:

private:
    int _seleccionItem=0;
    sf::Font _fontItem;
    sf::Text _nombre_zombie[Item];
    sf::Sprite _sprite_Morty;
    sf::Texture _texture_Morty;
    sf::Sprite _sprite_Sally;
    sf::Texture _texture_Sally;
    sf::Sprite _sprite_Igor;
    sf::Texture _texture_Igor;
    sf::Sprite _sprite_fondo;
    sf::Texture _texture_fondo;



};

#endif // SELECCION_DE_ZOMBIE_H
