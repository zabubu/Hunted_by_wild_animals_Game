#ifndef JOUEURNORMAL_H
#define JOUEURNORMAL_H

#include <iostream>
#include "position.h"
#include "joueur.h"
class interface;



class joueurNormal : public joueur
{
public :
    joueurNormal(const position & pos);
    position avanceVers(int i) override;
    int deplaceEn(const position &pos, terrain &t) override;
    std::unique_ptr<elements> clone() override;
    void affiche(const interface &inter) const override;
};



#endif // JOUEURNORMAL_H



