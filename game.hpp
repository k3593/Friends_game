#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "menu.hpp"
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "appartment.hpp"
using namespace std;

class Game
{
  public:
    Game();
    void menu();
    void play();
    void popUp(string titre, string image);
    void initFonts();
    void initText();
    void initChrono();
    void updateText();
    void updateChrono(sf::Clock chrono);
  private:
    sf::Music music;
    sf::Music music_joey;
    float windowHeight = 721;
    float windowWidht = 1109;
    Appartment appart{10, 10, 10, 10, "appart", "apartment.jpeg"};
    sf::Image icone;
    sf::Text text;
    sf::Text time;
    sf::Font MyFont;
    sf::Texture texturePU;
    sf::Sprite spritePU;
};

#endif
