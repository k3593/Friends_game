#define CATCH_CONFIG_MAIN // Must only appear in ONE test file
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
#include "objet.hpp"
#include "gameElement.hpp"



TEST_CASE( "player can be created, ses méthodes fonctionnent", "[player]" ) {

    // Pour chaque SECTION, cet initialisation est faite - voir https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md#test-cases-and-sections
    // Et pour plus d'infos : https://github.com/catchorg/Catch2/blob/master/docs/test-cases-and-sections.md#type-parametrised-test-cases
    
    Appartment appart(10, 10, 48, 48, "appart", "apartment.jpeg");
    
    Room room1(10, 10, 90, 350, 120, 120, "Bedroom_chandler");
    appart.addRoom(room1);

    Player p1(1, 2, 3, 4, "p1", "monica.png", appart.getRoom(0));
    appart.addPlayer(p1);

    // Tests constructeur
    REQUIRE(p1.getX() == 1);
    REQUIRE(p1.getY() == 2);
    REQUIRE(p1.getW() == 48);
    REQUIRE(p1.getH() == 48);
    REQUIRE(p1.getName() == "p1");
    REQUIRE(p1.getRoom().getName()== "Bedroom_chandler");

    SECTION( "score" ) 
    {
        //test score
        p1.setScore(3);
        REQUIRE(p1.getScore() == 3);
    }


    SECTION( "room" ) 
    {
        Room room2(10, 10, 90, 350, 120, 120, "Bedroom_Monica");
        appart.addRoom(room2);
        p1.setRoom(room2);
        REQUIRE(p1.getRoom().getName() == "Bedroom_Monica");
    }
    
    
    SECTION( "update" ) 
    {
        p1.update(66,326);
        REQUIRE( p1.getX() == 66);
        REQUIRE( p1.getY() == 326);
    }

}


