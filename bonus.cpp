#include "appartment.hpp"
#include "room.hpp"
#include "gameElement.hpp"
#include "player.hpp"
#include "bonus.hpp"
#include "door.hpp"
#include "objet.hpp"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <SFML/Graphics.hpp>
using namespace std;


//Constructeur Bonus
Bonus::Bonus(Room room) : Objet(room, "bonus.png")
{
    return;
}

//effet de bonus sur le jeu
void Bonus::fonction(Player& player)
{
    player.setScore(player.getScore()+10); 
}


