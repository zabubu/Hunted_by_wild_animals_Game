#ifndef TESTTIGRE_H
#define TESTTIGRE_H

#include "doctest.h"
#include "../Hunted_by_wild_animals_Game/tigre.h"
#include "../Hunted_by_wild_animals_Game/terrain.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

TEST_CASE("Test de la classe tigre")
{
    int i =1, j = 1;
    position posTigre{i,j};
    tigre t{posTigre};
    SUBCASE("Test du constructeur")
    {

        REQUIRE_EQ(t.posElem(), posTigre);
    }
    SUBCASE("Test de la methode clone")
    {

        auto nouveauTigre = t.clone();

        REQUIRE_EQ(t.posElem(), nouveauTigre->posElem());
    }
    SUBCASE("Test du deplacement du lion")
    {
        terrain ter{};
        std::string terrain = "[" + std::to_string(4) + ";" +  std::to_string(5) + "]" + "\n" +
                                    ".....\n" +
                                    ".T...\n" +
                                    ".....\n" +
                                    "...J.\n" ;
        std::stringstream ist;
        for(auto c : terrain)
        {
            ist << c;
        }
        ter.lireDepuisFichier(ist);

        t.deplace(ter);

        std::string terrainAttendu = "[" + std::to_string(4) + ";" +  std::to_string(5) + "]" + "\n" +
                                    ".....\n" +
                                    ".....\n" +
                                    "..T..\n" +
                                    "...J.\n" ;



        std::stringstream ost;
        ter.enregistreDansFichier(ost);
        std::string terrainEnregistre = ost.str();
        REQUIRE_EQ(terrainEnregistre, terrainAttendu);
    }

}

#endif


