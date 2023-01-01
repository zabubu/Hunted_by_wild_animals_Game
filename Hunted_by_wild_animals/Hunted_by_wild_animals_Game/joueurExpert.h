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
    std::unique_ptr<elements> clone() override;
    void affiche(const interface &inter) const override;
    void deplace(terrain &t, int direction) override;
};



#endif // JOUEUR_H



