#include "joueurNormal.h"
#include "interface.h"
#include "terrain.h"
#include "fauves.h"
#include "lion.h"
#include "tigre.h"
#include "pieges.h"
#include "arbres.h"
#include "terrain.h"
#include "joueurNormalMover.h"

joueurNormal::joueurNormal(const position & pos) : joueur{pos}
{

}

std::unique_ptr<elements> joueurNormal::clone()
{
    auto p {std::make_unique<joueurNormal>(posElem())};
    return p;
}

void joueurNormal::affiche(const interface &inter) const
{
    inter.afficheJoueurNormal(*this);
}

 void joueurNormal::deplace(terrain &t , int direction)
 {
     position positionActuelle = posElem();
     joueurNormalMover moveJoueurN{direction, positionActuelle};
     position p  =  moveJoueurN.nouvellePosition(t);
     moveJoueurN.deplace(t);
     changePosition(p);
 }

