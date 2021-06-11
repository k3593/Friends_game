#ifndef GAMEELEMENT_HPP
#define GAMEELEMENT_HPP

#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;

class GameElement
{
  public:
    //constructeurs
    GameElement() {}
    virtual ~GameElement() = 0;
    int getX() {return this->x;}
    int getY() {return this->y;}
    int getW() {return this->w;}
    int getH() {return this->h;}
    string getName() {return this->nom;}

  protected:
    int x; //Coordonnées x de l'origine
    int y; //Coordonnées y de l'origine
    int w; //largeur de l'élément
    int h; //hauteur de l'élément
    string nom;
};
#endif