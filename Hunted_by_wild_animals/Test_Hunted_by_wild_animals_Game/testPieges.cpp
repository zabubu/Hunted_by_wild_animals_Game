#ifndef TESTARBRES_H
#define TESTARBRES_H

#include "doctest.h"
#include <sstream>
#include <string>
#include "../Hunted_by_wild_animals_Game/pieges.h"

using std::ostringstream;
using std::string;

TEST_CASE("Construction du piege")
{
    SUBCASE("Test du constructeur")
    {
        int i = 2, j = 4;
        position pos{i,j};
        pieges p{pos};
        REQUIRE_EQ(p.posElem().getI(),i);
        REQUIRE_EQ(p.posElem().getJ(),j);
    }
}

#endif
