#ifndef ELEMENTMOVER_H
#define ELEMENTMOVER_H
#include "position.h"
class terrain;

class elementMover
{
public :
    elementMover(int direction, const position &posElement);
    ~elementMover() = default;
    virtual position nouvellePositionPotentiel()=0;
    virtual void deplace(terrain &t) = 0;
    int direction() const;
    position positionElem() const;
    virtual int situation(terrain &t)=0;
    virtual position nouvellePosition(terrain &t) =0;

    const int SITUATION_PEUT_SE_DEPLACER {1};
    const int SITUATION_NE_PEUT_SE_DEPLACER {2};
    const int SITUATION_MORT {3};

protected:
    int d_direction;
    position d_posElement;

};
#endif // ELEMENTMOVER_H
