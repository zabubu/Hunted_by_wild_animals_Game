#ifndef TESTPOINT_H
#define TESTPOINT_H

#include "doctest.h"
#include <sstream>
#include <string>
#include "../Hunted_by_wild_animals_Game/position.h"

using std::ostringstream;
using std::string;


TEST_CASE("0 - Test de la classe position")
{
    double x = 6.1, y = 5.8;
    double random_double = 10.5;
    point Testpoint{x, y};
    point p_2 {5,2.2};
    point pointTestVide{};
    SUBCASE("Test du constructeur")
    {
        REQUIRE(p.renvoyerX() == x);
    	REQUIRE(p.renvoyerY() == y);
    }
    SUBCASE("Test du constructeur par defaut")
    {
        REQUIRE(p.renvoyerX() == 0);
    	REQUIRE(p.renvoyerY() == 0);
    }
    SUBCASE("Test de l'operator ==")
    {
        point p{6.1,5.8};
        REQUIRE_EQ(p, Testpoint);
    }
    SUBCASE("Test de l'operator !=")
    {
        REQUIRE_NE(p_2, Testpoint);
    }
}

#endif //TESTPOINT_H