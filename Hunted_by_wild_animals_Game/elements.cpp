#include "elements.h"



elements::elements(const position &pos) : d_pos{pos}
{

}

void elements::changePosition(int i, int j)
{
  d_pos.modifieI(i);
  d_pos.modifieJ(j);
}

position elements::posElem() const
{
    return d_pos;
}




