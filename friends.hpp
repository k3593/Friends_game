#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;

class GameElement{
public:
  //constructeurs
  GameElement() {}
  virtual ~GameElement() = 0;

protected:
  int x; //Coordonnées x de l'origine
	int y; //Coordonnées y de l'origine
  int w; //largeur de l'élément
	int h; //hauteur de l'élément
  string nom;
};

class Player : public GameElement {
public:
  //constructeurs
  Player(int x, int y, int w, int h, string nom, string filename);
  // destructeur
	~Player() {}
  //Verifié dans quelle pièce le joueur est.
  //Room inRoom(vector<Room> rooms);
  //getters
  sf::Sprite getSprite() {return this->sprite;}
protected:
  sf::Texture texture;
  sf::Sprite sprite;
};

class Room : public GameElement {
public:
  //constructeurs
  Room(int l, int c, int x, int y, int w, int h, string nom);
  // destructeur
	~Room();
  //Vérification de l'état d'une pièce
  void state();
protected:
  int l; //nombre de lignes
	int c; //nombre de colonnes
  double **data;
};

class Appartment : public GameElement {
public:
  //constructeurs
  Appartment(int x, int y, int w, int h, string nom, string fileName);
  // destructeur
	~Appartment() {}
  //Vérification de l'état d'une pièce
  void state();
  void addRoom(Room nom);
  //getters
  sf::Sprite getSprite() {return this->sprite;}

protected:
  sf::Texture texture;
  sf::Sprite sprite;
  int nbrRoom;
  vector <Room> rooms (int nbrRoom);
};
