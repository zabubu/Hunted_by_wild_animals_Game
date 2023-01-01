/*
#ifndef TESTLION_H
#define TESTLION_H
#include "doctest.h"
#include <sstream>
#include <string>
#include "../Hunted_by_wild_animals_Game/lion.h"

using std::ostringstream;
using std::string;

constexpr int enHaut=8,aDroite=6,aGauche=4,enBas=2;

TEST_CASE("Les opérations sur les positions des lions sont corrects")
{
    SUB_CASE("Creer un lion à une position donnée est correct")
    {
        position pos(3,4);
        lion lio(pos);
        REQUIRE_EQ(lio.posElem(),pos);
    }
    TEST_CASE("Changer la position d'un lion est correct")
    {
            position pos(5,5);
            lion lio(pos);
        SUB_CASE("Avancer un lion vers le haut est correct")
        {;
            pos.modifieI(4);
            REQUIRE_EQ(lio.avanceVers(enHaut),pos);
        }
        SUB_CASE("Avancer un lion vers la droite est correct")
        {
            pos.modifieJ(6);
            REQUIRE_EQ(lio.avanceVers(aDroite),pos);
        }
        SUB_CASE("Avancer un lion vers la gauche est correct")
        {
            pos.modifieJ(4);
            REQUIRE_EQ(lio.avanceVers(aGauche),pos);
        }
        SUB_CASE("Avancer un lion vers le bas est correct")
        {
            pos.modifieI(6);
            REQUIRE_EQ(lio.avanceVers(enBas),pos);
        }
    }
    TEST_CASE("Deplacer un lion vers un joueur est correct")
    {
        position posL(5,5);
        lion lio(posL);
        SUB_CASE("Lion en dessous à gauche")
        {
            position posJ(2,2);
            vector<int> vecPosFonc=lio.directionDeplacement(posJ);
            vector<int> vecPos{aGauche,enHaut};
            REQUIRE_EQ(vecPosFonc,vecPos);
        }
        SUB_CASE("Lion en dessous à gauche")
        {
            position posJ(8,2);
            vector<int> vecPosFonc=lio.directionDeplacement(posJ);
            vector<int> vecPos{aDroite,enHaut};
            REQUIRE_EQ(vecPosFonc,vecPos);
        }
        SUB_CASE("Lion au dessus à droite")
        {
            position posJ(2,8);
            vector<int> vecPosFonc=lio.directionDeplacement(posJ);
            vector<int> vecPos{aGauche,enBas};
            REQUIRE_EQ(vecPosFonc,vecPos);
        }
        SUB_CASE("Lion en dessous à droite")
        {
            position posJ(8,8);
            vector<int> vecPosFonc=lio.directionDeplacement(posJ);
            vector<int> vecPos{aDroite,enBas};
            REQUIRE_EQ(vecPosFonc,vecPos);
        }
    }
}


#endif
*/
