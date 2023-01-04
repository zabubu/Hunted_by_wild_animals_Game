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
    std::unique_ptr<elements> clone() override =0;
    void affiche(const interface &inter) const override=0;
    void deplace(terrain &t , int direction) override =0;

};




#endif // FAUVES_H