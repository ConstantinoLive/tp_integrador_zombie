#ifndef SELECCION_DE_ZOMBIE_H
#define SELECCION_DE_ZOMBIE_H

#include <SFML/Graphics.hpp>

#define Item 4

class Seleccion_de_zombie: public sf::Drawable
{
public:
    Seleccion_de_zombie(float width, float height);
    Seleccion_de_zombie();
    virtual ~Seleccion_de_zombie();
    void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
    void up();
    void down();
    int GetPressedItem()
    {
        return _seleccionItem;
    }
    void Opciones();

protected:

private:
    int _seleccionItem;
    sf::Font _fontItem;
    sf::Text _nombre_zombie[Item];
    sf::Sprite _sprite_Morty;
    sf::Texture _texture_Morty;
    sf::Sprite _sprite_Sally;
    sf::Texture _texture_Sally;
    sf::Sprite _sprite_fondo;
    sf::Texture _texture_fondo;


};

#endif // SELECCION_DE_ZOMBIE_H
