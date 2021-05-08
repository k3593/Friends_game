#include "menu.hpp"

Menu::Menu(float width, float height)
{
  if(!font.loadFromFile("arial.ttf"))
  {
    throw std::runtime_error("impossible de charger la police");
  }
  text[0].setFont(font);
  text[0].setColor(sf::Color::Red);
  text[0].setString("Play");
  text[0].setPosition(sf::Vector2f(width/2, height/4*1));

  text[1].setFont(font);
  text[1].setColor(sf::Color::White);
  text[1].setString("Options");
  text[1].setPosition(sf::Vector2f(width/2, height/4*2));

  text[2].setFont(font);
  text[2].setColor(sf::Color::White);
  text[2].setString("Exit");
  text[2].setPosition(sf::Vector2f(width/2, height/4*3));
}

void Menu::draw(sf::RenderWindow &window)
{
  for(int i=0; i<3; i++)
  {
    window.draw(text[i]);
  }
}
