#ifndef TESTFAUVES_H
#define TESTFAUVES_H

#include "doctest.h"
#include <sstream>
#include <string>
#include "../Hunted_by_wild_animals_Game/position.h"

using std::ostringstream;
using std::string;

TEST_CASE("Les opérations sur les fauves sont correctes")
{
	SUBCASE("Deplacer un fauve est correct")
	{
		fauves fau{};
		SUBCASE("Deplacer un fauve aux positions vide est correct")
		{
			position p{3,3};
			fau.DeplaceEn(p);
			REQUIRE_EQ(fau.position(),p);
		}
		SUBCASE("Deplacer un fauve aux positions existantes est correct")
		{
			fau.deplaceEn(p{2,5})
			position p{3,3};
			fau.DeplaceEn(p);
			REQUIRE_EQ(fau.position(),p);	
		}
	}
	SUBCASE("La verification de déplacement est correct")
	{
		fauves fau{0,5};
		SUBCASE("Deplacer un fauve en dehors de la grille est correct")
		{
			position p{-1,5};
			REQUIRE(fau.deplacementAutorise(p)==false);
		}
		SUBCASE("Deplacer un fauve sur un obstacle est correct")
		{
			obstacle obs{p{1,5},"arbre"};
			position p{1,5};
			REQUIRE(fau.deplacementAutorise(p)==false);
		}
	}
}
#endif