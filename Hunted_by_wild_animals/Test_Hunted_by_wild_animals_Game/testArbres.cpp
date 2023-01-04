#ifndef TESTARBRES_H
#define TESTARBRES_H

#include "doctest.h"
#include <sstream>
#include <string>
#include "../Hunted_by_wild_animals_Game/arbres.h"

using std::ostringstream;
using std::string;

TEST_CASE("Construction de l'arbre")
{
    SUBCASE("Test du constructeur")
    {
        int i = 2, j = 4;
        position p{i,j};
        arbres a{p};
        REQUIRE_EQ(a.posElem().getI(),i);
        REQUIRE_EQ(a.posElem().getJ(),j);
    }
}

#endif
