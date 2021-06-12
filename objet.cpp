#include "objet.hpp"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <SFML/Graphics.hpp>
using namespace std;

Objet::Objet(string name, string filename)
{
        /* initialize random seed: */
    srand (time(NULL));

    cout << "Création de l'objet" << endl;
    this->w = 10;
    this->h = 10;
    this->nom = name;
    this->etat = 1;

    //Generation du sprite
    sf::Texture image;
    if(!image.loadFromFile(filename))
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
