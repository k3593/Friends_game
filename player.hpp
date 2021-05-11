#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

#include "gameElement.hpp"
#include "room.hpp"

using namespace std;

class Player : public GameElement
{
  public:
    //constructeurs
    Player(int x, int y, int w, int h, string nom, string filename);
    // destructeur
    ~Player() {}
    //getters
    sf::Sprite& getSprite() {return this->sprite;}
    void setSprite(sf::Sprite s) {this->sprite=s;}
    int getScore() {return this->score;}
    void setScore(int s) {this->score=s;}
    void setRoom(string room_name) {this->room = room_name;}
    int getW() {return this->w;}
    int getH() {return this->h;}
    //update position
    void update(int x, int y);
  protected:
    int score;
    sf::Texture texture;
    sf::Sprite sprite;
    string room;
};

#endif
