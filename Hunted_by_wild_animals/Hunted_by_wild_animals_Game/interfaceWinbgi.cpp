#include "interfaceWinbgi.h"
#include "terrain.h"
#include "tigre.h"
#include "lion.h"
#include "pieges.h"
#include "arbres.h"
#include "joueurNormal.h"
#include "joueurExpert.h"
#include "position.h"

constexpr int CONSTANT {110};//constante permettant un affichage centrale du jeu
constexpr int SIZE {30};// taille d'un rectangle du terrain

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
                int x = j * SIZE; // Coordonnées x du pixel à dessiner
                int y = i * SIZE; // Coordonnées y du pixel à dessiner
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
    int y=t.posElem().getI()*SIZE;
    int x=t.posElem().getJ()*SIZE;
    position BAS{x-5,y-5};
    position HAUT{x+5,y+5};
    setcolor(RED);
    bar(BAS.getI()+CONSTANT,BAS.getJ()+CONSTANT,HAUT.getI()+CONSTANT,HAUT.getJ()+CONSTANT);
}

void interfaceWinbgi::afficheLion(const lion &l) const
{
    int y=l.posElem().getI()*SIZE;
    int x=l.posElem().getJ()*SIZE;
    position BAS{x-5,y-5};
    position HAUT{x+5,y+5};
    setcolor(YELLOW);
    bar(BAS.getI()+CONSTANT,BAS.getJ()+CONSTANT,HAUT.getI()+CONSTANT,HAUT.getJ()+CONSTANT);
}

void interfaceWinbgi::affichePieges(const pieges &p) const
{
    int y=p.posElem().getI()*SIZE;
    int x=p.posElem().getJ()*SIZE;
    position BAS{x-5,y-5};
    position HAUT{x+5,y+5};
    setcolor(DARKGRAY);
    bar(BAS.getI()+CONSTANT,BAS.getJ()+CONSTANT,HAUT.getI()+CONSTANT,HAUT.getJ()+CONSTANT);
}

void interfaceWinbgi::afficheArbres(const arbres& a) const
{
    int y=a.posElem().getI()*SIZE;
    int x=a.posElem().getJ()*SIZE;
    position BAS{x-5,y-5};
    position HAUT{x+5,y+5};
    setcolor(GREEN);
    bar(BAS.getI()+CONSTANT,BAS.getJ()+CONSTANT,HAUT.getI()+CONSTANT,HAUT.getJ()+CONSTANT);
}
void interfaceWinbgi::afficheJoueurExpert(const joueurExpert& a) const
{
    int y=a.posElem().getI()*SIZE;
    int x=a.posElem().getJ()*SIZE;
    position BAS{x-5,y-5};
    position HAUT{x+5,y+5};
    setcolor(CYAN);
    bar(BAS.getI()+CONSTANT,BAS.getJ()+CONSTANT,HAUT.getI()+CONSTANT,HAUT.getJ()+CONSTANT);

}

void interfaceWinbgi::afficheJoueurNormal(const joueurNormal& a) const
{
    int y=a.posElem().getI()*SIZE;
    int x=a.posElem().getJ()*SIZE;
    position BAS{x-5,y-5};
    position HAUT{x+5,y+5};
    setcolor(CYAN);
    bar(BAS.getI()+CONSTANT,BAS.getJ()+CONSTANT,HAUT.getI()+CONSTANT,HAUT.getJ()+CONSTANT);
}

void interfaceWinbgi::initialize()
{
    opengraphsize(width, height);
}
