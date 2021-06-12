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
    return;
}

//effet de bonus sur le jeu
void Bonus::fonction(Player& player)
{
    player.setScore(player.getScore()+10);
}
