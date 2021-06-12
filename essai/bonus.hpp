#ifndef BONUS_HPP
#define BONUS_HPP

#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

#include "player.hpp"
#include "bonus.hpp"
#include "objet.hpp"

using namespace std;

//effet de bonus : rajouter 10pts au player qui l'a
class Bonus : public Objet
{
  public:
    //constructeur
    Bonus(const int x,const int y);

};

#endif
