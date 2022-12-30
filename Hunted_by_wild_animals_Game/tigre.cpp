#include "tigre.h"
#include "position.h"
#include "joueur.h"
#include "arbres.h"
#include "terrain.h"
#include "pieges.h"
#include "interface.h"

tigre::tigre(const position & pos) : fauves{pos}
{

}

position tigre::avanceVers(int i)
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



int tigre::deplaceEn(const position &pos, terrain &t)
{

       int i = pos.i();
       int j = pos.j();
       auto elem = t.tabElements()[i][j].get();
       if(dynamic_cast<tigre*>(elem))
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


std::unique_ptr<elements> tigre::clone()
{
    auto p {std::make_unique<tigre>(posElem())};
    return p;
}

void tigre::affiche(const interface &inter) const
{
     inter.afficheTigre(*this);
}

std::vector<int> tigre::directionDeplacement(const position &posJoueur) const
{
     std::vector<int> tabDeplacements;
     int Ijoueur = posJoueur.i(), Jjoueur = posJoueur.j(), Ilion = d_pos.i(), Jlion = d_pos.j();


     if(Jlion > Jjoueur)
     {
         if(Ilion < Ijoueur)
         {
            tabDeplacements.push_back(1);
            tabDeplacements.push_back(4);
            tabDeplacements.push_back(2);
         }
         else if(Ilion > Ijoueur)
         {
            tabDeplacements.push_back(7);
            tabDeplacements.push_back(4);
            tabDeplacements.push_back(8);
         }
         else
         {
             tabDeplacements.push_back(4);
             tabDeplacements.push_back(7);
             tabDeplacements.push_back(1);
         }
     }
     else if(Jlion < Jjoueur)
     {
         if(Ilion < Ijoueur)
         {
            tabDeplacements.push_back(3);
            tabDeplacements.push_back(6);
            tabDeplacements.push_back(2);
         }
         else if(Ilion > Ijoueur)
         {
            tabDeplacements.push_back(9);
            tabDeplacements.push_back(6);
            tabDeplacements.push_back(8);
         }
         else
         {
             tabDeplacements.push_back(6);
             tabDeplacements.push_back(3);
             tabDeplacements.push_back(9);
         }
     }
     else if(Jlion == Jjoueur)
     {
         if(Ilion > Ijoueur)
         {
            tabDeplacements.push_back(8);
            tabDeplacements.push_back(7);
            tabDeplacements.push_back(9);
         }
         else if(Ilion < Ijoueur)
         {
            tabDeplacements.push_back(2);
            tabDeplacements.push_back(1);
            tabDeplacements.push_back(3);
         }
     }
     else if(Ilion == Ijoueur)
     {
         if(Jlion > Jjoueur)
         {
            tabDeplacements.push_back(4);
            tabDeplacements.push_back(7);
            tabDeplacements.push_back(1);
         }
         else if(Jlion < Jjoueur)
         {
            tabDeplacements.push_back(6);
            tabDeplacements.push_back(9);
            tabDeplacements.push_back(3);
         }
     }
          return tabDeplacements;
}
