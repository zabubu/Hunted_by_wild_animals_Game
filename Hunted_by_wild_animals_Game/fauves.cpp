#include "fauves.h"

fauves::fauves() : elementsEnMouvements{}
{}

fauves::fauves(const position &p) : elementsEnMouvements{p}
{}

fauves::fauves(int x, int y) : elementsEnMouvements{position{x,y}}
{}

bool fauves::deplacementAutorise(const position &p)
{
    if(p.possible())
    {
        if(terrain.libre(p))
        {
            return true;
        }
    }
}