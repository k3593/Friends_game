#include "friends.hpp"

int main(int argc, char ** argv)
{

    float windowHeight = 946;
	float windowWidht = 1350;
    
    sf::RenderWindow window(sf::VideoMode(windowWidht, windowHeight), "Jeu Friends");
    Player p1(10, 10, 10, 10, "theo", "monica.png");
    Appartment appart(10, 10, 10, 10, "appart", "apartment.png");
    
    sf::Image icone;
    if(!icone.loadFromFile("icone.png"))
	{
		throw std::runtime_error("impossible de chatger image de l'icone");
	}	

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // resize en gardant le ratio de la photo originale
			//il faudrait metre un size.y max => taille de l'écran
            if (event.type == sf::Event::Resized)
            {
                    // récupération de la taille de la fenêtre
                    sf::Vector2u size = window.getSize();

                    float ratio(windowHeight/windowWidht);
                    size.y=(unsigned int) (ratio*size.x);
                    window.setSize(size);
            }
			//si l'utilisateur veux fermer la fenetre
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // gestion du déplacment d'un joueur (ne devrait pas etre une méthode ?)
		sf::Vector2f posMonica = p1.getSprite().getPosition();
		float nx=posMonica.x;
		float ny=posMonica.y;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			//if (!(spriteBackground.getGlobalBounds().intersects(spriteMonica.getGlobalBounds())))
				nx = nx-1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			//if ((spriteBackground.getGlobalBounds().intersects(spriteMonica.getGlobalBounds()))==false)
				nx = nx+1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			//if (!(spriteBackground.getGlobalBounds().intersects(spriteMonica.getGlobalBounds())))
        	//{
				ny = ny-1;
			//}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			//if (!(spriteBackground.getGlobalBounds().intersects(spriteMonica.getGlobalBounds())))
        	//{
				ny = ny+1;
			//}
		}
        p1.getSprite().setPosition(posMonica.x, posMonica.y+1);

        window.clear();
        window.draw(appart.getSprite());
		window.draw(p1.getSprite());
        window.display();
    }

    return 0;
}