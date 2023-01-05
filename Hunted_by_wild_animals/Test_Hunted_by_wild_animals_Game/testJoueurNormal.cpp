#ifndef TESTJOUEURNORMAL_H
#define TESTJOUEURNORMAL_H

#include "doctest.h"
#include "../Hunted_by_wild_animals_Game/joueurNormal.h"
#include "../Hunted_by_wild_animals_Game/terrain.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

const int DIRECTION_HAUT = 8;

TEST_CASE("Test de la classe joueurNormal")
{

    int i =1, j = 3;
    position posJoueurN{i,j};
    joueurNormal joueurN{posJoueurN};
    SUBCASE("Test du constructeur")
    {

        REQUIRE_EQ(joueurN.posElem(), posJoueurN);
    }
    SUBCASE("Test de la methode clone")
    {

        auto nouveauJoueurN= joueurN.clone();

        REQUIRE_EQ(joueurN.posElem(), nouveauJoueurN->posElem());
    }
    SUBCASE("Test du deplacement du joueur")
    {
        terrain t{};
        std::string terrain = "[" + std::to_string(4) + ";" +  std::to_string(5) + "]" + "\n" +
                                    ".....\n" +
                                    "...J.\n" +
                                    ".....\n" +
                                    ".....\n" ;
        std::stringstream ist;
        for(auto c : terrain)
        {
            ist << c;
        }
        t.lireDepuisFichier(ist);

        joueurN.deplaceJoueur(t,DIRECTION_HAUT);

        std::string terrainAttendu = "[" + std::to_string(4) + ";" +  std::to_string(5) + "]" + "\n" +
                                    "...J.\n" +
                                    ".....\n" +
                                    ".....\n" +
                                    ".....\n" ;



        std::stringstream ost;
        t.enregistreDansFichier(ost);
        std::string terrainEnregistre = ost.str();
        REQUIRE_EQ(terrainEnregistre, terrainAttendu);
    }

}

#endif


