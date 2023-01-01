#include "joueurExpert.h"
#include "interface.h"
#include "terrain.h"
#include "fauves.h"
#include "lion.h"
#include "tigre.h"
#include "pieges.h"
#include "arbres.h"
#include "joueurNormalMover.h"

joueurExpert::joueurExpert(const position & pos) : joueur{pos}
{

}


std::unique_ptr<elements> joueurExpert::clone()
{
    auto p {std::make_unique<joueurExpert>(posElem())};
    return p;
}

void joueurExpert::affiche(const interface &inter) const
{
    inter.afficheJoueurExpert(*this);
}

void joueurExpert::deplace(terrain &t , int direction)
 {
     position positionActuelle = posElem();
     joueurNormalMover moveJoueurN{direction, positionActuelle};
     moveJoueurN.deplace(t);
 }
