#include "catch.hpp"
//Ou si installé par la distribution : #include <catch2/catch.hpp>

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "door.hpp"

TEST_CASE( "door can be created", "[door]" ) 
{

    // Pour chaque SECTION, cet initialisation est faite - voir https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md#test-cases-and-sections
    // Et pour plus d'infos : https://github.com/catchorg/Catch2/blob/master/docs/test-cases-and-sections.md#type-parametrised-test-cases
    
    Door door(0, 1, 2, 3,"door",4,5);
    

    // Tests constructeur
    REQUIRE(door.getX() == 0);
    REQUIRE(door.getY() == 1);
    REQUIRE(door.getW() == 2);
    REQUIRE(door.getH() == 3);
    REQUIRE(door.getAngle() == 4);
    REQUIRE(door.getCote() == 5);
    REQUIRE(door.getName() == "door");


}