#include "catch.hpp"
//Ou si installé par la distribution : #include <catch2/catch.hpp>

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "room.hpp"
#include "objet.hpp"
#include "door.hpp"



TEST_CASE( "room can be created, ses méthodes fonctionnent", "[room]" ) {

    // Pour chaque SECTION, cet initialisation est faite - voir https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md#test-cases-and-sections
    // Et pour plus d'infos : https://github.com/catchorg/Catch2/blob/master/docs/test-cases-and-sections.md#type-parametrised-test-cases
    
    Room room(0,1,2,3,4,5,"room");
    
    

    // Tests constructeur
    REQUIRE(room.getL() == 0);
    REQUIRE(room.getC() == 1);
    REQUIRE(room.getX() == 2);
    REQUIRE(room.getY() == 3);
    REQUIRE(room.getW() == 4);
    REQUIRE(room.getH() == 5);
    REQUIRE(room.getName() == "room");

    SECTION( "ajout de porte" ) 
    {
        REQUIRE(room.getDoors().size() == 0) ;
        Door door(0, 1, 2, 3,"door",4,5);
        room.addDoor(door);
        REQUIRE(room.getDoors().size() == 1);
       
    }
    SECTION( "ajout d'objet" ) 
    {
        REQUIRE(room.getObjets().size() == 0) ;
        Objet bonus("bonus","bonus.png",0, 1);
        room.addObjet(&bonus);
        REQUIRE(room.getObjets().size() == 1);
       
    }

}