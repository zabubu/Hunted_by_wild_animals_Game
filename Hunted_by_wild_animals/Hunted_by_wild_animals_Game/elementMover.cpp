#include "elementMover.h"
#include "terrain.h"

elementMover::elementMover(const position &posElement,int direction) : d_direction{direction}, d_posElement{posElement}
{

}

int elementMover::direction() const
{
    return d_direction;
}

position elementMover::positionElem() const
{
    return d_posElement;
}

