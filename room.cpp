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
  rectangle.setOutlineColor(sf::Color::Transparent);
  rectangle.setOutlineThickness(2);
  rectangle.setPosition(x, y);
  rectangle.setFillColor(sf::Color::Transparent);
  this->rectangle = rectangle;

  int i,j;
  int cpt=0;//compteur de rouge

  //déclaration de la matrice
  data = new sf::RectangleShape*[this->c];
  for ( i=0; i<this->c; i=i+1)
  {
    data[i] = new sf::RectangleShape[this->l];
  }
  //initialisation de la matrice
  //sf::Color blacko(192, 192, 192);
  //blacko.a=192;
  for ( i=0; i<this->c; i++)
  {
    for ( j=0; j<this->l; j++)
    {
      sf::RectangleShape rectangle;
      rectangle.setSize(sf::Vector2f(int(w/c), int(h/l)));
      rectangle.setOutlineColor(sf::Color::Red);
      rectangle.setOutlineThickness(1);
      rectangle.setPosition(x+i*(w/c), y+j*(h/l));
      rectangle.setFillColor(sf::Color::Transparent);
      data[i][j] = rectangle;

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

  int nb=(int)((this->c*this->l)/2);
  //cout << nb << endl;
  //cout << cpt << endl;
  while ((cpt!=nb))// si il n'y a pas environ autant de 0 que de 1
  {
    int nl=rand()%l;
    int nc=rand()%c;
    if ((cpt<=(nb-1)))//si il y a plus de blanc que de rouge
    {
      if (data[nl][nc].getFillColor()==sf::Color::Transparent)
      {
        data[nl][nc].setFillColor(sf::Color(105, 105, 105, 192));
        cpt++;
        //cout << cpt << endl;
      }
    }
    else if ((cpt>=(nb+1)))//si il y a plus de rouge que de blanc
    {
      if (data[nl][nc].getFillColor()==sf::Color(105, 105, 105, 192))
      {
        data[nl][nc].setFillColor(sf::Color::Transparent);
        cpt--;
        //cout << cpt << endl;
      }
    }
    //cout << cpt << endl;
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


/*
Room:: ~Room(){
	for (int i=0; i < this->l; i++)
  {
    delete[] this->data[i];
  }
	delete[] this->data;
}
*/
