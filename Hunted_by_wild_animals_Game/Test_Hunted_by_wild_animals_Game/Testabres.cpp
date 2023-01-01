/*
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
        SUB_CASE("L'arbre est construit à un point donné")
        {
            arbres a{position{20,15}};
            REQUIRE_EQ(a.posElem().i(), 20);
            REQUIRE_EQ(a.posElem().j(), 20);
        }

        SUB_CASE("L'arbre est construit à (0;0)")
        {
            arbres a{};
            REQUIRE_EQ(a.posElem().i(), 0);
            REQUIRE_EQ(a.posElem().j(), 0);
        }
}

#endif
*/
