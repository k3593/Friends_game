#include "player.hpp"
#include "gameElement.hpp"
#include "room.hpp"

#include <iostream>
#include<cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <SFML/Graphics.hpp>
using namespace std;

//Constructeur Player
Player::Player(int x, int y, int w, int h, string nom, string filename)
{
    cout << "Initialisation du joueur" << endl;
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->nom = nom;
    //Generation du sprite
    sf::Texture texture;
    if(!texture.loadFromFile(filename))
    {
        throw std::runtime_error("impossible de charger image du player");
        }
    this->texture = texture;
    sf::Sprite sprite;
    sprite.setPosition(x, y);
    sprite.setTexture(this->texture);
    sf::Vector2f scale = sprite.getScale();
    scale = sprite.getScale();
    this->w = 48;
    this->h = 48;
    this->sprite = sprite;
    cout << "Initialisation du joueur terminée" << endl;
}

void Player::update(int x, int y){
    if(x<120)
      x = 120;
    else if(y<370)
      y = 370;
    else if(x>240)
      x = 240;
    else if(y>490)
      y = 490;
  this->x = x;
  this->y = y;
  sprite.setPosition(x, y);

  //this->room = room_name;
  //cout << this->room << endl;
}

//destructeur de player
//Player:: ~Player(){
//	delete this->sprite;
//}
