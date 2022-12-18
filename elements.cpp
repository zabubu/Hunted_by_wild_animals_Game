#include "elements.h"
//des elements du terrain

elements::elements(const position &pos, const std::string n&om) : d_pos{pos}, d_nom{nom}
{

}

void elements::changePosition(int i, int j)
{
  d_pos.modifieI(i);
  d_pos.modifieJ(j);
}

void elements::affiche(std::ostream &ost) const
{
    ost<<d_nom;
}
