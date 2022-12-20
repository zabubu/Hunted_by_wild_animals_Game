#ifndef ELEMENTS_H
#define ELEMENTS_H
#include <istream>
#include <string>
#include <iostream>
#include "memory"
#include "position.h"

//des elements

class elements
{
public :
   ~elements() = default;
   elements(const std::string& type);
   elements(int x,int y,const std::string &nom);
   elements(const position &pos,const std::string &nom);
   void affiche(std::ostream &ost) const;
   void changePosition(const position& p);
   /*virtual std::unique_ptr<elements> clone() const;*/
private :
    position d_pos;
    std::string d_nom;

};


#endif // ELEMENTS_H
