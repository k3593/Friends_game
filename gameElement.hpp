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
    const int getX() const {return this->x;}
    const int getY() const {return this->y;}
    const int getW() const {return this->w;}
    const int getH() const {return this->h;}
    const string getName() const {return this->nom;}

  protected:
    int x; //Coordonnées x de l'origine
    int y; //Coordonnées y de l'origine
    int w; //largeur de l'élément
    int h; //hauteur de l'élément
    string nom;
};
#endif
