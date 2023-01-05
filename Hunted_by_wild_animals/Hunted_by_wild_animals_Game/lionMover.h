#ifndef LIONMOVER_H
#define LIONMOVER_H
#include <vector>

#include "elementMover.h"
class terrain;

class lionMover : public elementMover
{
public :
    lionMover( const position &posElement);
    position positionSelonDirection() override;

    std::vector<int> tabDirectionsDeplacements (const position &posJoueur, const position &posLion);
    position nouvellePositionPotentiel(terrain &t);

    void deplace(terrain &t) override;
    int situation(terrain &t) override;
    position nouvellePosition(terrain &t) override;

};

#endif // LIONMOVER_H

