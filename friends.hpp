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
  int getX() {return this->x;}
  int getY() {return this->y;}
  int getW() {return this->w;}
  int getH() {return this->h;}
  string getName() {return this->nom;}

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
  //getters
  sf::Sprite& getSprite() {return this->sprite;}
  //update position
  void update(int x, int y);
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
  void affichage(sf::RenderWindow& window);
  //getters
  int getL() {return this->l;}
  int getC() {return this->c;}
  sf::RectangleShape& getRectangle() {return this->rectangle;}
  sf::RectangleShape& operator() (int i, int j){
    if(i > this->c || j > this->l){
      throw std::out_of_range("ERREUR : Vous essayez d'acceder à un élément en dehors de la matrice !");
    }
    else{
      return this->data[i][j];
    }
  }

protected:
  int l; //nombre de lignes
	int c; //nombre de colonnes
  sf::RectangleShape **data;
  sf::RectangleShape rectangle;
};

class Appartment : public GameElement {
public:
  //constructeurs
  Appartment(int x, int y, int w, int h, string nom, string fileName);
  // destructeur
	~Appartment() {}
  void addRoom(Room nom);
  void addPlayer(Player nom);
  //getters
  sf::Sprite& getSprite() {return this->sprite;}
  //Verifié dans quelle pièce le joueur est.
  Room& inRoom(Player player);
protected:
  sf::Texture texture;
  sf::Sprite sprite;
  vector<Room> rooms;
  vector<Player> players;
};
