#ifndef DOOR_HPP
#define DOOR_HPP

#include "gameElement.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class Door : public GameElement
{
  public:
    Door(int x, int y, int w, int h, string nom, int ang, int cot);
    sf::RectangleShape getDoor() {return door;}
    int getAngle() {return angle;}
    int getCote() {return cote;}
  protected:
    sf::RectangleShape door;
    int angle = 0;
    // 0 = gauche, 1 = haut, 2 = droite, 3 = bas
    int cote = 0;
};

#endif
