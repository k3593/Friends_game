#include "catch.hpp"
//Ou si installé par la distribution : #include <catch2/catch.hpp>

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "bonus.hpp"




TEST_CASE( "bonus can be created", "[bonus]" ) {

    // Pour chaque SECTION, cet initialisation est faite - voir https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md#test-cases-and-sections
    // Et pour plus d'infos : https://github.com/catchorg/Catch2/blob/master/docs/test-cases-and-sections.md#type-parametrised-test-cases
    
    Bonus bonus(0, 1);
    

    // Tests constructeur
    REQUIRE(bonus.getX() == 0);
    REQUIRE(bonus.getY() == 1);
    REQUIRE(bonus.getW() == 10);
    REQUIRE(bonus.getH() == 10);
    REQUIRE(bonus.getScore() == 10);
    REQUIRE(bonus.getName() == "bonus");

}