#include "player.hpp"

#include <iostream>
#include<cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <SFML/Graphics.hpp>
using namespace std;

//Constructeur Player
Player::Player(int x, int y, int w, int h, string nom, string filename, Room room_init)
{
    cout << "Initialisation du joueur" << endl;
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->nom = nom;
    this->room = room_init;
    //Generation du sprite
    sf::Texture texture;
    if(!texture.loadFromFile(filename))
    {
        throw std::runtime_error("impossible de charger image du player");
        }
    this->texture = texture;
    sf::Sprite sprite;
    sprite.setPosition(x, y);
    sprite.setTexture(this->texture);
    sf::Vector2f scale = sprite.getScale();
    scale = sprite.getScale();
    this->w = 48;
    this->h = 48;
    this->sprite = sprite;
    cout << "Initialisation du joueur terminée" << endl;
}

void Player::update(int x, int y){
    int state=0;
    cout << room.getName() << endl;
    for (int i=0; i<room.getDoors().size(); i++)
    {
      int cote = room.getDoors()[i].getCote();
      switch (cote) {
        case 0:
        if(x<(room.getX()-20) && y<((room.getDoors()[i].getY())-24+10) && y>((room.getDoors()[i].getY()) -24-10))
        {
          x = x;
          y = y;
          this->x = x;
          this->y = y;
          sprite.setPosition(x, y);
          state = 1;
        }
        break;
        case 2:
        if(x>(room.getX()+room.getW()-24) && y<((room.getDoors()[i].getY())-24+10) && y>((room.getDoors()[i].getY()) -24-10))
        {
          x = x;
          y = y;
          this->x = x;
          this->y = y;
          sprite.setPosition(x, y);
          state = 1;
        }
        break;
        case 1:
        if(y<(room.getY()-20) && x<((room.getDoors()[i].getX())-24+10) && x>((room.getDoors()[i].getX()) -24-10))
        {
          x = x;
          y = y;
          this->x = x;
          this->y = y;
          sprite.setPosition(x, y);
          state = 1;
        }
        case 3:
        if(y>(room.getY()+room.getH()-24) && x<((room.getDoors()[i].getX())-24+10) && x>((room.getDoors()[i].getX()) -24-10))
        {
          x = x;
          y = y;
          this->x = x;
          this->y = y;
          sprite.setPosition(x, y);
          state = 1;
        }
      }
    }

        if(state == 0){
          if(x<room.getX()-24)
          x = room.getX()-24;
          else if(y<room.getY()-24)
          y = room.getY()-24;
          else if(x>(room.getX()+room.getW()-24))
          x = room.getX()+room.getW()-24;
          else if(y>(room.getY() + room.getH()-24))
          y = room.getY() + room.getH()-24;
          this->x = x;
          this->y = y;
          sprite.setPosition(x, y);
        }

      this->x = x;
      this->y = y;
      sprite.setPosition(x, y);

}

//destructeur de player
//Player:: ~Player(){
//	delete this->sprite;
//}
