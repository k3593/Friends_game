#include "friends.hpp"
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
  cout << "Debut player" << endl;
  this->x = x;
  this->y = y;
  this->w = w;
  this->h = h;
  this->nom = nom;
  //Generation du sprite
  sf::Texture texture;
  if(!texture.loadFromFile(filename))
  {
    throw std::runtime_error("impossible de chatger image du player");
	}
  sf::Sprite sprite;
	sprite.setTexture(texture);
	sf::Vector2f scale = sprite.getScale();
	sprite.scale(scale.x * 1/12, scale.y * 1/12);
  this->sprite = sprite;
  cout << "fin player" << endl;
}

//Constructeur Room
Room::Room(int l, int c, int x, int y, int w, int h, string nom)
{
  cout << "debut room" << endl;
  this->l = l;
  this->c = c;
  this->x = x;
  this->y = y;
  this->w = w;
  this->h = h;
  this->nom = nom;

  int j=0;
  int i=0;
  //déclaration de la matrice
  data = new double*[this->l];
  for (i=0; i<this->l; i++)
  {
    data[i] = new double[this->c];
  }
  
  //initialisation de la matrice à 0
  for (i=0; i<this->l; i++)
  {
    for (j=0; j<this->c; j++)
    {
      data[i][j] = 0;
    }
  }
  cout << "fin room" << endl;
}

//Constructeur Player
Appartment::Appartment(int x, int y, int w, int h, string nom, string filename)
{
  cout << "debut apartment" << endl;
  this->x = x;
  this->y = y;
  this->w = w;
  this->h = h;
  this->nom = nom;

  //Generation du sprite
  sf::Texture background;
  if(!background.loadFromFile(filename))
  {
    throw std::runtime_error("impossible de chatger image de l'appartment");
	}
  sf::Sprite spriteBackground;
	spriteBackground.setTexture(background);
  this->sprite = spriteBackground;
  cout << "fin appartment" << endl;
}

GameElement::~GameElement() {}

//Player:: ~Player(){
//	delete this->sprite;
//}

Room:: ~Room(){
	for (int i=0; i < this->l; i++)
  {
    delete[] this->data[i];
  }
	delete[] this->data;
}


