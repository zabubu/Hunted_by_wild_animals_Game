#ifndef TESTTERRAIN_H
#define TESTTERRAIN_H

#include "doctest.h"
#include "../Hunted_by_wild_animals_Game/terrain.h"
#include "../Hunted_by_wild_animals_Game/position.h"
#include "../Hunted_by_wild_animals_Game/tigre.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>


TEST_CASE("Test de la classe terrain")
{
    int hauteur = 4;
    int largeur = 5;
    terrain t{hauteur,largeur};

    SUBCASE("Test du constructeur")
    {
        REQUIRE_EQ(t.hauteur(), hauteur);
        REQUIRE_EQ(t.largeur(), largeur);
        REQUIRE_EQ(t.nombreFauves(),0);
        for(unsigned i = 0; i < hauteur; ++i)
            REQUIRE_EQ(t.tabElements()[i].size(), largeur);
    }
    SUBCASE("Test  fonction modifierTaille")
    {
        int nouvelleHauteur = 7, nouvelleLargeur = 8;

        t.modifierTaille(nouvelleHauteur,nouvelleLargeur);

        REQUIRE_EQ(t.hauteur(), nouvelleHauteur );
        REQUIRE_EQ(t.largeur(), nouvelleLargeur);
        for(unsigned i = 0; i < nouvelleHauteur; ++i)
            REQUIRE_EQ(t.tabElements()[i].size(), nouvelleLargeur);

    }
    SUBCASE("Test de la fonction lireDepuisFichier")
    {
        std::string terrain = "[" + std::to_string(hauteur) + ";" +  std::to_string(largeur) + "]" + "\n" +
                                    "T....\n" +
                                    ".L...\n" +
                                    ".....\n" +
                                    "...J.\n" ;
        std::stringstream ist;
        for(auto c : terrain)
        {
            ist << c;
        }
        t.lireDepuisFichier(ist);

        REQUIRE_EQ(t.hauteur(), hauteur);
        REQUIRE_EQ(t.largeur(), largeur);
        REQUIRE_EQ(t.nombreFauves(), 2);
        for(unsigned i = 0; i < hauteur; ++i)
            REQUIRE_EQ(t.tabElements()[i].size(), largeur);
    }
    SUBCASE("Test de la fonction enregistreDansFichier")
    {
        std::string fichierAttendu = "["+ std::to_string(hauteur) + ";" +  std::to_string(largeur) + "]" + "\n" +
                                    ".....\n" +
                                    ".....\n" +
                                    ".....\n" +
                                    ".....\n" ;
        std::stringstream ost;
        t.enregistreDansFichier(ost);
        std::string terrainEnregistre = ost.str();
        REQUIRE_EQ(terrainEnregistre, fichierAttendu);
    }
    SUBCASE("Test de la fonction permettant de recuperer la position du joueur")
    {
        std::string terrain = "["+ std::to_string(hauteur) + ";" +  std::to_string(largeur) + "]" + "\n" +
                                    ".....\n" +
                                    "..J..\n" +
                                    ".....\n" +
                                    ".....\n" ;
        std::stringstream ist;
        for(auto c : terrain)
        {
            ist << c;
        }
        t.lireDepuisFichier(ist);

        position posAttendu{1,2};
        position posJoueur = t.posJoueur();

        REQUIRE_EQ(posAttendu, posJoueur);
    }
    SUBCASE("Test de la fonction ajouter un element")
    {
        std::string terrain = "[" + std::to_string(hauteur) + ";" +  std::to_string(largeur) + "]" + "\n" +
                                    "T....\n" +
                                    ".L...\n" +
                                    ".....\n" +
                                    "...J.\n" ;
        std::stringstream ist;
        for(auto c : terrain)
        {
            ist << c;
        }
        t.lireDepuisFichier(ist);

        std::string terrainAttendu = "[" + std::to_string(hauteur) + ";" +  std::to_string(largeur) + "]" + "\n" +
                                    "T....\n" +
                                    ".L...\n" +
                                    ".....\n" +
                                    ".T.J.\n" ; //Ajout d'un tigre

        position posTigre{3,1};
        t.ajouterElement(std::make_unique<tigre>(posTigre), posTigre);

        std::stringstream ost;
        t.enregistreDansFichier(ost);
        std::string terrainEnregistre = ost.str();
        REQUIRE_EQ(terrainEnregistre, terrainAttendu);
    }
}
#endif // TESTTERRAIN_H
