#ifndef TESTLION_H
#define TESTLION_H

#include "doctest.h"
#include "../Hunted_by_wild_animals_Game/lion.h"

TEST_CASE("Test de la classe lion")
{
        int i = 2, j = 4;
        position posLion{i,j};
        lion l{posLion};
    SUBCASE("Test du constructeur")
    {

        REQUIRE_EQ(l.posElem(), posLion);
    }
}

#endif

