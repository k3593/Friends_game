#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <SFML/Graphics.hpp>
using namespace std;


//Constructeur Bonus
Bonus::Bonus() : Objet("bonus", "bonus.png")
{
    this->score = 10;
    return;
}
