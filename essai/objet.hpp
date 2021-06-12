#ifndef OBJET_HPP
#define OBJET_HPP

#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

#include "objet.hpp"
#include "gameElement.hpp"

using namespace std;

class Objet : public GameElement
{
  public:
  //constructeurs
    Objet(string name, string filename, int x, int y);
    Objet();
    ~Objet();
    //getters
    int getScore() {return this->score;}
    sf::Sprite getObjetAff() {return sprite;}

  protected:
    sf::Texture texture;
    sf::Sprite sprite;
    int score = 0;
};

#endif
