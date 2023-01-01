
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
        REQUIRE_EQ(p.getI() == x);
    	REQUIRE_EQ(p.getJ() == y);
    }
    /*SUBCASE("Test du constructeur par defaut")
    {
        REQUIRE_EQ(p.getI() == 0);
    	REQUIRE_EQ(p.getJ() == 0);
    }
    SUBCASE("Test de l'operator ==")
    {
        position p{6,5};
        REQUIRE_EQ(p, p);
    }
    SUBCASE("Test de l'operator !=")
    {
        REQUIRE_NE(pT, p);
    }*/
}

#endif //TESTPOINT_H
