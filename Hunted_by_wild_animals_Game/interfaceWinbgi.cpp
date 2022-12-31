#include "interfaceWinbgi.h"
#include "terrain.h"
#include "tigre.h"
#include "lion.h"
#include "pieges.h"
#include "arbres.h"
#include "joueurNormal.h"
#include "joueurExpert.h"
#include "position.h"


interfaceWinbgi::interfaceWinbgi():width{700},
                                    height{700}

{
    initialize();
}


void interfaceWinbgi::afficheTerrain(const terrain& ter) const
{
    int caseWidth = 10; // Largeur d'une case en pixels
    int caseHeight = 10; // Hauteur d'une case en pixels

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
                 putpixel(x, y, WHITE);
            }
        }
    }
}

void interfaceWinbgi::afficheTigre(const tigre &t) const
{
    int caseWidth = 10; // Largeur d'une case en pixels
    int caseHeight = 10; // Hauteur d'une case en pixels
    int x=t.posElem().i();
    int y=t.posElem().j();
     putpixel(x*caseWidth, y*caseWidth, GREEN);
}

void interfaceWinbgi::afficheLion(const lion &l) const
{
    int caseWidth = 10; // Largeur d'une case en pixels
    int caseHeight = 10; // Hauteur d'une case en pixels
    int x=l.posElem().i();
    int y=l.posElem().j();
     putpixel(x*caseWidth, y*caseWidth, GREEN);
}

void interfaceWinbgi::affichePieges(const pieges &p) const
{
    int caseWidth = 10; // Largeur d'une case en pixels
    int caseHeight = 10; // Hauteur d'une case en pixels
    int x=p.posElem().i();
    int y=p.posElem().j();
     putpixel(x*caseWidth, y*caseWidth, GREEN);
}

void interfaceWinbgi::afficheArbres(const arbres& a) const
{
    int caseWidth = 10; // Largeur d'une case en pixels
    int caseHeight = 10; // Hauteur d'une case en pixels
    int x=a.posElem().i();
    int y=a.posElem().j();
     putpixel(x*caseWidth, y*caseWidth, GREEN);
}

void interfaceWinbgi::afficheJoueurExpert(const joueurExpert& a) const
{
    int caseWidth = 10; // Largeur d'une case en pixels
    int caseHeight = 10; // Hauteur d'une case en pixels
    int x=a.posElem().i();
    int y=a.posElem().j();
     putpixel(x*caseWidth, y*caseWidth, GREEN);
}

void interfaceWinbgi::afficheJoueurNormal(const joueurNormal& a) const
{
    int caseWidth = 10; // Largeur d'une case en pixels
    int caseHeight = 10; // Hauteur d'une case en pixels
    int x=a.posElem().i();
    int y=a.posElem().j();
     putpixel(x*caseWidth, y*caseWidth, GREEN);
}

void interfaceWinbgi::initialize()
{
    opengraphsize(width, height);
}
