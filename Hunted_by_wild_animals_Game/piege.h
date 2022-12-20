#ifndef PIEGE_H
#define PIEGE_H
#include <iostream>
#include "Position.h"

class piege
{
    public:
        piege(const position &pos, int nbMaxDeUtilisation, const std::string &type);
        int nbDeUtilisation () const;
        int nbMaxDeUtilisation () const;
        void modifierPosition (const position& p);

    private:
        position d_position;
        int d_nbDeUtilisation;
        int d_nbMaxDeUtilisation;
        std::string d_type;
};

#endif // PIEGE_H
