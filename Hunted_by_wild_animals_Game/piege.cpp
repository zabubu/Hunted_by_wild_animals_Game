#include "piege.h"

piege::piege (const position &pos, int nbMaxDeUtilisation, const std::string &type) :
    d_position{pos.x(), pos.y()}, d_nbMaxDeUtilisation{nbMaxDeUtilisation}, d_nbDeUtilisation{0}, d_type{type}
{}

int piege::nbDeUtilisation () const
{
    return d_nbDeUtilisation;
}

int piege::nbMaxDeUtilisation () const
{
    return d_nbMaxDeUtilisation;
}

void piege::modifierPosition (const position& p)
{
    d_position.modifierX(p.x());
    d_position.modifierY(p.y());
}
