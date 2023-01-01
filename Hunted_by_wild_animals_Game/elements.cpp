#include "elements.h"



elements::elements(const position &pos) : d_pos{pos}
{

}

void elements::changePosition(const position &p)
{
  d_pos.setI(p.getI());
  d_pos.setJ(p.getJ());
}

position elements::posElem() const
{
    return d_pos;
}




