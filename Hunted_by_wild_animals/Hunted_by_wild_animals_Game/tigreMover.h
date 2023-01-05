#ifndef TIGREMOVER_H
#define TIGREMOVER_H
#include <vector>

#include "elementMover.h"
class terrain;

class tigreMover : public elementMover
{
public :
    tigreMover( const position &posElement);
    position positionSelonDirection() override;

    std::vector<int> tabDirectionsDeplacements (const position &posJoueur, const position &posTigre);
    position nouvellePositionPotentiel(terrain &t);

    void deplace(terrain &t) override;
    int situation(terrain &t) override;
    position nouvellePosition(terrain &t) override;

};

#endif // TIGREMOVER_H
