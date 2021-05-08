#include "appartment.hpp"
#include "room.hpp"
#include "gameElement.hpp"
#include "player.hpp"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <SFML/Graphics.hpp>
using namespace std;


//Constructeur Appartment
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

void Appartment::calculScore(Player nom)
{
  int i,j,k;
  cout << "score de " << nom.getName()<< " : " << nom.getScore() << endl;
  for(i=0;i<this->rooms.size();i++)
  {

    for(j=0;j<this->rooms[i].getC();j++)
      for(k=0;k<this->rooms[i].getL();k++)
      {
        if(nom.getName().compare("joey") == 0 && rooms[i].getDataColor(j,k)==sf::Color(105, 105, 105, 192))// si le joueur est joey et que la case est rouge (sale)
        {
          nom.setScore(nom.getScore()+1);
        }
        else if(nom.getName().compare("monica") == 0 && rooms[i].getDataColor(j,k)==sf::Color::Transparent)// si le joueur est monica et que la case est blanche (propre)
        {
          nom.setScore(nom.getScore()+1);
        }

      }
    cout << "score de " << nom.getName()<<" dans " << rooms[i].getName()<< " : " << nom.getScore() << endl;
  }
  cout << "score de " << nom.getName()<< " : " << nom.getScore() << endl;
}

//Cette fonction return l'adresse de la pièce dans laquelle le joueur se trouve.
Room& Appartment::inRoom(Player player){
  for(int i=0; i<rooms.size(); i++){
    if((rooms[i].getX()<player.getX() && player.getX()<rooms[i].getX()+rooms[i].getW()) && rooms[i].getY()<player.getY() && player.getY()<rooms[i].getY()+rooms[i].getH())
    {
      //cout << rooms[i].getName() << endl;
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
          if(k*(rooms[i].getW()/rooms[i].getC())<=posLocalPlayerX && posLocalPlayerX<=(k+1)*(rooms[i].getW()/rooms[i].getC()) && j*(rooms[i].getH()/rooms[i].getL())<=posLocalPlayerY && posLocalPlayerY<=(j+1)*(rooms[i].getH()/rooms[i].getL()))
          {
            if(player.getName().compare("joey") == 0){
              rooms[i](k,j).setOutlineColor(sf::Color::Transparent);
              rooms[i](k,j).setFillColor(sf::Color(105, 105, 105, 192));
            }
            else{
              rooms[i](k,j).setOutlineColor(sf::Color::Transparent);
              rooms[i](k,j).setFillColor(sf::Color::Transparent);
            }
          }
        }
      }
      return(rooms[i]);
    }
  }
}

void Appartment::affichage(sf::RenderWindow& window){
  for (int i=0; i<this->rooms.size(); i=i+1)
  {
      rooms[i].affichage(window);
  }
}
