#include "doctest.h"
#include "../Hunted_by_wild_animals_Game/position.h"
#include <string>

TEST_CASE ("Test de la classe position")
{
    int i=2,j=4;
    SUBCASE("Test du constructeur")
    {
        SUBCASE("la position est correcte")
        {
            position p{i,j};
            REQUIRE_EQ(p.getI(),i);
            REQUIRE_EQ(p.getJ(),j);
        }
        SUBCASE("Test du constructeur par defaut")
        {
            position p{};
            REQUIRE_EQ(p.getI(),0);
            REQUIRE_EQ(p.getJ(),0);
        }
    }
    SUBCASE("Test des fonctions set")
    {
        position p{};
        p.setI(i);
        p.setJ(j);
        REQUIRE_EQ(p.getI(),i);
    	REQUIRE_EQ(p.getJ(),j);
    }
    SUBCASE("Test de l'operator =")
    {
        position p{i,j};
        position pT = p;
        REQUIRE_EQ(p, pT);
    }
    SUBCASE("Test de l'operator ==")
    {
        position p{i,j};
        position pT{i,j};
        REQUIRE_EQ(p, pT);
    }
    SUBCASE("Test de l'operator !=")
    {
        position p{i,j};
        position pT{i+1,j+1};
        REQUIRE_NE(pT, p);
    }
}
