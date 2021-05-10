#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "menu.hpp"
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "appartment.hpp"
using namespace std;

class Game
{
  public:
    Game();
    void menu();
    void play();
    void initFonts();
    void initText();
    void updateText();
  private:
    float windowHeight = 721;
    float windowWidht = 1109;
    Appartment appart{10, 10, 10, 10, "appart", "apartment.png"};
    sf::Image icone;
    sf::Text text;
    sf::Font MyFont;
};

#endif
