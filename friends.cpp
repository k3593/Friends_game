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
	sprite.scale(scale.x * 1/12, scale.y * 1/12);
  this->sprite = sprite;
  cout << "Initialisation du joueur terminée" << endl;
}

//Constructeur Room
Room::Room(int l, int c, int x, int y, int w, int h, string nom)
{
  cout << "Initialisation d'une pièce" << endl;
  this->l = l;
  this->c = c;
  this->x = x;
  this->y = y;
  this->w = w;
  this->h = h;
  this->nom = nom;

  sf::RectangleShape rectangle;
  rectangle.setSize(sf::Vector2f(100, 50));
  rectangle.setOutlineColor(sf::Color::Red);
  rectangle.setOutlineThickness(5);
  rectangle.setPosition(10, 20);
  rectangle.setFillColor(sf::Color::Transparent);
  this->rectangle = rectangle;

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
  cout << "Fin de l'initialisation d'une pièce" << endl;
}

void Room::state(Player nom){
  
}

//Constructeur Player
Appartment::Appartment(int x, int y, int w, int h, string nom, string filename)
{
  cout << "Initialisation d'un appartement" << endl;
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
  this->texture = background;
  sf::Sprite spriteBackground;
	spriteBackground.setTexture(this->texture);
  this->sprite = spriteBackground;

  cout << "Fin de l'initialisation d'un appartement" << endl;
}

void Appartment::addRoom(Room nom){
  this->rooms.push_back(nom);
  cout << "Ajout de la pièce terminé" << endl;
}

void Appartment::addPlayer(Player nom){
  this->players.push_back(nom);
  cout << "Ajout du joueur terminé" << endl;
}

//Cette fonction return l'adresse de la pièce dans laquelle le joueur se trouve.
Room& Appartment::inRoom(Player player){
  for(int i=0; i<rooms.size(); i++){
    if(rooms[i].getX()< player.getX()<rooms[i].getX()+rooms[i].getW() && rooms[i].getY()< player.getY() <rooms[i].getY()+rooms[i].getH()){
      return(rooms[i]);
      cout << rooms[i].getName();
    }
  }
}

GameElement::~GameElement() {}

//Player:: ~Player(){
//	delete this->sprite;
//}

Room:: ~Room(){}

/*
Room:: ~Room(){
	for (int i=0; i < this->l; i++)
  {
    delete[] this->data[i];
  }
	delete[] this->data;
}
*/

int main(int argc, char ** argv)
{

    float windowHeight = 721;
    float windowWidht = 1109;
    //Création des joueurs
    Player p1(10, 10, 10, 10, "theo", "monica.png");
    //Création de l'appartement
    Appartment appart(10, 10, 10, 10, "appart", "apartment.png");
    //Création des pièces de l'appartement
    Room room1(10, 10, 5, 10, 10, 10, "Bathroom");
    Room room2(10, 10, 5, 10, 10, 10, "Bedroom");
    //Remplissage de l'appartement avec les pièces
    appart.addRoom(room1);
    appart.addRoom(room2);

    //Test de inRoom
    appart.inRoom(p1);
    //

    sf::RenderWindow window(sf::VideoMode(windowWidht, windowHeight), "Jeu Friends");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Resized)
            {
                    // récupération de la taille de la fenêtre
                    sf::Vector2u size = window.getSize();

                    float ratio(windowHeight/windowWidht);
                    size.y=(unsigned int) (ratio*size.x);
                    window.setSize(size);
            }
            if (event.type == sf::Event::Closed)
                window.close();
        }

		sf::Vector2f posMonica = p1.getSprite().getPosition();
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
		    window.draw(room1.getRectangle());
        window.draw(room2.getRectangle());
        window.display();
    }

    return 0;
}
