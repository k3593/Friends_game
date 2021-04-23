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
  this->score=0;
  if (filename.compare("monica.png") == 0)
    this->role=0;
  else
    this->role=1;
  cout << "Initialisation du joueur terminée" << endl;
}

void Player::update(int x, int y)
{
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
  int i,j;
  //déclaration de la matrice
  data = new sf::RectangleShape*[this->c];
  for (i=0; i<this->c; i=i+1)
  {
    data[i] = new sf::RectangleShape[this->l];
  }
  //initialisation de la matrice
  for (i=0; i<this->c; i++)
  {
    for (j=0; j<this->l; j++)
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
  // déclaration de la matrice state
  state = new int*[this->c];
  for ( i=0; i<this->c; i++)
  {
    state[i] = new int[this->l];
  }
  int cpt=0;//compteur de 1
  //initialisation de la matrice state
  for(i=0;i<this->c;i++)
  {
		for(j=0;j<this->l;j++)
    {
			state[i][j]=rand()%2;
      if (state[i][j]==1)
        cpt++;
		}
	}
  int nb=(int)((this->c*this->l)/2);
  //cout << nb << endl;
  //cout << cpt << endl;
  while ((cpt!=nb))// si il n'y a pas environ autant de 0 que de 1
  {
    int nl=rand()%l;
    int nc=rand()%c;
    if ((cpt<=(nb-1)))//si il y a plus de 0 que de 1 
    {
      if (state[nl][nc]==0)
      {
        state[nl][nc]=1;
        cpt++;
        //cout << cpt << endl;
      }
    }
    else if ((cpt>=(nb+1)))//si il y a plus de 1 que de 0
    {
      if (state[nl][nc]==1)
      {
        state[nl][nc]=0;
        cpt--;
        //cout << cpt << endl;
      }
    }
  }

  //affichage de la matrice state
  cout << this->nom << endl; 
  cout << "state :" << endl;
  cout << "[";
  for ( i=0; i<this->c; i++)
  { 
      cout << " ";
      for (int j=0; j<this->l; j++)
      { 
          cout << state[i][j] << " " ;
      }
      if (i != this->l-1)
        cout << endl;
  }
  cout << "]" << endl;

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

//Constructeur appartment
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

void Appartment::calculScore(Player nom)
{
  int i,j,k;
  for(i=0;i<this->rooms.size();i++)
  {
    for(j=0;j<this->rooms[i].c;j++)
      for(k=0;k<this->rooms[i].l;k++)
        if(rooms[i].state[j][k]==nom.role)
          nom.score++;
  }
  cout << nom.score << endl;
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