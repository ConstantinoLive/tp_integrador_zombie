#include "Lifebar.h"

Lifebar::Lifebar()
{
    _life_points=5;     //Dado por el sprite, ya que es de 5 puntos posibles. Podria, eventualmente, hacer que cada disparo quite 0.5 de daño
    initTexture();
    _life_bar_sprite.setPosition(0.f,700.f);
}

Lifebar::~Lifebar()
{
    //dtor
}

void Lifebar::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_life_bar_sprite,states);
}

void Lifebar::initTexture()
{
    _life_bar_texture.loadFromFile("img/Lifegood.png");
    _life_bar_sprite.setTexture(_life_bar_texture);
    _current_frame=sf::IntRect(0,0,433,116);
    _life_bar_sprite.setTextureRect(_current_frame);
}

int Lifebar::getLifePoints() const
{
    return _life_points;
}

void Lifebar::setLifePoints(int points)
{
    _life_points=points;
}

void Lifebar::update()
{
    switch(_life_points)
    {
        case 5:
            _current_frame=sf::IntRect(0,0,433,116);
            break;
        case 4:
            _current_frame=sf::IntRect(0,116,433,116);
            break;
        case 3:
            _current_frame=sf::IntRect(0,232,433,116);
            break;
        case 2:
            _current_frame=sf::IntRect(0,348,433,116);
            break;
        case 1:
            _current_frame=sf::IntRect(0,464,433,116);
            break;
        case 0:
            _current_frame=sf::IntRect(0,580,433,116);
            break;
        default:
            _current_frame=sf::IntRect(0,580,433,116);
            break;
    }
    _life_bar_sprite.setTextureRect(_current_frame);
    _life_bar_sprite.setScale(0.5,0.5);
    _life_bar_sprite.setPosition(0.f,600.f);
}
