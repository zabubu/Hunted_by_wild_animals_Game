#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>
#include "position.h"
#include "elementsDeplacable.h"
class interface;



class joueur : public elementsDeplacable
{
    public :
    joueur(const position & pos);
    position avanceVers(int i) override =0;
    int deplaceEn(const position &pos, terrain &t) override = 0;
    std::unique_ptr<elements> clone() override =0;
    void affiche(const interface &inter) const override =0;

};



#endif // JOUEUR_H


