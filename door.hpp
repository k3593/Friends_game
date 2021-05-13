#ifndef DOOR_HPP
#define DOOR_HPP

#include "gameElement.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class Door : public GameElement
{
  public:
    Door(int x, int y, int w, int h, string nom);
    sf::RectangleShape getDoor() {return door;}
  private:
    sf::RectangleShape door;
};

#endif
