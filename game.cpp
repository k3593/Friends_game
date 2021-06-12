#include "game.hpp"
#include "gameElement.hpp"
#include "appartment.hpp"
#include "menu.hpp"
#include "objet.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>

Game::Game()
{
  //Création des pièces de l'appartement
  //Création de la première pièce
  Door door1_room1(90+120, 350+20, 20, 0, "door1", 90, 2);
  Room room1(10, 10, 90, 350, 120, 120, "Bedroom_chandler");
  room1.addDoor(door1_room1);
  //Création de la deuxième pièce
  Door door1_room2(90+130, 500+10, 20, 0, "door1", 90, 2);
  Room room2(10, 10, 90, 500, 130, 130, "Bedroom_joey");
  room2.addDoor(door1_room2);
  //Création de la troisième pièce
  Door door1_room3(240+240, 360+60, 20, 0, "door1", 90, 2);
  Door door2_room3(240, 360+20, 20, 0, "door2", 90, 0);
  Door door3_room3(240, 360+140, 20, 0, "door2", 90, 0);
  Door door4_room3(240+140, 360, 40, 0, "door2", 180, 1);
  //création du premier objet
  //Objet bonus1("bonus", "bonus.png", 240+10, 360+10);
  Room room3(10, 10, 240, 360, 240, 160, "Living");
  room3.addDoor(door1_room3);
  room3.addDoor(door2_room3);
  room3.addDoor(door3_room3);
  room3.addDoor(door4_room3);
  Objet* bonus1 = new Objet("bonus", "bonus.png", 240+10, 360+10);
  room3.addObjet(bonus1);
  //room3.addObjet(bonus1);

  //Création de la quatrième pièce
  Door door1_room10(500+90, 400+20, 20, 0, "door1", 90, 2);
  Door door2_room10(500, 400+20, 20, 0, "door2", 90, 0);
  Room room10(5,5,500, 400, 90, 120, "corridor");
  room10.addDoor(door1_room10);
  room10.addDoor(door2_room10);


  Door door1_room4(920, 200+30, 20, 0, "door1", 90, 0);
  Room room4(10, 10, 920, 200, 110, 110, "Bedroom_Monica");
  room4.addDoor(door1_room4);
  Door door1_room5(640+60, 200, 20, 0, "door1", 90, 2);
  Room room5(5, 5, 640, 180, 60, 70, "Bathroom_Monica");
  room5.addDoor(door1_room5);
  //Création de la sixième pièce
  Door door1_room6(650, 300+120, 20, 0, "door1", 90, 0);
  Door door2_room6(650+230, 300+50, 20, 0, "door2", 90, 2);
  Door door3_room6(650+210, 300, 150, 0, "door1", 180, 1);
  Room room6(8, 8, 650, 300, 230, 130, "Living_Monica");
  Objet* bonus2 = new Objet("bonus", "unit1.png", 650+20, 300+20);
  room6.addObjet(bonus2);
  room6.addDoor(door1_room6);
  room6.addDoor(door2_room6);
  room6.addDoor(door3_room6);

  Door door1_room7(860, 300, 150, 0, "door1", 180, 3);
  Door door2_room7(750, 200, 20, 0, "door1", 90, 0);
  Door door3_room7(750+120, 200+30, 20, 0, "door1", 90, 2);
  Room room7(6, 6, 750, 200, 120, 80, "Living_Monica_2");
  room7.addDoor(door1_room7);
  room7.addDoor(door2_room7);
  room7.addDoor(door3_room7);

  //Création de la sixième pièce
  Door door1_room8(920, 350, 20, 0, "door1", 90, 0);
  Room room8(6, 6, 920, 350, 110, 100, "Guest_room");
  room8.addDoor(door1_room8);

  //Création de la 9 pièce
  Door door1_room9(360+40, 205+60, 20, 0, "door1", 180, 3);
  Room room9(6, 6, 360, 205, 80, 60, "Bathroom_Joey");
  room9.addDoor(door1_room9);
  cout << "Initialisation appart terminée" << endl;
  //Remplissage de l'appartement avec les pièces
  appart.addRoom(room1);

  appart.addRoom(room2);
  appart.addRoom(room3);
  appart.addRoom(room4);
  appart.addRoom(room5);
  appart.addRoom(room6);
  appart.addRoom(room7);
  appart.addRoom(room8);
  appart.addRoom(room9);
  appart.addRoom(room10);
  cout << "Initialisation appart terminée" << endl;

  if(!icone.loadFromFile("icone.png"))
  {
    throw std::runtime_error("impossible de charger image de l'icone");
  }

  initFonts();
  initText();
  initChrono();

  //sounds
  music.openFromFile("friends_song.ogg");
  music_joey.openFromFile("how_you_doin.ogg");
  music_monica.openFromFile("monica.ogg");
}

void Game::menu()
{
  sf::RenderWindow window_menu(sf::VideoMode(windowWidht, windowHeight), "Jeu Friends");

  window_menu.setIcon(225, 225,icone.getPixelsPtr());
  //Création du menu
  Menu menu(window_menu.getSize().x, window_menu.getSize().y);

  music.play();
  while (window_menu.isOpen())
  {
      sf::Event event;
      while (window_menu.pollEvent(event))
      {
          switch(event.type)
          {
            case sf::Event::KeyReleased:
              switch(event.key.code)
              {
                case sf::Keyboard::Up:
                  menu.goUp();
                  break;
                case sf::Keyboard::Down:
                  menu.goDown();
                  break;
                case sf::Keyboard::Return:
                  switch (menu.GetState())
                  {
                    case 0:
                      std::cout << "bouton play" << std::endl;

                      this->play();

                      break;
                    case 1:
                      std::cout << "bouton options" << std::endl;
                      popUp("Règles","Régles.png");
                      break;
                    case 2:
                      std::cout << "bouton exit" << std::endl;
                      window_menu.close();
                      break;
                  }
              }
              break;
            case sf::Event::Closed:
              window_menu.close();
              break;
          }
      }
      sf::Texture background;
      if(!background.loadFromFile("LEJEU.png"))
      {
        throw std::runtime_error("impossible de charger image du menu");
      }
      sf::Sprite spriteBackground;
      spriteBackground.setTexture(background);
      window_menu.draw(spriteBackground);
      menu.draw(window_menu);
      window_menu.display();

  }
}

void Game::initFonts()
{
  // Chargement de la police à partir d'un fichier

    if (!MyFont.loadFromFile("Dosis-Light.ttf"))
    {
      throw std::runtime_error("impossible de charger la police");
    }
}
void Game::initText()
{
  text.setFont(MyFont);
  text.setCharacterSize(24);
  text.setString("Hello");
  text.setFillColor(sf::Color::Red);
}

void Game::initChrono()
{
  time.setFont(MyFont);
  time.setCharacterSize(24);
  time.setPosition(windowWidht-150,0);
  time.setString("Hello");
  time.setFillColor(sf::Color::Black);
}

void Game::updateText(int score1, int score2)
{
  std::stringstream ss;
  ss <<"Points de Monica : "<<  score1 <<"\n" << "Points de Joey : "<< score2 ;
  //cout << ss.str() <<endl;
  this->text.setString(ss.str());
}

void Game::updateChrono(sf::Clock chrono)
{
  std::stringstream ss;
  ss <<"Temps : "<<  temps-chrono.getElapsedTime().asSeconds() ;
  //cout << ss.str() <<endl;
  this->time.setString(ss.str());
}
void Game::popUp(string titre, string image)
{
  sf::RenderWindow window_popUp(sf::VideoMode(windowWidht, windowHeight), titre);
  while (window_popUp.isOpen())
  {
    sf::Event event;
    while (window_popUp.pollEvent(event))
    {
        // évènement "fermeture demandée" : on ferme la fenêtre
        if (event.type == sf::Event::Closed)
            window_popUp.close();
    }
    sf::Texture background;
    if(!background.loadFromFile(image))
    {
      throw std::runtime_error("impossible de charger image dans popUp");
    }
    sf::Sprite spriteBackground;
    spriteBackground.setTexture(background);
    window_popUp.draw(spriteBackground);
    window_popUp.display();
  }

}

void Game::play()
{
  //Création des joueurs
  Player p1(140, 370, 144, 192, "monica", "monica.png", appart.getRoom(1));
  Player p2(140, 370, 144, 192, "joey", "joey.png", appart.getRoom(1));
  appart.addPlayer(p1);
  appart.addPlayer(p2);

  appart.calculScore(appart.getPlayer(0));
  appart.calculScore(appart.getPlayer(1));

  //appart.calculScore(p1);
  //appart.calculScore(p2);

  cout<<"gloabl"<<p1.getMyObjets().size()<<endl;

  sf::RenderWindow window_game(sf::VideoMode(windowWidht, windowHeight), "Jeu Friends");
  window_game.setIcon(225, 225,icone.getPixelsPtr());

  //pour l'animation lors des deplacements
  enum Dir{Down, Left, Right, Up};
  sf::Vector2i anim1(1,Down);
  sf::Vector2i anim2(1,Down);
  bool updateFPS1 = false;
  bool updateFPS2 = false;

  //création des horloges
  sf::Clock time1;
  sf::Clock time2;
  sf::Clock time3;
  sf::Clock chrono;


  //sounds

  sf::SoundBuffer buffer;
  buffer.loadFromFile("pas.wav");

  sf::Sound sound;
  sound.setBuffer(buffer);

  while (window_game.isOpen())
  {
    sf::Event event;
    while (window_game.pollEvent(event))
    {
        if (event.type == sf::Event::Resized)
        {
            // récupération de la taille de la fenêtre
            sf::Vector2u size = window_game.getSize();

            float ratio(windowHeight/windowWidht);
            size.y=(unsigned int) (ratio*size.x);//redimentionnement proportionel
            window_game.setSize(size);
        }
        if (event.type == sf::Event::Closed)//si on clique sur fermer
            window_game.close();

        if(event.type=sf::Event::KeyPressed)//si une touche est pressée
        {
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
          ||sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            updateFPS1=true;//on fait l'animation
          else
            updateFPS1=false;//sinon on ne l'a fait pas

          if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)
          ||sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            updateFPS2=true;//on fait l'animation
          else
            updateFPS2=false;//sinon on ne l'a fait pas
        }
    }
    if(chrono.getElapsedTime().asSeconds()<temps)
    {
      sf::Vector2f posMonica = p1.getSprite().getPosition();
      sf::Vector2f posJoey = p2.getSprite().getPosition();
      //monica
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
      {
              anim1.y=Left;

              posMonica.x = posMonica.x-1;
              posMonica.y = posMonica.y;
      }
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
      {
              anim1.y=Right;
              posMonica.x = posMonica.x + 1;
              posMonica.y = posMonica.y;
      }
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
      {
              anim1.y=Up;
              posMonica.x = posMonica.x;
              posMonica.y = posMonica.y-1;
      }
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
      {
              anim1.y=Down;
              posMonica.x = posMonica.x;
              posMonica.y = posMonica.y + 1;
      }

      //Joey
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
      {
            anim2.y=Left;
            posJoey.x = posJoey.x-1;
            posJoey.y = posJoey.y;
      }
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
      {
              anim2.y=Right;
              posJoey.x = posJoey.x + 1;
              posJoey.y = posJoey.y;
      }
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
      {
              anim2.y=Up;
              posJoey.x = posJoey.x;
              posJoey.y = posJoey.y-1;
      }
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
      {
              anim2.y=Down;
              posJoey.x = posJoey.x;
              posJoey.y = posJoey.y + 1;
      }
      //animation
      if(updateFPS1==true)
      {
        if(time1.getElapsedTime().asMilliseconds() >= 50)
        {
          anim1.x++;
          if(anim1.x*48 >= p1.getW()*3)
              anim1.x=0;
          time1.restart();
        }
        if(time3.getElapsedTime().asMilliseconds() >= 500)
        {
          sound.play();
          time3.restart();
        }
      }
      if(updateFPS2==true)
      {
        if(time2.getElapsedTime().asMilliseconds() >= 50)
        {
          anim2.x++;
          if(anim2.x*48 >= p2.getW()*3)
              anim2.x=0;
          time2.restart();
        }
        if(time3.getElapsedTime().asMilliseconds() >= 500)
        {
          sound.play();
          time3.restart();
        }
      }
      sf::Sprite s1=p1.getSprite();
      s1.setTextureRect(sf::IntRect(anim1.x*48, anim1.y*48, 48, 48));
      p1.setSprite(s1);
      sf::Sprite s2=p2.getSprite();
      s2.setTextureRect(sf::IntRect(anim2.x*48, anim2.y*48, 48, 48));
      p2.setSprite(s2);

      //calcul du score
      /*
      for(int i=0; i<2; i++)
        appart.calculScore(appart.getPlayer(i));

      */

      appart.calculScore(p1);
      appart.calculScore(p2);

      cout<<"gloabl"<<p1.getMyObjets().size()<<endl;
      cout<<"gloabl2"<<appart.getPlayer(0).getMyObjets().size()<<endl;

      updateText(p1.getScore(), p2.getScore());
      updateChrono(chrono);
      window_game.clear();
      appart.inRoom(p1);
      appart.inRoom(p2);
      p1.update(posMonica.x, posMonica.y);
      p2.update(posJoey.x, posJoey.y);

      window_game.draw(appart.getSprite());
      appart.affichage(window_game);

      //window_game.draw(appart.get)
      window_game.draw(p1.getSprite());
      window_game.draw(p2.getSprite());
      window_game.draw(text);
      window_game.draw(time);
      window_game.display();
    }
    else
    {
      //music.stop();
      if(appart.getPlayer(0).getScore()>appart.getPlayer(1).getScore())
      {
        music.stop();
        music_monica.play();
        popUp("Joey t'es nul","WinM.png");
      }
      else
      {
        music.stop();
        music_joey.play();
        popUp("Monica t'es nulle","WinJ.png");
      }

      window_game.close();
    }
  }
}
