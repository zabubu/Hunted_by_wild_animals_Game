#ifndef JOUEUREXPERT_H
#define JOUEUREXPERT_H

#include <iostream>
#include "position.h"
#include "joueur.h"
class interface;

class joueurExpert : public joueur
{
public :
    joueurExpert(const position & pos);
    position avanceVers(int i) override;
    int deplaceEn(const position &pos, terrain &t) override;
    std::unique_ptr<elements> clone() override;
    void affiche(const interface &inter) const override;
};



#endif // JOUEUR_H



