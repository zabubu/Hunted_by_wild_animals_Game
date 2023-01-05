#ifndef TESTLION_H
#define TESTLION_H

#include "doctest.h"
#include "../Hunted_by_wild_animals_Game/lion.h"
#include "../Hunted_by_wild_animals_Game/terrain.h"

TEST_CASE("Test de la classe lion")
{
    int i =1, j = 3;
    position posLion{i,j};
    lion l{posLion};
    SUBCASE("Test du constructeur")
    {

        REQUIRE_EQ(l.posElem(), posLion);
    }
    SUBCASE("Test de la methode clone")
    {

        auto nouveauLion = l.clone();

        REQUIRE_EQ(l.posElem(), nouveauLion->posElem());
    }
    SUBCASE("Test du deplacement du lion")
    {
        terrain t{};
        std::string terrain = "[" + std::to_string(hauteur) + ";" +  std::to_string(largeur) + "]" + "\n" +
                                    ".....\n" +
                                    "...L.\n" +
                                    ".....\n" +
                                    "...J.\n" ;
        std::stringstream ist;
        for(auto c : terrain)
        {
            ist << c;
        }
        t.lireDepuisFichier(ist);

        l.deplace(t);




    }

}

#endif

