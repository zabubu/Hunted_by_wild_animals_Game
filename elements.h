#ifndef ELEMENTS_H
#define ELEMENTS_H
#include <istream>
#include <string>
#include <iostream>
#include "position.h"


class elements
{
public :
   ~elements() = default;
   elements(const position &pos, const std::string &nom);
   void affiche(std::ostream &ost) const;
   void changePosition (int i, int j);
   virtual unique_ptr<elements> clone() const;
protected :
    position d_pos;
    std::string d_nom;

};


#endif // ELEMENTS_H
