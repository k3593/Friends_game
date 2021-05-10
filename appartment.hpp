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
    Appartment();
    // destructeur
    ~Appartment() {}
    void addRoom(Room nom);
    void addPlayer(Player nom);
    void calculScore(Player& nom);
    //getters
    sf::Sprite& getSprite() {return this->sprite;}
    Player& getPlayer (int i) {return players[i];}
    //Verifier dans quelle pièce le joueur est.
    Room& inRoom(Player player);
    //affichage appartement
    void affichage(sf::RenderWindow& window);
  protected:
    sf::Texture texture;
    sf::Sprite sprite;
    vector<Room> rooms;
    vector<Player> players;
};

#endif
