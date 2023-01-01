#ifndef JOUEURNORMALMOVER_H
#define JOUEURNORMALMOVER_H
#include "elementMover.h"

class joueurNormalMover : public elementMover
{
    public :
    joueurNormalMover(int direction, const position &posElement);
    position nouvellePositionPotentiel() override;
    void deplace(terrain &t) override;
    int situation(terrain &t) override;
    position nouvellePosition(terrain &t) override;
};



#endif // JOUEURNORMALMOVER_H
