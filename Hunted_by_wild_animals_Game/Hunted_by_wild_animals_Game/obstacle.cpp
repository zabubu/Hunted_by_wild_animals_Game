#include "obstacle.h"

obstacle::obstacle (const position &pos, const std::string &type) :
    d_position{pos.x(), pos.y()}, d_type{type}
{}

void obstacle::modifierPosition (int x, int y)
{
    d_position.modifierX(x);
    d_position.modifierY(y);
}
