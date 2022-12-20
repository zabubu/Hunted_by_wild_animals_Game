#ifndef TESTJOUEUR_H
#define TESTJOUEUR_H

#include "doctest.h"
#include <sstream>
#include <string>
#include "../Hunted_by_wild_animals_Game/joueur.h"

using std::ostringstream;
using std::string;


TEST_CASE("0 - Test de la classe joueur")
{
    int x = 6, y = 5;
    int x2 = 10, y2 = 20;
    joueur Testjoueur{x, y};
    joueur p {};
    SUBCASE("Test du constructeur")
    {
        REQUIRE(Testjoueur.position().renvoyerX() == x);
    	REQUIRE(Testjoueur.position().renvoyerY() == y);
    }
    SUBCASE("Test du constructeur par defaut")
    {
        REQUIRE(p.position().renvoyerX() == 0);
    	REQUIRE(p.position().renvoyerY() == 0);
    }
    SUBCASE("Test la fonction deplacé vers")
    {
        REQUIRE(p.position().renvoyerX() == x);
        REQUIRE(p.position().renvoyerY() == y);
    }
    SUBCASE("Test si le joueur est en vie")
    {
        REQUIRE(p.isAlive() == true);
    }
    SUBCASE("Test la fonction killJoueur")
    {
        REQUIRE(p.isAlive() == false);;
    }
}

#endif //TESTJOUEUR_H