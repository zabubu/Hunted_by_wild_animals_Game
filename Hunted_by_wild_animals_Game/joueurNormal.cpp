#include "joueurNormal.h"
#include "interface.h"
#include "terrain.h"
#include "fauves.h"
#include "lion.h"
#include "tigre.h"
#include "pieges.h"
#include "arbres.h"

joueurNormal::joueurNormal(const position & pos) : joueur{pos}
{

}

position joueurNormal::avanceVers(int i)
{
    if(i==8)
    {
        position pos{posElem().i()-1, posElem().j()};
        return pos;
    }
    if(i==2)
    {
       position pos{posElem().i()+1, posElem().j()};
       return pos;
    }
    if(i==6)
    {
       position pos{posElem().i(), posElem().j()+1};
       return pos;
    }
    if(i==4)
    {
       position pos{posElem().i(), posElem().j()-1};
       return pos;
    }
    if(i==7)
    {
       position pos{posElem().i()-1, posElem().j()-1};
       return pos;
    }
    if(i==9)
    {
       position pos{posElem().i()-1, posElem().j()+1};
       return pos;
    }
    if(i==1)
    {
       position pos{posElem().i()+1, posElem().j()-1};
       return pos;
    }
    if(i==3)
    {
       position pos{posElem().i()+1, posElem().j()+1};
       return pos;
    }
}

int joueurNormal::deplaceEn(const position &pos, terrain &t)
{

       int i = pos.i();
       int j = pos.j();
       auto elem = t.tabElements()[i][j].get();

       if(dynamic_cast<fauves*>(elem))
       {
          return 3;
       }
        else if(dynamic_cast<pieges*>(elem))
       {
           return 3;
       }
        else if(dynamic_cast<arbres*>(elem))
       {
           return 1;
       }
       else if(elem==nullptr)
       {
           return 0;
       }

    }

std::unique_ptr<elements> joueurNormal::clone()
{
    auto p {std::make_unique<joueurNormal>(posElem())};
    return p;
}

void joueurNormal::affiche(const interface &inter) const
{
    inter.afficheJoueurNormal(*this);
}

