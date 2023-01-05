#ifndef TESTARBRES_H
#define TESTARBRES_H

#include "doctest.h"
#include "../Hunted_by_wild_animals_Game/arbres.h"

TEST_CASE("Teste de la classe arbre")
{
    int i = 2, j = 4;
    position posArbre{i,j};
    arbres a{posArbre};
    SUBCASE("Test du constructeur")
    {
        REQUIRE_EQ(a.posElem(), posArbre);
    }
}

#endif
