#include "fauves.h"

fauves::fauves() : d_position{}
{}

fauves::fauves(const position &p) : d_position{p}
{}

fauves::fauves(int x, int y) : d_position{position{x,y}}
{}

fauves::deplaceEn(const position& p)
{
    d_position = p;
}

bool fauves::deplacementAutorise(const position &p)
{
    if(p.possible())
    {
        if()
        {
            return false;
        }
        else
        {
            return true;
        }
        }
}