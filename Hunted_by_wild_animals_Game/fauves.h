#ifndef FAUVES_H
#define FAUVES_H

#include "elementsDeplacable.h"
#include <string>
#include <iostream>
#include <vector>


class position;
class elements;
class interface;


class fauves : public elementsDeplacable
{
public :
    fauves(const position & pos);
    position avanceVers(int i) override =0;
    int deplaceEn(const position &pos, terrain &t) override = 0;
    std::unique_ptr<elements> clone() override =0;
    void affiche(const interface &inter) const override=0;
    virtual std::vector<int> directionDeplacement(const position &posJoueur) const=0;

};




#endif // FAUVES_H
