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
    cout << room.getName() << endl;

    for (int i=0; i<room.getDoors().size(); i++)
    {
      int cote = room.getDoors()[i].getCote();
      cout << cote << endl;
      if(cote ==2){
        if(x>(room.getX()+room.getW()-24) && y<((room.getDoors()[i].getY())-24+10) && y>((room.getDoors()[i].getY()) -24-10))
        {
          cout << "hello" << endl;
          x = x;
          y = y;

        }
        else{
          cout << "helloelse" << endl;
          if(x<room.getX()-24)
          x = room.getX()-24;
          else if(y<room.getY()-24)
          y = room.getY()-24;
          else if(x>(room.getX()+room.getW()-24))
          x = room.getX()+room.getW()-24;
          else if(y>(room.getY() + room.getH()-24))
          y = room.getY() + room.getH()-24;

        }
      }


      else if(cote ==0){
        if(x<(room.getX()+24) && y<((room.getDoors()[i].getY())-24+10) && y>((room.getDoors()[i].getY()) -24-10))
        {
          cout << "hello2" << endl;
          x = x;
          y = y;
        }

      }
    }

      /*
      else if(cote ==1){
        if(y<(room.getY()+24) && x<((room.getDoors()[i].getX())-24+10) && x>((room.getDoors()[i].getX()) -24-10))
        {
          x = x;
          y = y;
        }
        else{
          if(x<room.getX()-24)
          x = room.getX()-24;
          else if(y<room.getY()-24)
          y = room.getY()-24;
          else if(x>(room.getX()+room.getW()-24))
          x = room.getX()+room.getW()-24;
          else if(y>(room.getY() + room.getH()-24))
          y = room.getY() + room.getH()-24;
        }
      }
      */
      /*
      else if(cote ==3){
        if(y>(room.getY()+room.getH()-24) && x<((room.getDoors()[i].getX())-24+10) && x>((room.getDoors()[i].getX()) -24-10))
        {
          x = x;
          y = y;
        }
        else{
          if(x<room.getX()-24)
          x = room.getX()-24;
          else if(y<room.getY()-24)
          y = room.getY()-24;
          else if(x>(room.getX()+room.getW()-24))
          x = room.getX()+room.getW()-24;
          else if(y>(room.getY() + room.getH()-24))
          y = room.getY() + room.getH()-24;
        }
      }
      */
      this->x = x;
      this->y = y;
      sprite.setPosition(x, y);

}

//destructeur de player
//Player:: ~Player(){
//	delete this->sprite;
//}
