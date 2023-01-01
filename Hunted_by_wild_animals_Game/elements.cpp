#include "elements.h"



elements::elements(const position &pos) : d_pos{pos}
{

}

void elements::changePosition(const position &p)
{
  d_pos.modifieI(p.i());
  d_pos.modifieJ(p.j());
}

position elements::posElem() const
{
    return d_pos;
}




