#ifndef LION_H
#define LION_H
#include "fauves.h"

class lion : public fauves
{
    public : 
    void deplaceVers(const joueur &j) override;
    bool deplacementAutorise(const position &p)override;
}


#endif