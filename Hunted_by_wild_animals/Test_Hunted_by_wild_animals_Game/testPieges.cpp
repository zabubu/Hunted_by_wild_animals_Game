#ifndef TESTPIEGES_H
#define TESTPIEGES_H

#include "doctest.h"
#include "../Hunted_by_wild_animals_Game/pieges.h"



TEST_CASE("Test de la classe piege")
{
    int i = 2, j = 4;
    position posPiege{i,j};
    pieges p{posPiege};
    SUBCASE("Test du constructeur")
    {
        REQUIRE_EQ(p.posElem(),posPiege);
    }
}

#endif
