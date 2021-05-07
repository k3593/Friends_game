#include "player.hpp"
#include "gameElement.hpp"

#include <iostream>
#include <string>
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
    sprite.setTexture(this->texture);
    sf::Vector2f scale = sprite.getScale();
    //sprite.scale(scale.x * 1, scale.y * 1);
    scale = sprite.getScale();
    this->w = 48;
    this->h = 48;
    this->sprite = sprite;
    cout << "Initialisation du joueur terminée" << endl;
}

void Player::update(int x, int y){
  this->x = x;
  this->y = y;
}
//destructeur de player
//Player:: ~Player(){
//	delete this->sprite;
//}