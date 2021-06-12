#ifndef OBJET_HPP
#define OBJET_HPP

#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

#include "objet.hpp"
#include "gameElement.hpp"
#include "player.hpp"

using namespace std;

class Objet : public GameElement
{
  public:
  //constructeurs
    Objet(string name, string filename);
    Objet();
    ~Objet();
    //getters
    int getState() {return this->etat;}
    //fonction de l'objet
    void fonction(Player& player)=0;
    //affichage objet
    void affichage(sf::RenderWindow& window);
  protected:
    int etat;
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif
