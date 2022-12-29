#ifndef ELEMENTS_H
#define ELEMENTS_H
#include <string>
#include <iostream>
#include <memory>
#include "position.h"

class interface;
class position;
class interface;
class terrain;

class elements
{
public :
   ~elements() = default;
   elements(const position &pos);
   position posElem() const;
   void changePosition (int i, int j);
   virtual void affiche(const interface &inter) const=0;
   virtual std::unique_ptr<elements> clone() =0;

protected :
    position d_pos;
};


#endif // ELEMENTS_H
