#include "catch.hpp"
//Ou si installé par la distribution : #include <catch2/catch.hpp>

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "player.hpp"
#include "appartment.hpp"
#include "room.hpp"
#include "gameElement.hpp"



TEST_CASE( "appart can be created, ses méthodes fonctionnent", "[appartment]" ) {

    // Pour chaque SECTION, cet initialisation est faite - voir https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md#test-cases-and-sections
    // Et pour plus d'infos : https://github.com/catchorg/Catch2/blob/master/docs/test-cases-and-sections.md#type-parametrised-test-cases
    
    Appartment appart(10, 11, 12, 13, "appart", "apartment.jpeg");
    Room room1(1, 1, 90, 350, 120, 120, "Bedroom_chandler");
    
    

    // Tests constructeur
    REQUIRE(appart.getX() == 10);
    REQUIRE(appart.getY() == 11);
    REQUIRE(appart.getW() == 12);
    REQUIRE(appart.getH() == 13);
    REQUIRE(appart.getName() == "appart");

    SECTION( "addRoom" ) 
    {
        REQUIRE(appart.getRooms().size() == 0);
        
        appart.addRoom(room1);
       
        REQUIRE(appart.getRooms().size() == 1);
    }

    SECTION( "addPlayer" ) 
    {
        appart.addRoom(room1);
        Player p1(1, 2, 3, 4, "p1", "monica.png", appart.getRoom(0));
        appart.addPlayer(p1);
        REQUIRE(appart.getPlayer(0).getName() == "p1");
    }

    SECTION( "calculScore" ) 
    {
        appart.addRoom(room1);
        Player p1(1, 2, 3, 4, "p1", "monica.png", appart.getRoom(0));
        appart.addPlayer(p1);
        appart.calculScore(p1);
        REQUIRE(p1.getScore() == 0) ;
       
    }

    

}


