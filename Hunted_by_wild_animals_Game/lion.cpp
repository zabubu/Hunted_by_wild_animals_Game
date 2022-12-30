#include "lion.h"
#include "joueur.h"
#include "arbres.h"
#include "position.h"
#include "terrain.h"
#include "elements.h"
#include "pieges.h"
#include "interface.h"

lion::lion(const position &pos) : fauves{pos}
{

}

position lion::avanceVers(int i)
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
}


int lion::deplaceEn(const position &pos, terrain &t)
{

       int i = pos.i();
       int j = pos.j();
       auto elem = t.tabElements()[i][j].get();
       if(dynamic_cast<lion*>(elem))
       {
          return 1;
       }
       else if(dynamic_cast<fauves*>(elem))
       {
            return 2;
       }
       else if(dynamic_cast<joueur*>(elem))
       {
            return 2;
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

std::unique_ptr<elements> lion::clone()
{
    auto p {std::make_unique<lion>(posElem())};
    return p;
}

void lion::affiche(const interface &inter) const
{
    inter.afficheLion(*this);
}


std::vector<int> lion::directionDeplacement(const position &posJoueur) const
{
     std::vector<int> tabDeplacements;
     int Ijoueur = posJoueur.i(), Jjoueur = posJoueur.j(), Ilion = d_pos.i(), Jlion = d_pos.j();
     if(Jlion > Jjoueur)
     {
         if(Ilion < Ijoueur)
         {
            tabDeplacements.push_back(4);
            tabDeplacements.push_back(2);
         }
         else if(Ilion > Ijoueur)
         {
            tabDeplacements.push_back(4);
            tabDeplacements.push_back(8);
         }
         else
         {
             tabDeplacements.push_back(4);
         }
     }
     else if(Jlion < Jjoueur)
     {
         if(Ilion < Ijoueur)
         {
            tabDeplacements.push_back(6);
            tabDeplacements.push_back(2);
         }
         else if(Ilion > Ijoueur)
         {
            tabDeplacements.push_back(6);
            tabDeplacements.push_back(8);
         }
         else
         {
             tabDeplacements.push_back(6);
         }
     }
     else if(Jlion == Jjoueur)
     {
         if(Ilion > Ijoueur)
         {
            tabDeplacements.push_back(8);
         }
         else if (Ilion < Ijoueur)
         {
            tabDeplacements.push_back(2);
         }
     }
     else if(Ilion == Ijoueur)
     {
         if(Jlion > Jjoueur)
         {

            tabDeplacements.push_back(4);
         }
         else if(Jlion < Jjoueur)
         {

            tabDeplacements.push_back(6);
         }
     }
          return tabDeplacements;
}















