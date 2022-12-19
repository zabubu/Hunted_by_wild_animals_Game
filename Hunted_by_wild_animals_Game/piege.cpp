#include "piege.h"

piege::piege (const Position &pos, int nbMaxDeUtilisation, const string &type) :
    d_position{pos.renvoyerX(), pos.renvoyerY()}, d_nbMaxDeUtilisation{nbMaxDeUtilisation}, d_nbDeUtilisation{0}. d_type{type}
{}

int piege::nbDeUtilisation () const
{
    return d_nbDeUtilisation;
}

int piege::nbMaxDeUtilisation () const
{
    return d_nbMaxDeUtilisation;
}

void piege::modifierPosition (int x, int y)
{
    d_position.modifierX(x);
    d_position.modifierY(y);
}
