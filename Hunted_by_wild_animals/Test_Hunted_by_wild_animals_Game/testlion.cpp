#ifndef TESTLION_H
#define TESTLION_H

#include "doctest.h"
#include <sstream>
#include <string>
#include "../Hunted_by_wild_animals_Game/lion.h"

using std::ostringstream;
using std::string;
/*TEST_CASE("Les opérations sur les lions sont correctes")
{
    SUBCASE("Deplacer un lion ")
    {
        position p{4,3};
        position pL{3,3};
        lion L{pL};
        terrain t{5,5,nullptr,nullptr,5};
        int direction = 2;
        L.deplace(t,direction);
        REQUIRE_EQ(L.posElem(),p);
    }
}*/

#endif
