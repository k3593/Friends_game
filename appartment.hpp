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
#include "objet.hpp"

using namespace std;



class Appartment : public GameElement
{
  public:
    //constructeurs
    Appartment(const int x, const int y, const int w, const int h, const string nom, const string fileName);
    Appartment();
    // destructeur
    ~Appartment() {}
    void addRoom(Room& nom);
    void addPlayer(Player& nom);
    void calculScore(Player& nom);
    //getters
    const sf::Sprite& getSprite() const {return this->sprite;}
    Player& getPlayer (const int i)  {return players[i];}
    const Room getRoom(const int index) const {return this->rooms[index];}
    vector<Room> getRooms() const {return this->rooms;}
    //Verifier dans quelle pièce le joueur est.
    void inRoom(Player& player);
    //affichage appartement
    void affichage(sf::RenderWindow& window);
  protected:
    sf::Texture texture;
    sf::Sprite sprite;
    vector<Room> rooms;
    vector<Player> players;
};

#endif
