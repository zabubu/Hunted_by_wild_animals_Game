#ifndef FAUVES_H
#define FAUVES_H

#include "elements.h"
#include <string>
#include <iostream>
#include <vector>


class position;
class elements;
class interface;


class fauves : public elements
{
public :
    fauves(const position & pos);
    std::unique_ptr<elements> clone() override =0;
    void affiche(const interface &inter) const override=0;
    virtual void deplace(terrain &t ) = 0;

};




#endif // FAUVES_H
