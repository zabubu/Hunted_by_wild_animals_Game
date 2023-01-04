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
    std::unique_ptr<elements> clone() override;
    void affiche(const interface &inter) const override;
    void deplaceJoueur(terrain &t, int direction) override;

};



#endif // JOUEURNORMAL_H



