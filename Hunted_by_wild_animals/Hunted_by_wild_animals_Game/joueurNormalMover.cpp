#include "joueurNormalMover.h"
#include "joueurNormal.h"
#include "terrain.h"


joueurNormalMover::joueurNormalMover(int direction ,const position &posElement) : elementMover{posElement,direction}
{

}

position joueurNormalMover::nouvellePositionPotentiel()
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

int joueurNormalMover::situation(terrain &t)
{
         position posActuelle = positionElem();
         position nouvellePos = nouvellePositionPotentiel();

          int elementSurCase = t.typeElementCase(nouvellePos);

          if(elementSurCase != t.TYPE_ARBRE)
          {
             if(elementSurCase == t.CASE_VIDE)
             {
                return SITUATION_PEUT_SE_DEPLACER;
             }
             else
             {
                  return SITUATION_MORT;
             }
          }
          else
          {
              return SITUATION_NE_PEUT_SE_DEPLACER;
          }
}

void joueurNormalMover::deplace(terrain &t)
{
         position posActuelle = positionElem();
          position nouvellePos = nouvellePositionPotentiel();

                 if(situation(t)==SITUATION_PEUT_SE_DEPLACER)
                 {
                     int iAct=posActuelle.getI(), jAct = posActuelle.getJ(), iNouv = nouvellePos.getI(), jNouv = nouvellePos.getJ();
                     t.changeCase(iAct,jAct,iNouv,jNouv);
                 }
                 else if(situation(t)==SITUATION_MORT)
                 {
                    t.supprimerElement(posActuelle);
                 }
}

position joueurNormalMover::nouvellePosition(terrain &t)
{
    if(situation(t)==SITUATION_PEUT_SE_DEPLACER)
    {
        return nouvellePositionPotentiel();
    }
    else
    {
        return positionElem();
    }
}
