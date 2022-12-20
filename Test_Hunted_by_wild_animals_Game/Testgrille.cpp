#ifndef TESTGRILLE_H
#define TESTGRILLE_H

#include "doctest.h"
#include <sstream>
#include <string>
#include "../Hunted_by_wild_animals_Game/grille.h"

using std::ostringstream;
using std::string;


TEST_CASE("0 - Test de la classe grille")

    int x = 6, y = 5;
    grille Testgrille{x, y};
    grille g {8,2};
    SUBCASE("Test du constructeur")
    {
        REQUIRE(g.renvoiHauteur() == x);
    	REQUIRE(g.renvoiLargeur() == y);
    }
    SUBCASE("Test du constructeur par defaut")
    {
        REQUIRE(g.renvoiHauteur() == 0);
    	REQUIRE(g.renvoiLargeur() == 0);
    }
    SUBCASE("Test de la fonction modifierhauteur")
    {
        REQUIRE(g.renvoiHauteur() == h);
    }
    SUBCASE("Test de la fonction modifierlargeur")
    {
        REQUIRE(g.renvoiLargeur() == l);
    }
}

#endif //TESTGRILLE_H