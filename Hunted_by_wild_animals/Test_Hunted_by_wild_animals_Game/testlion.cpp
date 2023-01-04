#ifndef TESTLION_H
#define TESTLION_H

#include "doctest.h"
#include <sstream>
#include <string>
#include "../Hunted_by_wild_animals_Game/lion.h"
#include "../Hunted_by_wild_animals_Game/terrain.h"
#include "../Hunted_by_wild_animals_Game/joueur.h"
#include "../Hunted_by_wild_animals_Game/joueurNormal.h"

using std::ostringstream;
using std::string;
TEST_CASE("Les opérations sur les lions sont correctes")
{
    SUBCASE("Deplacer un lion ")
    {
        position p{5,4};
        position pT{4,3};
        joueurNormal j{p};
        position pL{3,3};
        lion L{pL};
        terrain t{5,5};
        L.deplace(t);
        REQUIRE_EQ(L.posElem().getJ(),pT.getJ());
    }
}

#endif
