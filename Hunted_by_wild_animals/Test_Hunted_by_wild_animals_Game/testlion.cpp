#ifndef TESTLION_H
#define TESTLION_H

#include "doctest.h"
#include <sstream>
#include <string>
#include "../Hunted_by_wild_animals_Game/lion.h"
#include "../Hunted_by_wild_animals_Game/terrain.h"
#include "../Hunted_by_wild_animals_Game/joueur.h"
#include "../Hunted_by_wild_animals_Game/joueurNormal.h"

using std::ostringstream;
using std::string;
TEST_CASE("Les opérations sur les lions sont correctes")
{
    SUBCASE("Deplacer un lion ")
    {
            terrain t{};
            std::ifstream ifs;
            ifs.open("Terrain1.txt");
            lion l;




    }
}

#endif
