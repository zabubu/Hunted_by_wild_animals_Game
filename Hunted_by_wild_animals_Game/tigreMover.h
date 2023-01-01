#ifndef TIGREMOVER_H
#define TIGREMOVER_H
#include <vector>

#include "elementMover.h"
class terrain;

class tigreMover : public elementMover
{
public :
    tigreMover(int direction, const position &posElement);
    position nouvellePositionPotentiel() override;

    std::vector<int> tabDirectionsDeplacements (const position &posJoueur, const position &posTigre);
    position nouvellePositionPotentiel2(terrain &t);

    void deplace(terrain &t) override;
    int situation(terrain &t) override;
    position nouvellePosition(terrain &t) override;

};

#endif // TIGREMOVER_H