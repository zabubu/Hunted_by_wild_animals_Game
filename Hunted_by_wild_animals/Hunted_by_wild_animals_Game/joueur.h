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
    std::unique_ptr<elements> clone() override =0;
    void affiche(const interface &inter) const override =0;
    void deplace(terrain &t , int direction) override =0;

};



#endif // JOUEUR_H


