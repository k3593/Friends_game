#ifndef ROOM_HPP
#define ROOM_HPP

#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

#include "gameElement.hpp"
#include "door.hpp"
#include "objet.hpp"

using namespace std;


class Room : public GameElement
{
  public:
    //constructeurs
    Room(int l, int c, int x, int y, int w, int h, string nom);
    Room();

    //Vérification de l'état d'une pièce
    void affichage(sf::RenderWindow& window);
    void affichageDoors(sf::RenderWindow& window);
    //getters
    int getL() {return this->l;}
    int getC() {return this->c;}
    string getName() {return this->nom;}
    vector<Door> getDoors() {return this->doors;}
    vector<Objet> getObjets() {return this->objets;}
    sf::Color getDataColor (const int i, const int j) {return data[i][j].getFillColor();}
    sf::RectangleShape& getRectangle() {return this->rectangle;}

    sf::RectangleShape& operator() (int i, int j){
      if(i > this->c || j > this->l){
        throw std::out_of_range("ERREUR : Vous essayez d'acceder à un élément en dehors de la matrice !");
      }
      else{
        return this->data[i][j];
      }
    }
    void addDoor(Door& door_name);
    void addObjet(Objet& objet_name);

  protected:
    int l; //nombre de lignes
    int c; //nombre de colonnes
    sf::RectangleShape **data;
    sf::RectangleShape rectangle;
    vector<Door> doors;
    vector<Objet> objets;

};
#endif
