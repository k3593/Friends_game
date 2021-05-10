#include "game.hpp"
#include "gameElement.hpp"
#include "appartment.hpp"
#include "menu.hpp"

#include <SFML/Graphics.hpp>
#include <sstream>

Game::Game()
{
  //Création des pièces de l'appartement
  Room room1(10, 10, 120, 370, 120, 120, "Bedroom_chandler");
  Room room2(10, 10, 120, 500, 130, 130, "Bedroom_joey");
  Room room3(10, 10, 280, 400, 180, 130, "Living");
  Room room4(10, 10, 850, 250, 110, 110, "Bedroom_Monica");
  Room room5(5, 5, 610, 220, 70, 80, "Bathroom_Monica");
  Room room6(8, 8, 610, 350, 200, 130, "Living_Monica");
  Room room7(6, 6, 690, 260, 120, 80, "Living_Monica_2");
  Room room8(6, 6, 850, 400, 110, 100, "Guest_room");
  Room room9(6, 6, 360, 220, 70, 80, "Bathroom_Joey");
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

  if(!icone.loadFromFile("icone.png"))
  {
    throw std::runtime_error("impossible de charger image de l'icone");
  }

  initFonts();
  initText();

}

void Game::menu()
{
  sf::RenderWindow window_menu(sf::VideoMode(windowWidht, windowHeight), "Jeu Friends");

  window_menu.setIcon(225, 225,icone.getPixelsPtr());
  //Création du menu
  Menu menu(window_menu.getSize().x, window_menu.getSize().y);

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
                      break;
                    case 2:
                      std::cout << "bouton exit" << std::endl;
                      break;
                  }
              }
              break;
            case sf::Event::Closed:
              window_menu.close();
              break;
          }
      }
      window_menu.clear();
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

void Game::updateText()
{
  std::stringstream ss;
  ss <<"Points de Monica : "<<  appart.getPlayer(0).getScore() <<"\n" << "Points de Joey : "<< appart.getPlayer(1).getScore() ;
  cout << ss.str() <<endl;
  this->text.setString(ss.str());
}

void Game::play()
{
  //Création des joueurs
  Player p1(0, 0, 144, 192, "monica", "monica.png");
  Player p2(0, 0, 144, 192, "joey", "joey.png");
  appart.addPlayer(p1);
  appart.addPlayer(p2);

  appart.calculScore(appart.getPlayer(0));
  appart.calculScore(appart.getPlayer(1));

  appart.calculScore(p1);
  appart.calculScore(p2);

  sf::RenderWindow window_game(sf::VideoMode(windowWidht, windowHeight), "Jeu Friends");
  window_game.setIcon(225, 225,icone.getPixelsPtr());

  //pour l'animation lors des deplacements
  enum Dir{Down, Left, Right, Up};
  sf::Vector2i anim1(1,Down);
  sf::Vector2i anim2(1,Down);
  bool updateFPS1 = false;
  bool updateFPS2 = false;

  //création d'une horloge
  sf::Clock time1;
  sf::Clock time2;
  

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
    }
    sf::Sprite s1=p1.getSprite();
    s1.setTextureRect(sf::IntRect(anim1.x*48, anim1.y*48, 48, 48));
    p1.setSprite(s1);
    sf::Sprite s2=p2.getSprite();
    s2.setTextureRect(sf::IntRect(anim2.x*48, anim2.y*48, 48, 48));
    p2.setSprite(s2);

    //calcul du score
    for(int i=0; i<2; i++)
      appart.calculScore(appart.getPlayer(i));
    /*appart.calculScore(appart.getPlayer(0));
    appart.calculScore(appart.getPlayer(1));
    
    cout <<"Points de Monica : "<<  appart.getPlayer(0).getScore()  << "Points de Joey : "<< appart.getPlayer(0).getScore()<<endl ;*/
    
    

   
    
    updateText();
    p1.getSprite().setPosition(posMonica.x, posMonica.y);
    p1.update(posMonica.x, posMonica.y);
    p2.getSprite().setPosition(posJoey.x, posJoey.y);
    p2.update(posJoey.x, posJoey.y);
    window_game.clear();
    appart.inRoom(p1);
    appart.inRoom(p2);
    window_game.draw(appart.getSprite());
    appart.affichage(window_game);
    window_game.draw(p1.getSprite());
    window_game.draw(p2.getSprite());
    window_game.draw(text);
    window_game.display();
  }
}
