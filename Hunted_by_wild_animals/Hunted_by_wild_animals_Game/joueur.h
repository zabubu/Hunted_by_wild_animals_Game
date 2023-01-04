#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>
#include "position.h"
#include "elements.h"
class interface;



class joueur : public elements
{
    public :
    joueur(const position & pos);
    std::unique_ptr<elements> clone() override =0;
    void affiche(const interface &inter) const override =0;
    virtual void deplaceJoueur(terrain &t , int direction) =0;

};



#endif // JOUEUR_H


