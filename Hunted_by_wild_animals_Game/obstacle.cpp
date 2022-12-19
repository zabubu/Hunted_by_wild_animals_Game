#include "obstacle.h"

obstacle::obstacle (const Position &pos, const string &type) :
    d_position{pos.renvoyerX(), pos.renvoyerY()}, d_type{type}
{}

void obstacle::modifierPosition (int x, int y)
{
    d_position.modifierX(x);
    d_position.modifierY(y);
}
