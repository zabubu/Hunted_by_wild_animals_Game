#ifndef PIEGE_H
#define PIEGE_H

#include "Position.h"

class piege
{
    public:
        piege (const Position &pos, int nbMaxDeUtilisation, const string &type);
        int nbDeUtilisation () const;
        int nbMaxDeUtilisation () const;
        void modifierPosition (int x, int y);

    private:
        Position d_position;
        int d_nbDeUtilisation;
        int d_nbMaxDeUtilisation;
        string d_type;
};

#endif // PIEGE_H
