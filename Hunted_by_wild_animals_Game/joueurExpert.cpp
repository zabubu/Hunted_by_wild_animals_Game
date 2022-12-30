#include "joueurExpert.h"
#include "interface.h"
#include "terrain.h"
#include "fauves.h"
#include "lion.h"
#include "tigre.h"
#include "pieges.h"
#include "arbres.h"

joueurExpert::joueurExpert(const position & pos) : joueur{pos}
{

}


position joueurExpert::avanceVers(int i)
{
    if(i==8)
    {
        position pos{posElem().i(), posElem().j()};
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
}

int joueurExpert::deplaceEn(const position &pos, terrain &t)
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


    }


std::unique_ptr<elements> joueurExpert::clone()
{
    auto p {std::make_unique<joueurExpert>(posElem())};
    return p;
}

void joueurExpert::affiche(const interface &inter) const
{
    inter.afficheJoueurExpert(*this);
}
