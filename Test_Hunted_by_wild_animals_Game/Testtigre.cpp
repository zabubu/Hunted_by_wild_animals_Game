#ifndef TESTTIGRE_H
#define TESTTIGRE_H
#include "doctest.h"
#include <sstream>
#include <string>
#include "../Hunted_by_wild_animals_Game/tigre.h"

using std::ostringstream;
using std::string;

constexpr int enHaut=8,aDroite=6,aGauche=4,enBas=2;

TEST_CASE("Les opérations sur les positions des tigres sont corrects")
{
    SUB_CASE("Creer un tigre à une position donnée est correct")
    {
        position pos(3,4);
        tigre tig(pos);
        REQUIRE_EQ(tig.posElem(),pos);
    }
    TEST_CASE("Changer la position d'un tigre est correct")
    {
            position pos(5,5);
            tigre tig(pos);
        SUB_CASE("Avancer un tigre vers le haut est correct")
        {;
            pos.modifieI(4);
            REQUIRE_EQ(tig.avanceVers(enHaut),pos);
        }
        SUB_CASE("Avancer un tigre vers la droite est correct")
        {
            pos.modifieJ(6);
            REQUIRE_EQ(tig.avanceVers(aDroite),pos);
        }
        SUB_CASE("Avancer un tigre vers la gauche est correct")
        {
            pos.modifieJ(4);
            REQUIRE_EQ(tig.avanceVers(aGauche),pos);
        }
        SUB_CASE("Avancer un tigre vers le bas est correct")
        {
            pos.modifieI(6);
            REQUIRE_EQ(tig.avanceVers(enBas),pos);
        }
        SUB_CASE("Avancer un tigre vers le haut droite est correct")
        {;
            pos.modifieI(4);
            pos.modifieJ(6);
            REQUIRE_EQ(tig.avanceVers(9),pos);
        }
        SUB_CASE("Avancer un tigre vers le bas droite est correct")
        {
            pos.modifieI(4);
            pos.modifieJ(4);
            REQUIRE_EQ(tig.avanceVers(3),pos);
        }
        SUB_CASE("Avancer un tigre vers le bas gauche est correct")
        {
            pos.modifieI(6);
            pos.modifieJ(4);
            REQUIRE_EQ(tig.avanceVers(1),pos);
        }
        SUB_CASE("Avancer un tigre vers le haut gauche est correct")
        {
            pos.modifieI(6);
            pos.modifieJ(6);
            REQUIRE_EQ(tig.avanceVers(7),pos);
        }
    }
    TEST_CASE("Deplacer un tigre vers un joueur est correct")
    {
        SUB_CASE("Deplacer un tigre vers un joueur au dessus est correct")
        {

        }
    }
}


#endif