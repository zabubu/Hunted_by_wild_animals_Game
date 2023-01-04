#include "lion.h"
#include "joueur.h"
#include "arbres.h"
#include "position.h"
#include "terrain.h"
#include "elements.h"
#include "pieges.h"
#include "interface.h"
#include "lionMover.h"

lion::lion(const position &pos) : fauves{pos}
{

}

std::unique_ptr<elements> lion::clone()
{
    auto p {std::make_unique<lion>(posElem())};
    return p;
}

void lion::affiche(const interface &inter) const
{
    inter.afficheLion(*this);
}

void lion::deplace(terrain &t )
 {
     position positionActuelle = posElem();
     lionMover moveLion{positionActuelle};
     position p  =  moveLion.nouvellePosition(t);
     moveLion.deplace(t);
     changePosition(p);
 }













