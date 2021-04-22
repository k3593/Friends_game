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
  this->x = x;
  this->y = y;
  this->w = w;
  this->h = h;
  this->nom = nom;
  //Generation du sprite
  sf::Texture texture;
	texture.loadFromFile(filename);
  this->texture = texture;
  sf::Sprite sprite;
	sprite.setTexture(this->texture);
	sf::Vector2f scale = sprite.getScale();
	sprite.scale(scale.x * 1/12, scale.y * 1/12);
  this->sprite = sprite;
}

//Constructeur Room
Room::Room(int l, int c, int x, int y, int w, int h, string nom)
{
  this->l = l;
  this->c = c;
  this->x = x;
  this->y = y;
  this->w = w;
  this->h = h;
  this->nom = nom;

  //déclaration de la matrice
  data = new double*[this->l];
  for (int i=0; i<this->l; i=i+1)
  {
    data[i] = new double[this->c];
  }
  int j=0;
  //initialisation de la matrice
  for (int i=0; i<this->l; i=i+1)
  {
    for (j=0; j<this->c; j=j+1)
    {
      data[i][j] = 0;
    }
  }
}

//Constructeur Player
Appartment::Appartment(int x, int y, int w, int h, string nom, string filename)
{
  this->x = x;
  this->y = y;
  this->w = w;
  this->h = h;
  this->nom = nom;

  //Generation du sprite
  sf::Texture background;
	background.loadFromFile(filename);
  this->texture = background;
  sf::Sprite spriteBackground;
	spriteBackground.setTexture(this->texture);
  this->sprite = spriteBackground;
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

int main(int argc, char ** argv)
{

    float windowHeight = 721;
    float windowWidht = 1109;
    Player p1(10, 10, 10, 10, "theo", "monica.png");
    Appartment appart(10, 10, 10, 10, "appart", "apartment.png");
    sf::RenderWindow window(sf::VideoMode(windowWidht, windowHeight), "SFML works!");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

		sf::Vector2f posMonica = p1.getSprite().getPosition();
    std::cout << posMonica.x << posMonica.y;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			p1.getSprite().setPosition(posMonica.x - 1, posMonica.y);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			p1.getSprite().setPosition(posMonica.x + 1, posMonica.y);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			p1.getSprite().setPosition(posMonica.x, posMonica.y-1);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			p1.getSprite().setPosition(posMonica.x, posMonica.y+1);
		}
        window.clear();
        window.draw(appart.getSprite());
		    window.draw(p1.getSprite());
        window.display();
    }

    return 0;
}
