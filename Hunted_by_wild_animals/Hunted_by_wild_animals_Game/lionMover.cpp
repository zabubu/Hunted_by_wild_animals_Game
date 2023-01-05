#include "lionMover.h"
#include "terrain.h"

lionMover::lionMover(const position &posElement) : elementMover{posElement}
{

}

position lionMover::positionSelonDirection()
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
}

std::vector<int> lionMover::tabDirectionsDeplacements(const position &posJoueur, const position &posTigre)
{
       std::vector<int> tabDeplacements;
     int Ijoueur = posJoueur.getI(), Jjoueur = posJoueur.getJ(), Ilion = posTigre.getI(), Jlion = posTigre.getJ();

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

position lionMover::nouvellePositionPotentiel(terrain &t)
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
       nouvellePos = positionSelonDirection();
       int elementSurCase = t.typeElementCase(nouvellePos);

       if(elementSurCase == t.TYPE_LION ||  elementSurCase == t.TYPE_ARBRE)
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

int lionMover::situation(terrain &t)
{
         position posActuelle = positionElem();
         position nouvellePos = nouvellePositionPotentiel(t);

          int elementSurCase = t.typeElementCase(nouvellePos);

          if(elementSurCase != t.TYPE_ARBRE && elementSurCase != t.TYPE_LION)
          {
             if(elementSurCase == t.CASE_VIDE)
             {
                return SITUATION_PEUT_SE_DEPLACER;
             }
             else if (elementSurCase == t.TYPE_PIEGE)
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

void lionMover::deplace(terrain &t)
{
         position posActuelle = positionElem();
          position nouvellePos = nouvellePositionPotentiel(t);

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
                    int iAct=posActuelle.getI(), jAct = posActuelle.getJ(), iNouv = nouvellePos.getI(), jNouv = nouvellePos.getJ();
                    t.changeCase(iAct,jAct,iNouv,jNouv);
                 }
}

position lionMover::nouvellePosition(terrain &t)
{
    if(situation(t)==SITUATION_PEUT_SE_DEPLACER || situation(t)==SITUATION_MANGE)
    {
        return nouvellePositionPotentiel(t);
    }
    else
    {
        return positionElem();
    }
}


