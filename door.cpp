#include "door.hpp"

using namespace std;

//Constructeur Player
Door::Door(int x, int y, int w, int h, string nom)
{
  //declaration de la ligne de la porte
  int length = 20;
  sf::RectangleShape line;
  line.setSize(sf::Vector2f(length, 2));
  line.setOutlineColor(sf::Color::Red);
  line.setOutlineThickness(length/2);
  line.setPosition(x-5, y);
  line.setFillColor(sf::Color::Transparent);
  line.rotate(90);
  this->door = line;
}
