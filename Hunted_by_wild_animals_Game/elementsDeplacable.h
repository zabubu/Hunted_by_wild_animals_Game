#ifndef ELEMENTSDEPLACABLE_H
#define ELEMENTSDEPLACABLE_H

#include "elements.h"
#include <string>
#include <iostream>


class position;
class terrain;
class interface;

class elementsDeplacable : public elements
{
public :
    elementsDeplacable(const position &pos);
    std::unique_ptr<elements> clone() override =0;
    void affiche(const interface &inter) const  override =0;
    virtual void deplace(terrain &t , int direction)= 0;

};

#endif // ELEMENTSDEPLACABLE_H
