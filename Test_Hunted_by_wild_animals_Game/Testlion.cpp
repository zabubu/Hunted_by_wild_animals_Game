#ifndef TESTLION_H
#define TESTLION_H

#include "doctest.h"
#include <sstream>
#include <string>
#include "../Hunted_by_wild_animals_Game/position.h"

using std::ostringstream;
using std::string;

TEST_CASE("Les opérations sur les lions sont correctes")
{
	SUBCASE("Deplacer un lion vers un joueur est correct")
	{
		SUBCASE("Deplacer un lion vers un joueur au dessus de lui")
		{
			joueur jou{1,5};
			lion lio{1,1};
			lio.deplaceVers(jou);
			REQUIRE_EQ(lio.position(),p{1,2});
		}
				SUBCASE("Deplacer un lion vers un joueur au dessus de lui")
		{
			joueur jou{1,1};
			fauves lio{1,5};
			lio.deplaceVers(jou);
			REQUIRE_EQ(lio.position(),p{1,4});
		}
	}
}

#endif