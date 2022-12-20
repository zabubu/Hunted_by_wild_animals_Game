#include "elements.h"
//des elements du terrain

elements::elements(const std::string& type) : d_pos{}, d_nom{type}
{

}

elements::elements(int x, int y,const std::string &nom) : d_pos{x,y}, d_nom{nom}
{

}

elements::elements(const position &pos, const std::string &nom) : d_pos{pos}, d_nom{nom}
{

}

void elements::changePosition(const position& p)
{
  d_pos.modifierX(p.x());
  d_pos.modifierY(p.y());
}

void elements::affiche(std::ostream &ost) const
{
    ost<<d_nom;
}
