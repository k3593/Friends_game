#include "door.hpp"

using namespace std;

//Constructeur de Door
Door::Door(const int x, const int y, const int w, const int h, const string nom,const int ang, const int cot)
{
  this->x = x;
  this->y = y;
  this->w = w;
  this->h = h;
  this->angle = ang;
  this->cote = cot;
  this->nom = nom;
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
