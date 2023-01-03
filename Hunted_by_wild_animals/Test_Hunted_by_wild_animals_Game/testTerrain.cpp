#include "doctest.h"
#include "../Hunted_by_wild_animals_Game/terrain.h"
#include <string>

TEST_CASE ("Test de la classe terrain")
{
    int hauteur=2;
    int largeur=4;
    int x=3;
    int y=5;
    SUBCASE("Test du constructeur")
    {
       SUBCASE("Test du constructeur par defaut")
        {
            terrain t{};
            REQUIRE_EQ(t.hauteur(),0);
            REQUIRE_EQ(t.largeur(),0);
            //REQUIRE_EQ(t.tabElements(),nullptr);
            //REQUIRE_EQ(t.tabPositionFauves(),nullptr);
            REQUIRE_EQ(t.nombreFauves(),0);
        }
        SUBCASE("Test du constructeur")
        {
            terrain t{hauteur,largeur};
            REQUIRE_EQ(t.hauteur(),2);
            REQUIRE_EQ(t.largeur(),4);
            //REQUIRE_EQ(t.tabElements(),nullptr);
            //REQUIRE_EQ(t.tabPositionFauves(),nullptr);
            REQUIRE_EQ(t.nombreFauves(),0);
        }
    }
}
