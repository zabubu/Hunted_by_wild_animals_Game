#include "terrain.h"
#include <sstream>
#include <string>
#include "elements.h"
#include "elementsDeplacable.h"
#include "tigre.h"
#include "lion.h"
#include "arbres.h"
#include "pieges.h"
#include "position.h"
#include "joueurNormal.h"
#include "joueurExpert.h"
#include "joueur.h"
#include "fauves.h"
#include "interface.h"

#include "elementMover.h"
#include "joueurNormalMover.h"

terrain::terrain() : d_hauteur{0},
                     d_largeur{0},
                     d_tabElements{},
                     d_tabPosFauves{},
                     d_nbFauves{0}
{}


terrain::terrain(int largeur, int hauteur) :  d_hauteur{hauteur}, d_largeur{largeur}, d_tabPosFauves{},  d_nbFauves{0}
{
   d_tabElements.resize(hauteur);
   for(int i=0; i<hauteur; i++)
   {
       d_tabElements[i].resize(largeur);
   }
}

terrain::terrain(const terrain &t) :  d_hauteur{t.hauteur()}, d_largeur{t.largeur()} , d_tabPosFauves{},  d_nbFauves{0}
{
    d_tabElements.resize(t.hauteur());
    for(int i=0; i<t.hauteur(); i++)
    {
        d_tabElements[i].resize(t.largeur());
        for(int j=0; j<t.tabElements()[i].size(); j++)
        {
            auto elem = t.tabElements()[i][j].get()->clone();
            d_tabElements[i][j] = std::move(elem);
        }
    }
}


void terrain::taille(int hauteur, int largeur)
{
   d_tabElements.resize(hauteur);
   for(int i=0; i<hauteur; i++)
   {
       d_tabElements[i].resize(largeur);
   }

   d_hauteur = hauteur;
   d_largeur = largeur;
}

 double terrain::hauteur() const
 {
     return d_hauteur;
 }

double terrain::largeur() const
{
     return d_largeur;
}


const std::vector<std::vector<std::unique_ptr<elements>>>& terrain::tabElements() const
{
     return d_tabElements;
}

void terrain::miseAjourTabPosFauves()
{
    d_tabPosFauves.resize(0);

    for(int i=0; i<d_hauteur; i++)
    {
        for(int j=0; j<d_largeur; j++)
        {
             if(dynamic_cast<fauves*>(d_tabElements[i][j].get()))
             {
                position pos{i,j};
                d_tabPosFauves.push_back(pos);
             }
        }
    }
}

const std::vector<position>& terrain::tabPositionFauves() const
{
    return d_tabPosFauves;
}


void terrain::ajouterElement(std::unique_ptr<elements> elem, const position &pos)
{
      if(d_tabElements[pos.getI()][pos.getJ()].get()==nullptr)
        {
            if(dynamic_cast<fauves*>(elem.get()))
            {
                d_tabPosFauves.push_back(pos);
                d_nbFauves++;
            }
            d_tabElements[pos.getI()][pos.getJ()] = std::move(elem);
        }
    }

void terrain::supprimerCaseTabPositionFauves(const position &pos)
{
    int i=0;
    while(i<d_tabPosFauves.size() && d_tabPosFauves[i]!=pos)
    {
      i++;
    }
    if(d_tabPosFauves[i]==pos)
    {
            for(int j=i; j<d_tabPosFauves.size()-1; j++)
            {
                d_tabPosFauves[j]=d_tabPosFauves[j+1];
            }
    }
    d_tabPosFauves.pop_back();
}
void terrain::supprimerElement(const position &pos)
{

        auto obj = d_tabElements[pos.getI()][pos.getJ()].get();
        if(obj!=nullptr)
        {
            if(dynamic_cast<fauves*>(obj))
            {
              supprimerCaseTabPositionFauves(pos);
              d_nbFauves--;
            }
            d_tabElements[pos.getI()][pos.getJ()].reset();
        }
}

int terrain::nombreFauves() const
{
    return d_nbFauves;
}


void terrain::lireDepuisFichier(std::istream& ist)
{
   int largeur,longueur;
   char c;
   ist>>c>>largeur>>c>>longueur>>c;

    taille(largeur,longueur);

    int cptLargeur=0, cptLongueur=0;

    while(!ist.eof() && cptLargeur<largeur && cptLongueur <longueur)
    {
        ist>>c;
        position p{cptLongueur,cptLargeur};
        if(c=='L')
        {
            auto ar{std::make_unique<lion>(p)};
            ajouterElement(std::move(ar),p);
        }
        else if(c=='T')
        {
           auto ar{std::make_unique<tigre>(p)};
           ajouterElement(std::move(ar),p);
        }
        else if(c=='A')
        {
             auto ar{std::make_unique<arbres>(p)};
             ajouterElement(std::move(ar),p);

        }
        else if(c=='P')
        {
            auto ar{std::make_unique<pieges>(p)};
             ajouterElement(std::move(ar),p);
        }
        else if(c=='J')
        {
            auto ar{std::make_unique<joueurNormal>(p)};
             ajouterElement(std::move(ar),p);
        }
        else if(c=='E')
        {
            auto ar{std::make_unique<joueurExpert>(p)};
             ajouterElement(std::move(ar),p);
        }

        cptLargeur++;
        if(cptLargeur==largeur)
        {
            cptLargeur=0;
            cptLongueur+=1;
        }
    }
}

void terrain::enregistreDansFichier(std::ostream& ost)
{
   ost<<"["<<hauteur()<<";"<<largeur()<<"]"<<"\n";

   for(int i=0; i<hauteur(); i++)
   {
       for(int j=0; j<largeur(); j++)
       {
           auto elem = d_tabElements[i][j].get();
           if(dynamic_cast<lion*>(elem))
           {
              ost<<"L";
           }
           else if(dynamic_cast<tigre*>(elem))
           {
              ost<<"T";
           }
           else if(dynamic_cast<joueurExpert*>(elem))
           {
               ost<<"E";
           }
            else if(dynamic_cast<pieges*>(elem))
           {
               ost<<"P";
           }
            else if(dynamic_cast<joueurNormal*>(elem))
           {
                ost<<"J";
           }
           else if(dynamic_cast<arbres*>(elem))
           {
                ost<<"A";
           }
           else
           {
               ost<<".";
           }
       }
       ost<<'\n';
   }
}

position terrain::posJoueur() const
{
    for(int i = 0 ; i < hauteur() ; i++)
    {
        for(int j = 0 ; j < largeur() ; j++)
        {
            auto elem = d_tabElements[i][j].get();
            if(elem!=nullptr)
            {
                if(dynamic_cast<joueur*>(elem))
                {
                    return position{i,j};
                }
            }
        }
    }
    return position{-1,-1};
}

void terrain::affiche(const interface &inter) const
{
    inter.afficheTerrain(*this);
}

void terrain::creeTerrain()
{
        int hauteur,largeur,nbPieges, nbLions,nbTigres, nbArbres;
        char type;
        std::cout<<"Hauteur du terrain :"<<std::endl;
        std::cin>>hauteur;
        std::cout<<"Largeur du terrain :"<<std::endl;
        std::cin>>largeur;
        std::cout<<"Nombre de pieges"<<std::endl;
        std::cin>>nbPieges;
        std::cout<<"Nombre de tigres:"<<std::endl;
        std::cin>>nbTigres;
        std::cout<<"Nombre de lions:"<<std::endl;
        std::cin>>nbLions;
        std::cout<<"Nombre de arbres:"<<std::endl;
        std::cin>>nbArbres;
        std::cout<<"Type de joueur :  E (expert) ou N (normal)"<<std::endl;
        std::cin>>type;

        taille(hauteur,largeur);


        int lig,col;
        for(int i=0; i<nbPieges; i++)
        {
            std::cout<<"Donnez la ligne du piege"<<i+1<<std::endl;
            std::cin>>lig;
            std::cout<<"Donnez la colonne du piege"<<i+1<<std::endl;
            std::cin>>col;
            position p{lig,col};
            auto e{std::make_unique<pieges>(p)};
            ajouterElement(std::move(e),p);
        }

        for(int i=0; i<nbLions; i++)
        {
            std::cout<<"Donnez la ligne du lion"<<i+1<<std::endl;
            std::cin>>lig;
            std::cout<<"Donnez la colonne du lion"<<i+1<<std::endl;
            std::cin>>col;
            position p{lig,col};
            auto e{std::make_unique<lion>(p)};
            ajouterElement(std::move(e),p);
        }

        for(int i=0; i<nbTigres; i++)
        {
            std::cout<<"Donnez la ligne du tigre"<<i+1<<std::endl;
            std::cin>>lig;
            std::cout<<"Donnez la colonne du tigre"<<i+1<<std::endl;
            std::cin>>col;
            position p{lig,col};
            auto e{std::make_unique<tigre>(p)};
            ajouterElement(std::move(e),p);
        }

        for(int i=0; i<nbArbres; i++)
        {
            std::cout<<"Donnez la ligne de l'arbre"<<i+1<<std::endl;
            std::cin>>lig;
            std::cout<<"Donnez la colonne de l'arbre"<<i+1<<std::endl;
            std::cin>>col;
            position p{lig,col};
            auto e{std::make_unique<arbres>(p)};
            ajouterElement(std::move(e),p);
        }



        std::cout<<"Donnez la ligne du joueur"<<std::endl;
        std::cin>>lig;
        std::cout<<"Donnez la colonne du joueur"<<std::endl;
        std::cin>>col;
        position p{lig,col};

            if(type == 'E')
            {
                    auto e{std::make_unique<joueurNormal>(p)};
                    ajouterElement(std::move(e),p);
            }
            else if(type == 'N')
            {
                    auto e{std::make_unique<joueurNormal>(p)};
                    ajouterElement(std::move(e),p);
            }

            std::cout<<"Voulez vous enregistrer le terrain ? (o / n)"<<std::endl;
            std::cin>>type;

            if(type=='o')
            {
                std::string nom;
                std::cout<<"Donnez le nom du fichier"<<std::endl;
                std::cin>>nom;
                std::ofstream la;
                la.open(nom);
                enregistreDansFichier(la);
            }

}

 int terrain::typeElementCase(const position &pos) const
 {
     int type;

     auto elem = d_tabElements[pos.getI()][pos.getJ()].get();

     if(dynamic_cast<joueurNormal*>(elem))
     {
        type = TYPE_JOUEUR_NORMAL;
     }
     else if(dynamic_cast<joueurExpert*>(elem))
     {
        type =TYPE_JOUEUR_EXPERT;
     }
     else if(dynamic_cast<lion*>(elem))
     {
        type = TYPE_LION;
     }
     else if(dynamic_cast<tigre*>(elem))
     {
       type = TYPE_TIGRE;
     }
     else if(dynamic_cast<pieges*>(elem))
     {
        type = TYPE_PIEGE;
     }
     else if(dynamic_cast<arbres*>(elem))
     {
        type = TYPE_ARBRE;
     }
     else
     {
         type = CASE_VIDE;
     }
     return type;
 }

void terrain::changeCase(int iAct,int jAct,int iNouv,int jNouv)
{
    d_tabElements[iNouv][jNouv] = move(d_tabElements[iAct][jAct]);
}



bool terrain::joueurEnVie()
{
    position positionJoueur = posJoueur();

    bool enVie;
    if(positionJoueur.getI()==-1 && positionJoueur.getJ()==-1)
    {
        enVie = false;
    }
    else
    {
        enVie = false;
    }
    return enVie;
}
