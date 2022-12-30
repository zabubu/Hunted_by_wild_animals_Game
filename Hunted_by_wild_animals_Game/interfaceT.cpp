#include "interfaceT.h"
#include "terrain.h"
#include "tigre.h"
#include "lion.h"
#include "pieges.h"
#include "arbres.h"
#include "joueurNormal.h"
#include "joueurExpert.h"

interfaceT::interfaceT()
{

}

void interfaceT::afficheTerrain(const terrain& ter) const
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
    std::cout<<"Nombre de fauves = "<<ter.nombreFauves()<<std::endl;
    std::cout<<"J = joueur  L = lion  T = tigre  P = piege  A = arbre"<<std::endl;

}

void interfaceT::afficheTigre(const tigre &t) const
{
    std::cout<<"T";
}

void interfaceT::afficheLion(const lion &l) const
{
    std::cout<<"L";
}

void interfaceT::affichePieges(const pieges &p) const
{
    std::cout<<"P";
}

void interfaceT::afficheArbres(const arbres& a) const
{
    std::cout<<"A";
}

void interfaceT::afficheJoueurExpert(const joueurExpert& a) const
{
    std::cout<<"E";
}

void interfaceT::afficheJoueurNormal(const joueurNormal& a) const
{
   std::cout<<"J";
}
