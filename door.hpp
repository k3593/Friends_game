#ifndef DOOR_HPP
#define DOOR_HPP

#include "gameElement.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class Door : public GameElement
{
  public:
    //constructeur
    Door(const int x,const int y,const int w, const int h, const string nom,const int ang, const int cot);

    //accesseur
    const sf::RectangleShape getDoor() const {return door;}
    int const getAngle() const {return angle;}
    int const getCote() const {return cote;}
  protected:
    sf::RectangleShape door;
    int angle = 0;
    // 0 = gauche, 1 = haut, 2 = droite, 3 = bas
    int cote = 0;
};

#endif
