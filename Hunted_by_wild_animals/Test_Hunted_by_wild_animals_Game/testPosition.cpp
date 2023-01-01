#include "doctest.h"
#include "../Hunted_by_wild_animals_Game/position.h"
#include <string>

TEST_CASE ("Test de la classe position")
{
    SUBCASE("Test du constructeur")
    {
        int i=2,j=4;
        position p{i,j};

        SUBCASE("la position est correcte")
        {
            REQUIRE_EQ(p.getI(),i);
            REQUIRE_EQ(p.getJ(),j);
        }
    }
}
