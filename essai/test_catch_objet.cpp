#include "catch.hpp"
//Ou si installé par la distribution : #include <catch2/catch.hpp>

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "objet.hpp"




TEST_CASE( "objet can be created", "[objet]" ) {

    // Pour chaque SECTION, cet initialisation est faite - voir https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md#test-cases-and-sections
    // Et pour plus d'infos : https://github.com/catchorg/Catch2/blob/master/docs/test-cases-and-sections.md#type-parametrised-test-cases
    
    Objet objet("name", "bonus.png",0, 1);
    

    // Tests constructeur
    REQUIRE(objet.getX() == 0);
    REQUIRE(objet.getY() == 1);
    REQUIRE(objet.getW() == 10);
    REQUIRE(objet.getH() == 10);
    REQUIRE(objet.getScore() == 10);
    REQUIRE(objet.getName() == "name");

}