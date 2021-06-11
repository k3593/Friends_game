#ifndef BONUS_HPP
#define BONUS_HPP

#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

#include "appartment.hpp"
#include "room.hpp"
#include "gameElement.hpp"
#include "player.hpp"
#include "bonus.hpp"
#include "objet.hpp"
#include "door.hpp"

using namespace std;

class Bonus : public Objet
{
  public:
    //constructeur
    Bonus(Room room);
    //effet de bonus : rajouter 10pts au player qui l'a
    void fonction(Player& player);
};

#endif