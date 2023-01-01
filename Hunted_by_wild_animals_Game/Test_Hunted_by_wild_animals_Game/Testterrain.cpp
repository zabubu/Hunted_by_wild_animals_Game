/*
#ifndef TESTTERRAIN_H
#define TESTTERRAIN_H

#include "doctest.h"
#include <sstream>
#include <string>
#include "../Hunted_by_wild_animals_Game/terrain.h"

using std::ostringstream;
using std::string;


TEST_CASE("0 - Test de la classe grille")

    int a = 1, b = 2, c = 3, d = 4, e = 5;
    terrain t {a,b,c,d,e};
    terrain test{}:

    SUBCASE("Test du constructeur")
    {
        REQUIRE(t.nombreElements() == c);
    	REQUIRE(t.nombreFauves() == 0);
        REQUIRE(t.nombrePieges() == 0);
        REQUIRE(t.nombreMaxFauves() == d);
        REQUIRE(t.nombreMaxPieges() == e);
    }
    SUBCASE("Test du constructeur par defaut")
    {
        REQUIRE(test.nombreElements() == 0);
        REQUIRE(test.nombreFauves() == 0);
        REQUIRE(test.nombrePieges() == 0);
        REQUIRE(test.nombreMaxFauves() == 0);
        REQUIRE(test.nombreMaxPieges() == 0);
    }
    SUBCASE("Test de la fonction modifierNbFauvesMax")
    {
        REQUIRE(g.renvoiHauteur() == FMax);
    }
    SUBCASE("Test de la fonction modifierNbPiegesMax")
    {
        REQUIRE(t.nombreMaxPieges() == PMax);
    }
}

#endif //TESTTERRAIN_H
*/
