#include "tigreMover.h"
#include "terrain.h"

tigreMover::tigreMover(int direction,const position &posElement) : elementMover{direction, posElement}
{

}

position tigreMover::nouvellePositionPotentiel()
{
    if(direction()==8)
    {
        return position{positionElem().getI()-1, positionElem().getJ()};
    }
    else if(direction()==2)
    {
       return position{positionElem().getI()+1, positionElem().getJ()};
    }
    else if(direction()==6)
    {
       return position{positionElem().getI(), positionElem().getJ()+1};
    }
    else if(direction()==4)
    {
       return position{positionElem().getI(), positionElem().getJ()-1};
    }
    else if(direction()==7)
    {
       return position{positionElem().getI()-1, positionElem().getJ()-1};
    }
    else if(direction()==9)
    {
       return position{positionElem().getI()-1, positionElem().getJ()+1};
    }
    else if(direction()==1)
    {
      return position{positionElem().getI()+1, positionElem().getJ()-1};
    }
    else if(direction()==3)
    {
       return position{positionElem().getI()+1, positionElem().getJ()+1};
    }

}

std::vector<int> tigreMover::tabDirectionsDeplacements(const position &posJoueur, const position &posTigre)
{
     std::vector<int> tabDeplacements;
     int Ijoueur = posJoueur.getI(), Jjoueur = posJoueur.getJ(), ITigre = posTigre.getI(), JTigre = posTigre.getJ();


     if(JTigre > Jjoueur)
     {
         if(ITigre < Ijoueur)
         {
            tabDeplacements.push_back(1);
            tabDeplacements.push_back(4);
            tabDeplacements.push_back(2);
         }
         else if(ITigre > Ijoueur)
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
     else if(JTigre < Jjoueur)
     {
         if(ITigre < Ijoueur)
         {
            tabDeplacements.push_back(3);
            tabDeplacements.push_back(6);
            tabDeplacements.push_back(2);
         }
         else if(ITigre > Ijoueur)
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
     else if(JTigre == Jjoueur)
     {
         if(ITigre > Ijoueur)
         {
            tabDeplacements.push_back(8);
            tabDeplacements.push_back(7);
            tabDeplacements.push_back(9);
         }
         else if(ITigre < Ijoueur)
         {
            tabDeplacements.push_back(2);
            tabDeplacements.push_back(1);
            tabDeplacements.push_back(3);
         }
     }
     else if(ITigre == Ijoueur)
     {
         if(JTigre > Jjoueur)
         {
            tabDeplacements.push_back(4);
            tabDeplacements.push_back(7);
            tabDeplacements.push_back(1);
         }
         else if(JTigre < Jjoueur)
         {
            tabDeplacements.push_back(6);
            tabDeplacements.push_back(9);
            tabDeplacements.push_back(3);
         }
     }
          return tabDeplacements;
}

position tigreMover::nouvellePositionPotentiel2(terrain &t)
{
   position posJoueur = t.posJoueur();
   position posActuelle =  positionElem();
   std::vector<int> tabDirection = tabDirectionsDeplacements(posJoueur,positionElem());
   int i=0;
   position nouvellePos{};
   bool tourFini;
   do
   {
       d_direction = tabDirection[i];
       nouvellePos = nouvellePositionPotentiel();
       int elementSurCase = t.typeElementCase(nouvellePos);

       if(elementSurCase == t.TYPE_TIGRE ||  elementSurCase == t.TYPE_ARBRE)
       {
           tourFini =false;
       }
       else
       {
           tourFini = true;
       }

     i++;
   }while( tourFini == false && i<tabDirection.size());
   return nouvellePos;
}

int tigreMover::situation(terrain &t)
{
         position posActuelle = positionElem();
         position nouvellePos = nouvellePositionPotentiel2(t);

          int elementSurCase = t.typeElementCase(nouvellePos);

          if(elementSurCase != t.TYPE_ARBRE && elementSurCase != t.TYPE_TIGRE)
          {
             if(elementSurCase == t.CASE_VIDE)
             {
                return SITUATION_PEUT_SE_DEPLACER;
             }
             else if(elementSurCase == t.TYPE_PIEGE)
             {
                  return SITUATION_MORT;
             }
             else
             {
                 return SITUATION_MANGE;
             }
          }
          else
          {
              return SITUATION_NE_PEUT_SE_DEPLACER;
          }
}

void tigreMover::deplace(terrain &t)
{
         position posActuelle = positionElem();
          position nouvellePos = nouvellePositionPotentiel2(t);

                 if(situation(t)==SITUATION_PEUT_SE_DEPLACER)
                 {
                     int iAct=posActuelle.getI(), jAct = posActuelle.getJ(), iNouv = nouvellePos.getI(), jNouv = nouvellePos.getJ();
                     t.changeCase(iAct,jAct,iNouv,jNouv);
                 }
                 else if(situation(t)==SITUATION_MORT)
                 {
                    t.supprimerElement(posActuelle);
                 }
                 else if(situation(t)==SITUATION_MANGE)
                 {
                    t.supprimerElement(nouvellePos);
                    int iAct=posActuelle.getI(), jAct = posActuelle.getJ(), iNouv = nouvellePos.getI(), jNouv = nouvellePos.getI();
                    t.changeCase(iAct,jAct,iNouv,jNouv);
                 }
}

position tigreMover::nouvellePosition(terrain &t)
{
    if(situation(t)==SITUATION_PEUT_SE_DEPLACER ||  situation(t)==SITUATION_MANGE)
    {
        return nouvellePositionPotentiel2(t);
    }
    else
    {
        return positionElem();
    }
}

