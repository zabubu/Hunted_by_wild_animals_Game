#include "menu.h"
#include "interfaceT.h"
#include "interfaceWinbgi.h"
#include "terrain.h"
#include "partie.h"

#include "terrain.h"
#include <sstream>
#include <string>
#include "elements.h"
#include "tigre.h"
#include "lion.h"
#include "arbres.h"
#include "pieges.h"
#include "position.h"
#include "joueurNormal.h"
#include "joueurExpert.h"
#include "fauves.h"
#include "interface.h"

menu::menu() : d_numInterface{0} , d_numTerrain{0}
{

}

void menu::choixInterface()
{
    int choix;
    do
    {
        std::cout<<"======================== INTERFACE ========================"<<std::endl;
        std::cout<<"1 - Terminal"<<std::endl;
        std::cout<<"2 - Winbgi "<<std::endl;
        std::cin>>choix;

        if(choix == 1)
        {
            d_numInterface = 1;
        }
        else if(choix == 2)
        {
             d_numInterface = 2;
        }
    }while(!(choix == 1 || choix == 2));
}

std::unique_ptr<interface> menu::creationInterface() const
{
        if(d_numInterface==1)
        {
            return std::make_unique<interfaceT>();
        }
        else
        {
            return std::make_unique<interfaceWinbgi>();
        }
}



void menu::printGround(const std::string& nomFichier)
{
    interfaceT inter{};
    terrain t{};
    std::ifstream ifs(nomFichier);
    t.lireDepuisFichier(ifs);
    inter.afficheTerrain(t);
}

void menu::choixTerrain(std::string &nomF)
{
    int choix;
    do
    {
        std::cout<<"======================Terrain par defaut====================="<<std::endl;
        printGround("Terrain2.txt");
        std::cout<<std::endl;
        std::cout<<"================Terrain importe depuis fichier================"<<std::endl;
        std::cout<<"=============================================================="<<std::endl;
        std::cout<<std::endl;
        std::cout<<"=====================Terrain personnalise====================="<<std::endl;
        std::cout<<"=============================================================="<<std::endl;
        std::cout<<std::endl;
        std::cout<<std::endl;
        std::cout<<"1 - Terrain par defaut"<<std::endl;
        std::cout<<"2 - Terrain importe depuis fichier"<<std::endl;
        std::cout<<"3 - Terrain personnalise"<<std::endl;

        std::cin>>choix;


        if(choix == 1)
        {
           d_numTerrain = 1;
        }
        else if(choix == 2)
        {
             d_numTerrain = 2;
             std::cout<<"Entrer le nom du fichier"<<std::endl;
             std::cin>>nomF;
             printGround(nomF);
             std::cout<<std::endl;
        }
        else if(choix == 3)
        {
            std::cout<<"Au lancement de la partie vous creerez votre terrain personnalise"<<std::endl;
            d_numTerrain = 3;
        }

    }
    while(!(choix == 1 || choix == 2 || choix == 3));

}



void menu::menuPrincipale()
{
    int choix;
    bool choixI = false, choixT = false;
    std::string nomF;
    do
    {
        std::cout<<"====================== HUNTED BY WILD ANIMALS GAME ====================="<<std::endl<<std::endl;
        std::cout<<"1 - Choisir un mode graphique"<<std::endl;
        std::cout<<"2 - Choisir un terrain"<<std::endl;

        if(choixI && choixT)
            std::cout<<"3 - Lancer une partie"<<std::endl;

        std::cin>>choix;



        if(choix == 1)
        {
            choixInterface();
            choixI = true;
        }
        else if(choix == 2)
        {
            choixTerrain(nomF);
            choixT = true;
        }
        else if(choixI && choixT && choix == 3)
        {
            std::unique_ptr<interface> d_inter= creationInterface();
            partie p{std::move(d_inter)};

            if(d_numTerrain == 1)
            {
                p.lireFichier("Terrain1.txt");
            }
            else  if(d_numTerrain == 2)
            {
                p.lireFichier(nomF);
            }
            else if(d_numTerrain == 3)
            {
               p.nouveauTerrain();
            }

            p.joue();
        }
    }while(choix != 0);


}


