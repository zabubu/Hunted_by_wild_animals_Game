#include "interfaceWinbgi.h"
#include "terrain.h"
#include "tigre.h"
#include "lion.h"
#include "pieges.h"
#include "arbres.h"
#include "joueurNormal.h"
#include "joueurExpert.h"



interfaceWinbgi::interfaceWinbgi()
{

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
                std::cout<<".";
            }
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl<<"Nombre de fauves = "<<ter.nombreFauves()<<std::endl;
    std::cout<<"Nombre d'elements"<<ter.nombreElements();

}

void interfaceWinbgi::afficheTigre(const tigre &t) const
{
    std::cout<<"T";
}

void interfaceWinbgi::afficheLion(const lion &l) const
{
    std::cout<<"L";
}

void interfaceWinbgi::affichePieges(const pieges &p) const
{
    std::cout<<"P";
}

void interfaceWinbgi::afficheArbres(const arbres& a) const
{
    std::cout<<"A";
}

void interfaceWinbgi::afficheJoueurExpert(const joueurExpert& a) const
{
    std::cout<<"E";
}

void interfaceWinbgi::afficheJoueurNormal(const joueurNormal& a) const
{
   std::cout<<"J";
}
