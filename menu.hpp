#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>

using namespace std;

class Menu
{
public:
  Menu(float width, float height);

  void draw(sf::RenderWindow &window);
  void goUp();
  void goDown();

private:
  int index;
  sf::Font font;
  sf::Text text[3];
};

#endif
