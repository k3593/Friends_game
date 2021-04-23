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

void Player::update(int x, int y){
  this->x = x;
  this->y = y;
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
  rectangle.setSize(sf::Vector2f(w, h));
  rectangle.setOutlineColor(sf::Color::Red);
  rectangle.setOutlineThickness(2);
  rectangle.setPosition(x, y);
  rectangle.setFillColor(sf::Color::Transparent);
  this->rectangle = rectangle;

  //déclaration de la matrice
  data = new sf::RectangleShape*[this->c];
  for (int i=0; i<this->c; i=i+1)
  {
    data[i] = new sf::RectangleShape[this->l];
  }
  //initialisation de la matrice
  for (int i=0; i<this->c; i++)
  {
    for (int j=0; j<this->l; j++)
    {
      sf::RectangleShape rectangle;
      rectangle.setSize(sf::Vector2f(int(w/c), int(h/l)));
      rectangle.setOutlineColor(sf::Color::Red);
      rectangle.setOutlineThickness(1);
      rectangle.setPosition(x+i*(w/c), y+j*(h/l));
      //rectangle.setFillColor(sf::Color::Transparent);
      data[i][j] = rectangle;
    }
  }
  cout << "Fin de l'initialisation d'une pièce" << endl;
}

void Room::affichage(sf::RenderWindow& window){
  for (int i=0; i<this->l; i=i+1)
  {
    for (int j=0; j<this->c; j=j+1)
    {
      window.draw(data[i][j]);
    }
  }
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
    throw std::runtime_error("impossible de charger image de l'appartment");
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
    if((rooms[i].getX()<player.getX() && player.getX()<rooms[i].getX()+rooms[i].getW()) && rooms[i].getY()<player.getY() && player.getY()<rooms[i].getY()+rooms[i].getH()){
      cout << rooms[i].getName() << endl;
      int posXPlayer = player.getX();
      int posYPlayer = player.getY();
      int posXRoom = rooms[i].getX();
      int posYRoom = rooms[i].getY();
      int posLocalPlayerX = (posXPlayer - posXRoom) + player.getW()/2;
      int posLocalPlayerY = (posYPlayer - posYRoom) + player.getH()/2;
      for (int k=0; k<rooms[i].getC(); k++)
      {
        for (int j=0; j<rooms[i].getL(); j++)
        {
          if(k*(rooms[i].getW()/rooms[i].getC())<posLocalPlayerX && posLocalPlayerX<(k+1)*(rooms[i].getW()/rooms[i].getC()) && j*(rooms[i].getH()/rooms[i].getL())<posLocalPlayerY && posLocalPlayerY<(j+1)*(rooms[i].getH()/rooms[i].getL())){
            if(player.getName().compare("joey") == 0){
              rooms[i](k,j).setOutlineColor(sf::Color::White);
              rooms[i](k,j).setFillColor(sf::Color::Red);
            }
            else{
              rooms[i](k,j).setOutlineColor(sf::Color::Red);
              rooms[i](k,j).setFillColor(sf::Color::White);
            }
          }
        }
      }
      return(rooms[i]);
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
    Player p1(0, 0, 35, 35, "monica", "monica.png");
    Player p2(0, 0, 35, 35, "joey", "monica.png");
    //Création de l'appartement
    Appartment appart(10, 10, 10, 10, "appart", "apartment.png");
    //Création des pièces de l'appartement
    Room room1(10, 10, 120, 370, 120, 120, "Bathroom");
    Room room2(10, 10, 120, 500, 130, 130, "Bedroom");
    Room room3(10, 10, 300, 400, 130, 130, "Living");
    Room room4(10, 10, 850, 250, 110, 110, "Bedroom_Monica");
    Room room5(5, 5, 610, 220, 70, 80, "Bathroom_Monica");
    Room room6(8, 8, 610, 350, 200, 130, "Living_Monica");
    Room room7(8, 8, 610, 350, 200, 130, "Living_Monica_2");
    //Remplissage de l'appartement avec les pièces
    appart.addRoom(room1);
    appart.addRoom(room2);
    appart.addRoom(room3);
    appart.addRoom(room4);
    appart.addRoom(room5);
    appart.addRoom(room6);
    appart.addRoom(room7);

    //appart.inRoom(p1).state(p1);
    //appart.inRoom(p1).state(p1);


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
    sf::Vector2f posJoey = p2.getSprite().getPosition();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
      posMonica.x = posMonica.x-1;
      posMonica.y = posMonica.y;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
      posMonica.x = posMonica.x + 1;
      posMonica.y = posMonica.y;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
      posMonica.x = posMonica.x;
      posMonica.y = posMonica.y-1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
      posMonica.x = posMonica.x;
      posMonica.y = posMonica.y + 1;
		}

    //Joey
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		{
      posJoey.x = posJoey.x-1;
      posJoey.y = posJoey.y;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
      posJoey.x = posJoey.x + 1;
      posJoey.y = posJoey.y;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		{
      posJoey.x = posJoey.x;
      posJoey.y = posJoey.y-1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
      posJoey.x = posJoey.x;
      posJoey.y = posJoey.y + 1;
		}
        p1.getSprite().setPosition(posMonica.x, posMonica.y);
        p1.update(posMonica.x, posMonica.y);
        p2.getSprite().setPosition(posJoey.x, posJoey.y);
        p2.update(posJoey.x, posJoey.y);
        window.clear();
        appart.inRoom(p1);
        appart.inRoom(p2);
        window.draw(appart.getSprite());
        window.draw(room1.getRectangle());
        window.draw(room2.getRectangle());
        window.draw(room3.getRectangle());
        window.draw(room4.getRectangle());
        window.draw(room5.getRectangle());
        window.draw(room6.getRectangle());
        window.draw(room7.getRectangle());
        room1.affichage(window);
        room2.affichage(window);
        room3.affichage(window);
        room4.affichage(window);
        room5.affichage(window);
        room6.affichage(window);
        room7.affichage(window);
        window.draw(p1.getSprite());
        window.draw(p2.getSprite());
        window.display();
    }

    return 0;
}
