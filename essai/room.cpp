#include "room.hpp"
#include "gameElement.hpp"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <SFML/Graphics.hpp>
using namespace std;

//Constructeur Room
Room::Room(int l, int c, int x, int y, int w, int h, string nom)
{
  //cout << "Initialisation d'une pièce" << endl;
  this->l = l;
  this->c = c;
  this->x = x;
  this->y = y;
  this->w = w;
  this->h = h;
  this->nom = nom;

  //declaration du contour de la room
  sf::RectangleShape rectangle;
  rectangle.setSize(sf::Vector2f(w, h));
  rectangle.setOutlineColor(sf::Color::Red);
  rectangle.setOutlineThickness(2);
  rectangle.setPosition(x, y);
  rectangle.setFillColor(sf::Color::Transparent);
  this->rectangle = rectangle;

  int i;

  //déclaration de la matrice
  data = new sf::RectangleShape*[this->c];
  for ( i=0; i<this->c; i=i+1)
  {
    data[i] = new sf::RectangleShape[this->l];
  }

  //cout << "Fin de l'initialisation d'une pièce" << endl;
}
void Room::reset()
{
  int i,j;
  int cpt=0;//compteur de gris
  
  //initialisation de la matrice
  for ( i=0; i<this->c; i++)
  {
    for ( j=0; j<this->l; j++)
    {
      sf::RectangleShape rectangle;
      rectangle.setSize(sf::Vector2f(int(w/c), int(h/l)));
      rectangle.setOutlineColor(sf::Color::Transparent);
      rectangle.setOutlineThickness(1);
      rectangle.setPosition(x+i*(w/c), y+j*(h/l));
      rectangle.setFillColor(sf::Color::Transparent);
      data[i][j] = rectangle;
      
      //on remplit aléatoirement
      int k=rand()%2;
      if (k==1)
      {
        data[i][j].setFillColor(sf::Color(105, 105, 105, 192));
        cpt++;
      }
      else
        data[i][j].setFillColor(sf::Color::Transparent);
    }
  }
  //on égalise le nombre de case grise et transparente
  int nb=(int)((this->c*this->l)/2);
  while ((cpt!=nb))// si il n'y a pas environ autant de 0 que de 1
  {
    int nl=rand()%l;
    int nc=rand()%c;
    if ((cpt<=(nb-1)))//si il y a plus de transp que de gris
    {
      if (data[nl][nc].getFillColor()==sf::Color::Transparent)
      {
        data[nl][nc].setFillColor(sf::Color(105, 105, 105, 192));
        cpt++;
      }
    }
    else if ((cpt>=(nb+1)))//si il y a plus de gris que de transp
    {
      if (data[nl][nc].getFillColor()==sf::Color(105, 105, 105, 192))
      {
        data[nl][nc].setFillColor(sf::Color::Transparent);
        cpt--;
      }
    }
  }
}

//méthode d'affichage de la room
void Room::affichage(sf::RenderWindow& window){
  for (int i=0; i<this->l; i=i+1)
  {
    for (int j=0; j<this->c; j=j+1)
    {
      window.draw(data[i][j]);
    }
  }
}

//méthode d'affichage des portes
void Room::affichageDoors(sf::RenderWindow& window){
  for (int i=0; i<doors.size(); i++)
  {
    window.draw(this->doors[i].getDoor());
  }
}

//méthode d'affichage des objets
void Room::affichageObjets(sf::RenderWindow& window){
  for (int i=0; i<objets.size(); i++)
  {
    window.draw(this->objets[i]->getObjetAff());
  }
}

//ajout d'une porte à l'attribut doors de room
void Room::addDoor(Door& door_name){
  this->doors.push_back(door_name);
}

//ajout d'un objet à l'attribut objets de room
void Room::addObjet(Objet* objet_name){
  this->objets.push_back(objet_name);
}


/*
Room:: ~Room(){
	for (int i=0; i < this->l; i++)
  {
    delete[] this->data[i];
  }
	delete[] this->data;
}
*/
