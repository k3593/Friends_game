#include "gameElement.hpp"
#include "player.hpp"
#include "room.hpp"
#include "appartment.hpp"

int main(int argc, char ** argv)
{

    float windowHeight = 721;
    float windowWidht = 1109;
    //pour l'animation lors des deplacements
    enum Dir{Down, Left, Right, Up};
    sf::Vector2i anim1(1,Down);
    sf::Vector2i anim2(1,Down);
    bool updateFPS = true;
    //Création des joueurs
    Player p1(0, 0, 144, 192, "monica", "monica.png");
    Player p2(0, 0, 144, 192, "joey", "joey.png");
    //Création de l'appartement
    Appartment appart(10, 10, 10, 10, "appart", "apartment.png");
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

    //appart.inRoom(p1).state(p1);
    //appart.inRoom(p1).state(p1);


    sf::RenderWindow window(sf::VideoMode(windowWidht, windowHeight), "Jeu Friends");
    //icone
    sf::Image icone;
    if(!icone.loadFromFile("icone.png"))
    {
      throw std::runtime_error("impossible de charger image de l'icone");
    }
    window.setIcon(225, 225,icone.getPixelsPtr());

    appart.calculScore(p1);
    appart.calculScore(p2);

    //création d'une horloge
    sf::Clock time;
    float countFps=0;
    float switchFps=100;
    float speedFps=500;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Resized)
            {
                // récupération de la taille de la fenêtre
                sf::Vector2u size = window.getSize();

                float ratio(windowHeight/windowWidht);
                size.y=(unsigned int) (ratio*size.x);
                window.setSize(size);
            }
            if (event.type == sf::Event::Closed)
                window.close();
        }

	    sf::Vector2f posMonica = p1.getSprite().getPosition();
        sf::Vector2f posJoey = p2.getSprite().getPosition();
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
        if(updateFPS)
            countFps+=speedFps*time.restart().asSeconds();
        else
            countFps=0;

        if(countFps>=switchFps)
        {
            anim1.x++;
            if(anim1.x*48 >= p1.getW()*3)
                anim1.x=0;
            sf::Sprite s1=p1.getSprite();
            s1.setTextureRect(sf::IntRect(anim1.x*48, anim1.y*48, 48, 48));
            p1.setSprite(s1);

            anim2.x++;
            if(anim2.x*48 >= p2.getW()*3)
                anim2.x=0;
            sf::Sprite s2=p2.getSprite();
            s2.setTextureRect(sf::IntRect(anim2.x*48, anim2.y*48, 48, 48));
            p2.setSprite(s2);
        }


        p1.getSprite().setPosition(posMonica.x, posMonica.y);
        p1.update(posMonica.x, posMonica.y);
        p2.getSprite().setPosition(posJoey.x, posJoey.y);
        p2.update(posJoey.x, posJoey.y);
        window.clear();
        appart.inRoom(p1);
        appart.inRoom(p2);
        window.draw(appart.getSprite());
        window.draw(room1.getRectangle());
        window.draw(room2.getRectangle());
        window.draw(room3.getRectangle());
        window.draw(room4.getRectangle());
        window.draw(room5.getRectangle());
        window.draw(room6.getRectangle());
        window.draw(room7.getRectangle());
        window.draw(room8.getRectangle());
        window.draw(room9.getRectangle());
        appart.affichage(window);
        window.draw(p1.getSprite());
        window.draw(p2.getSprite());
        window.display();
    }

    return 0;
}
