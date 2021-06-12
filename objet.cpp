#include "objet.hpp"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <SFML/Graphics.hpp>
using namespace std;

Objet::Objet(Room room, string filename)
{
        /* initialize random seed: */
    srand (time(NULL));

    cout << "Création de l'objet" << endl;
    this->w = 10;
    this->h = 10;
    this->x =  rand() % room.getW() + room.getX();
    this->y =  rand() % room.getH() + room.getY();
    this->nom = 'bonus';
    this->etat = 1;
    this->room=room;

    //Generation du sprite
    sf::Texture image;
    if(!image.loadFromFile("filename"))
    {
        throw std::runtime_error("impossible de charger image de l'objet bonus");
    }
    this->texture = image;
    sf::Sprite spriteImage;
        spriteImage.setTexture(this->texture);
    this->sprite = spriteImage;

    cout << "Fin de création l'objet" << endl;
}
Objet::~Objet() {}

void Objet::affichage(sf::RenderWindow& window)
{
    sprite.setPosition(this->x, this->y);
    window.draw(this->sprite);
}
