#ifndef TIGRE_H
#define TIGRE_H


#include "fauves.h"
#include <iostream>


class position;
class terrain;
class interface;

class tigre : public fauves
{
    public :
    tigre(const position &pos);
    position avanceVers(int i) override;
    int deplaceEn(const position &pos, terrain &t) override;
    std::unique_ptr<elements> clone() override;
    void affiche(const interface &inter) const override;
    std::vector<int> directionDeplacement(const position &posJoueur) const override;

};



#endif // TIGRE_H


