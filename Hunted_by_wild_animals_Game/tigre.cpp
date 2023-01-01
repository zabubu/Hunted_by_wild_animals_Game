#include "tigre.h"
#include "position.h"
#include "joueur.h"
#include "arbres.h"
#include "terrain.h"
#include "pieges.h"
#include "interface.h"
#include "tigreMover.h"

tigre::tigre(const position & pos) : fauves{pos}
{

}



std::unique_ptr<elements> tigre::clone()
{
    auto p {std::make_unique<tigre>(posElem())};
    return p;
}

void tigre::affiche(const interface &inter) const
{
     inter.afficheTigre(*this);
}

void tigre::deplace(terrain &t , int direction)
 {
     position positionActuelle = posElem();
     tigreMover moveTigre{direction, positionActuelle};
     position p  =  moveTigre.nouvellePosition(t);
     moveTigre.deplace(t);
     changePosition(p);
 }
