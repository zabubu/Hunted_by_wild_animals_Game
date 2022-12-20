#ifndef TESTTIGRE_H
#define TESTTIGRE_H

#include "doctest.h"
#include <sstream>
#include <string>
#include "../Hunted_by_wild_animals_Game/position.h"

using std::ostringstream;
using std::string;

TESTCASE("Les opérations sur les tigres sont corrects")
{
	SUBCASE("Deplacer un tigre vers un joueur est correct")
	{
		SUBCASE("Deplacer un tigre vers un joueur au dessus de lui")
		{
			joueur jou{1,5};
			tigre tig{1,1};
			tig.deplaceVers(jou);
			REQUIRE_EQ((tig.position(),p{2,2})||tig.position(),p{0,2});
		}
				SUBCASE("Deplacer un tigre vers un joueur au dessus de lui")
		{
			joueur jou{1,1};
			tigre tig{1,5};
			tig.deplaceVers(jou);
			REQUIRE_EQ((tig.position(),p{2,4})||tig.position(),p{0,4});
		}
	}
}
#endif