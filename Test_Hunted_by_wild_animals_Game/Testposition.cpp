
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
    int x = 6, y = 5;
    position p{x, y};
    position pT {5,2};
    SUBCASE("Test du constructeur")
    {
        REQUIRE(p.i() == x);
    	REQUIRE(p.j() == y);
    }
    SUBCASE("Test du constructeur par defaut")
    {
        REQUIRE(p.i() == 0);
    	REQUIRE(p.j() == 0);
    }
    SUBCASE("Test de l'operator ==")
    {
        position p{6,5};
        REQUIRE_EQ(p, p);
    }
    SUBCASE("Test de l'operator !=")
    {
        REQUIRE_NE(pT, p);
    }
}

#endif //TESTPOINT_H
