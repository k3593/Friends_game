#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <SFML/Graphics.hpp>
using namespace std;

#include "bonus.hpp"


//Constructeur Bonus
Bonus::Bonus(const int x, const int y) : Objet("bonus", "bonus.png")
{
    this->x = x;
    this->y = y;
    this->score = 10;
    sprite.setPosition(this->x, this->y);
    return;
}
