#include "door.hpp"

using namespace std;

//Constructeur Player
Door::Door(int x, int y, int w, int h, string nom, int ang, int cot)
{
  this->x = x;
  this->y = y;
  this->w = w;
  this->angle = ang;
  this->cote = cot;
  //declaration de la ligne de la porte
  int length = w;
  sf::RectangleShape line;
  line.setSize(sf::Vector2f(length, 2));
  line.setOutlineColor(sf::Color::Red);
  line.setOutlineThickness(2);
  line.setPosition(x-5, y);
  line.setFillColor(sf::Color::Transparent);
  line.rotate(angle);
  this->door = line;
}
