#include "interfaceWinbgi.h"
#include "terrain.h"
#include "tigre.h"
#include "lion.h"
#include "pieges.h"
#include "arbres.h"
#include "joueurNormal.h"
#include "joueurExpert.h"
#include "position.h"

constexpr int CONSTANT {100};
constexpr int caseWidth {30};
constexpr int caseHeight {30};

interfaceWinbgi::interfaceWinbgi():width{500},
                                    height{500}

{
    initialize();
}


void interfaceWinbgi::afficheTerrain(const terrain& ter) const
{
    for(int i=0; i<ter.hauteur(); i++)
     {
        for(int j=0; j<ter.largeur(); j++)
        {
            if(ter.tabElements()[i][j].get()!=nullptr)
            {
                ter.tabElements()[i][j]->affiche(*this);
            }
            else
            {
                int x = j * caseWidth; // Coordonnées x du pixel à dessiner
                int y = i * caseHeight; // Coordonnées y du pixel à dessiner
                position BAS{x-5,y-5};
                position HAUT{x+5,y+5};
                setcolor(WHITE);
                bar(BAS.getI()+CONSTANT,BAS.getJ()+CONSTANT, HAUT.getI()+CONSTANT, HAUT.getJ()+CONSTANT);
            }
        }
    }
}

void interfaceWinbgi::afficheTigre(const tigre &t) const
{
    int y=t.posElem().getI()*caseWidth;
    int x=t.posElem().getJ()*caseHeight;
    position BAS{x-5,y-5};
    position HAUT{x+5,y+5};
    setcolor(RED);
    bar(BAS.getI()+CONSTANT,BAS.getJ()+CONSTANT,HAUT.getI()+CONSTANT,HAUT.getJ()+CONSTANT);
}

void interfaceWinbgi::afficheLion(const lion &l) const
{
    int y=l.posElem().getI()*caseWidth;
    int x=l.posElem().getJ()*caseHeight;
    position BAS{x-5,y-5};
    position HAUT{x+5,y+5};
    setcolor(YELLOW);
    bar(BAS.getI()+CONSTANT,BAS.getJ()+CONSTANT,HAUT.getI()+CONSTANT,HAUT.getJ()+CONSTANT);
}

void interfaceWinbgi::affichePieges(const pieges &p) const
{
    int y=p.posElem().getI()*caseWidth;
    int x=p.posElem().getJ()*caseHeight;
    position BAS{x-5,y-5};
    position HAUT{x+5,y+5};
    setcolor(BLUE);
    bar(BAS.getI()+CONSTANT,BAS.getJ()+CONSTANT,HAUT.getI()+CONSTANT,HAUT.getJ()+CONSTANT);
}

void interfaceWinbgi::afficheArbres(const arbres& a) const
{
    int y=a.posElem().getI()*caseWidth;
    int x=a.posElem().getJ()*caseHeight;
    position BAS{x-5,y-5};
    position HAUT{x+5,y+5};
    setcolor(GREEN);
    bar(BAS.getI()+CONSTANT,BAS.getJ()+CONSTANT,HAUT.getI()+CONSTANT,HAUT.getJ()+CONSTANT);
}
void interfaceWinbgi::afficheJoueurExpert(const joueurExpert& a) const
{
    int y=a.posElem().getI()*caseWidth;
    int x=a.posElem().getJ()*caseHeight;
    position BAS{x-5,y-5};
    position HAUT{x+5,y+5};
    setcolor(CYAN);
    bar(BAS.getI()+CONSTANT,BAS.getJ()+CONSTANT,HAUT.getI()+CONSTANT,HAUT.getJ()+CONSTANT);

}

void interfaceWinbgi::afficheJoueurNormal(const joueurNormal& a) const
{
    int y=a.posElem().getI()*caseWidth;
    int x=a.posElem().getJ()*caseHeight;
    position BAS{x-5,y-5};
    position HAUT{x+5,y+5};
    setcolor(CYAN);
    bar(BAS.getI()+CONSTANT,BAS.getJ()+CONSTANT,HAUT.getI()+CONSTANT,HAUT.getJ()+CONSTANT);
}

void interfaceWinbgi::initialize()
{
    opengraphsize(width, height);
}
