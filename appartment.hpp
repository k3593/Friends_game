#ifndef APPARTMENT_HPP
#define APPARTMENT_HPP

#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

#include "appartment.hpp"
#include "room.hpp"
#include "gameElement.hpp"
#include "player.hpp"

using namespace std;



class Appartment : public GameElement 
{
  public:
    //constructeurs
    Appartment(int x, int y, int w, int h, string nom, string fileName);
    // destructeur
    ~Appartment() {}
    void addRoom(Room nom);
    void addPlayer(Player nom);
    void calculScore(Player nom);
    //getters
    sf::Sprite& getSprite() {return this->sprite;}
    //Verifier dans quelle pièce le joueur est.
    Room& inRoom(Player player);
  protected:
    sf::Texture texture;
    sf::Sprite sprite;
    vector<Room> rooms;
    vector<Player> players;
};

#endif
