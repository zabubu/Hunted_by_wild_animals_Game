#include "elementMover.h"
#include "terrain.h"

elementMover::elementMover(int direction, const position &posElement) : d_direction{direction}, d_posElement{posElement}
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

