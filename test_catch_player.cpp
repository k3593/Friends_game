#define CATCH_CONFIG_MAIN // Must only appear in ONE test file
#include "catch.hpp"
//Ou si installé par la distribution : #include <catch2/catch.hpp>

#include "player.hpp"
#include "appartment.hpp"
#include "room.hpp"



TEST_CASE( "player can be created, ses méthodes fonctionnent", "[player]" ) {

    // Pour chaque SECTION, cet initialisation est faite - voir https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md#test-cases-and-sections
    // Et pour plus d'infos : https://github.com/catchorg/Catch2/blob/master/docs/test-cases-and-sections.md#type-parametrised-test-cases
    Appartment appart{10, 10, 10, 10, "appart", "apartment.jpeg"};

    Room room1(10, 10, 90, 350, 120, 120, "Bedroom_chandler");

    appart.addRoom(room1);

    Player p1(1, 2, 3, 4, "p1", "filename", appart.getRoom(1));


    // Tests constructeur
    REQUIRE(p1.getX() == 1);
    REQUIRE(p1.getY() == 2);
    REQUIRE(p1.getW() == 3);
    REQUIRE(p1.getH() == 4);
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

    SECTION( "sprite" )
    {
        sf::Sprite sprite;
        p1.setSprite(sprite);
        //REQUIRE(p1.getSprite() == sprite);
    }

    SECTION( "update" )
    {
        p1.update(5,6);
        REQUIRE( p1.getX() == 5);
        REQUIRE( p1.getY() == 6);
    }

}
