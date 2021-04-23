#include "friends.hpp"

int main(int argc, char ** argv)
{

    float windowHeight = 721;
    float windowWidht = 1109;
    //Création des joueurs
    Player p1(0, 0, 35, 35, "monica", "monica.png");
    Player p2(0, 0, 35, 35, "joey", "monica.png");
    //Création de l'appartement
    Appartment appart(10, 10, 10, 10, "appart", "apartment.png");
    //Création des pièces de l'appartement
    Room room1(10, 10, 120, 370, 120, 120, "Bathroom");
    Room room2(10, 10, 120, 500, 130, 130, "Bedroom");
    Room room3(10, 10, 300, 400, 130, 130, "Living");
    Room room4(10, 10, 850, 250, 110, 110, "Bedroom_Monica");
    Room room5(5, 5, 610, 220, 70, 80, "Bathroom_Monica");
    Room room6(8, 8, 610, 350, 200, 130, "Living_Monica");
    Room room7(8, 8, 610, 350, 200, 130, "Living_Monica_2");
    //Remplissage de l'appartement avec les pièces
    appart.addRoom(room1);
    appart.addRoom(room2);
    appart.addRoom(room3);
    appart.addRoom(room4);
    appart.addRoom(room5);
    appart.addRoom(room6);
    appart.addRoom(room7);

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
      posMonica.x = posMonica.x-1;
      posMonica.y = posMonica.y;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
      posMonica.x = posMonica.x + 1;
      posMonica.y = posMonica.y;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
      posMonica.x = posMonica.x;
      posMonica.y = posMonica.y-1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
      posMonica.x = posMonica.x;
      posMonica.y = posMonica.y + 1;
		}

    //Joey
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		{
      posJoey.x = posJoey.x-1;
      posJoey.y = posJoey.y;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
      posJoey.x = posJoey.x + 1;
      posJoey.y = posJoey.y;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		{
      posJoey.x = posJoey.x;
      posJoey.y = posJoey.y-1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
      posJoey.x = posJoey.x;
      posJoey.y = posJoey.y + 1;
		}
        p1.getSprite().setPosition(posMonica.x, posMonica.y);
        p1.update(posMonica.x, posMonica.y);
        p2.getSprite().setPosition(posJoey.x, posJoey.y);
        p2.update(posJoey.x, posJoey.y);
        appart.calculScore(p1);
        appart.calculScore(p2);
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
        room1.affichage(window);
        room2.affichage(window);
        room3.affichage(window);
        room4.affichage(window);
        room5.affichage(window);
        room6.affichage(window);
        room7.affichage(window);
        window.draw(p1.getSprite());
        window.draw(p2.getSprite());
        window.display();
    }

    return 0;
}