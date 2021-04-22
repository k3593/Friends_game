#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;

class GameElement
{
  public:
    //constructeurs 
    GameElement() {} //pq pas virtuelle ?
    //destructeur
    virtual ~GameElement() = 0;

  protected:
    //atributs
    int x; //Coordonnées x de l'origine
    int y; //Coordonnées y de l'origine
    int w; //largeur de l'élément
    int h; //hauteur de l'élément
    string nom;
};

class Player : public GameElement 
{
  public:
    //constructeurs
    Player(int x, int y, int w, int h, string nom, string filename);
    // destructeur (y en a pas besoin nan ?)
    ~Player() {}
    //Verifier dans quelle pièce le joueur est.
    //Room inRoom(vector<Room> rooms);
    sf::Sprite getSprite() 
      {return this->sprite;}
  protected:
    sf::Sprite sprite;
};

class Room : public GameElement 
{
  public:
    //constructeurs
    Room(int l, int c, int x, int y, int w, int h, string nom);
    // destructeur
    ~Room();
    //Vérification de l'état d'une pièce
    void state();
  protected:
    //attributs
    int l; //nombre de lignes
    int c; //nombre de colonnes
    double **data;
};

class Appartment : public GameElement 
{
  public:
    //constructeurs
    Appartment(int x, int y, int w, int h, string nom, string filename);
    // destructeur
    ~Appartment() {}
    //Vérification de l'état d'une pièce
    void state();
    //ajouter une salle à l'appartement
    void addRoom(Room nom);
    //getters
    sf::Sprite getSprite() 
      {return this->sprite;}

  protected:
    sf::Sprite sprite;
    int nbrRoom;
    vector <Room> rooms (int nbrRoom);//pq pas dans public ?
};
