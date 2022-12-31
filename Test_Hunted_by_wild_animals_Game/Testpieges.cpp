#ifndef TESTPIEGES_H
#define TESTPIEGES_H

#include "doctest.h"
#include <sstream>
#include <string>
#include "../Hunted_by_wild_animals_Game/pieges.h"

using std::ostringstream;
using std::string;

TEST_CASE("Construction du piège")
{
        SUB_CASE("Le piège est construit à un point donné")
        {
            pieges p{position{14, 9}};
            REQUIRE_EQ(p.posElem().i(), 14);
            REQUIRE_EQ(p.posElem().j(), 9);
        }

        SUB_CASE("Le piège est construit à (0;0)")
        {
            pieges p{};
            REQUIRE_EQ(p.posElem().i(), 0);
            REQUIRE_EQ(p.posElem().j(), 0);
        }
}

#endif