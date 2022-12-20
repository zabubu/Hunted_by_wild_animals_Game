#include "fauves.h"

fauves::fauves(const std::string& type) : elements{type}
{}

fauves::fauves(const position &p,const std::string& type) : elements{p,type}
{}

fauves::fauves(int x, int y,const std::string& type) : elements{x,y,type}
{}

bool fauves::deplacementAutorise(const position &p)const
{
/*    if(p.possible())
    {
        if(terrain.libre(p))
        {
            return true;
        }
    }
*/
}
/*
void fauves::deplaceVers(const joueur &j)
{
    position p=prochainePosition(j);
    if(DeplacementAutorise(p))
    {
    changePosition(p);
    }
}

*/
