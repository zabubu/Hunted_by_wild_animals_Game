#include "interfaceWinbgi.h"
#include "terrain.h"
#include "tigre.h"
#include "lion.h"
#include "pieges.h"
#include "arbres.h"
#include "joueurNormal.h"
#include "joueurExpert.h"
#include "position.h"


interfaceWinbgi::interfaceWinbgi():width{1000},
                                    height{1000}

{
    initialize();
}






void interfaceWinbgi::afficheTerrain(const terrain& ter) const
{
    int caseWidth = 30; // Largeur d'une case en pixels
    int caseHeight = 30; // Hauteur d'une case en pixels

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
                position un{x-5,y-5};
                position quatre{x+5,y+5};
                setcolor(WHITE);
                bar(un.i()+50,un.j()+50,quatre.i()+50,quatre.j()+50);
            }
        }
    }
}

void interfaceWinbgi::afficheTigre(const tigre &t) const
{
    int caseWidth = 30; // Largeur d'une case en pixels
    int caseHeight = 30; // Hauteur d'une case en pixels
    int y=t.posElem().i()*caseWidth;
    int x=t.posElem().j()*caseHeight;
    position un{x-5,y-5};
    position quatre{x+5,y+5};
    setcolor(RED);
    bar(un.i()+50,un.j()+50,quatre.i()+50,quatre.j()+50);
}

void interfaceWinbgi::afficheLion(const lion &l) const
{
    int caseWidth = 30; // Largeur d'une case en pixels
    int caseHeight = 30; // Hauteur d'une case en pixels
    int y=l.posElem().i()*caseWidth;
    int x=l.posElem().j()*caseHeight;
    position un{x-5,y-5};
    position quatre{x+5,y+5};
    setcolor(YELLOW);
    bar(un.i()+50,un.j()+50,quatre.i()+50,quatre.j()+50);
}

void interfaceWinbgi::affichePieges(const pieges &p) const
{
    int caseWidth = 30; // Largeur d'une case en pixels
    int caseHeight = 30; // Hauteur d'une case en pixels
    int y=p.posElem().i()*caseWidth;
    int x=p.posElem().j()*caseHeight;
    position un{x-5,y-5};
    position quatre{x+5,y+5};
    setcolor(BLUE);
    bar(un.i()+50,un.j()+50,quatre.i()+50,quatre.j()+50);
}

void interfaceWinbgi::afficheArbres(const arbres& a) const
{
    int caseWidth = 30; // Largeur d'une case en pixels
    int caseHeight = 30; // Hauteur d'une case en pixels
    int y=a.posElem().i()*caseWidth;
    int x=a.posElem().j()*caseHeight;
    position un{x-5,y-5};
    position quatre{x+5,y+5};
    setcolor(GREEN);
    bar(un.i()+50,un.j()+50,quatre.i()+50,quatre.j()+50);
}

void interfaceWinbgi::afficheJoueurExpert(const joueurExpert& a) const
{
    int caseWidth = 30; // Largeur d'une case en pixels
    int caseHeight = 30; // Hauteur d'une case en pixels
    int y=a.posElem().i()*caseWidth;
    int x=a.posElem().j()*caseHeight;
     //readimagefile("C++.jpg",0,0,x,y)
    position un{x-5,y-5};
    position quatre{x+5,y+5};
    setcolor(CYAN);
    bar(un.i()+50,un.j()+50,quatre.i()+50,quatre.j()+50);

}

void interfaceWinbgi::afficheJoueurNormal(const joueurNormal& a) const
{
    int caseWidth = 30; // Largeur d'une case en pixels
    int caseHeight = 30; // Hauteur d'une case en pixels
    int y=a.posElem().i()*caseWidth;
    int x=a.posElem().j()*caseHeight;
     //readimagefile("C++.jpg",0,0,x,y)
    position un{x-5,y-5};
    position quatre{x+5,y+5};
    setcolor(CYAN);
    bar(un.i()+50,un.j()+50,quatre.i()+50,quatre.j()+50);
}

void interfaceWinbgi::initialize()
{
    opengraphsize(width, height);
}
