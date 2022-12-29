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

terrain::terrain() : d_nombreElements{0},
                     d_nombreFauves{0},
                     d_nombrePieges{0},
                     d_hauteur{0},
                     d_largeur{0}
{}


terrain::terrain(int largeur, int hauteur, int nbElem, int nbFauves, int nbPieges) : d_nombreElements{nbElem},
                                                                                     d_nombreFauves{nbFauves},
                                                                                     d_nombrePieges{nbPieges},
                                                                                     d_hauteur{hauteur},
                                                                                     d_largeur{largeur}
{
   d_elems.resize(hauteur);
   for(int i=0; i<hauteur; i++)
   {
       d_elems[i].resize(largeur);
   }
}

terrain::terrain(const terrain &t) :  d_nombreElements{t.nombreElements()},
                                      d_nombreFauves{t.nombreFauves()},
                                      d_nombrePieges{t.nombrePieges()},
                                      d_hauteur{t.hauteur()},
                                      d_largeur{t.largeur()}
{
    d_elems.resize(t.hauteur());
    for(int i=0; i<t.hauteur(); i++)
    {
        d_elems[i].resize(t.largeur());
        for(int j=0; j<t.tabElements()[i].size(); j++)
        {
            auto elem = t.tabElements()[i][j].get()->clone();
            d_elems[i][j] = std::move(elem);
        }
    }
}


void terrain::taille(int hauteur, int largeur)
{
   d_elems.resize(hauteur);
   for(int i=0; i<hauteur; i++)
   {
       d_elems[i].resize(largeur);
   }

   d_hauteur = hauteur;
   d_largeur = largeur;
}

double terrain::nombreElements() const
{
    return d_nombreElements;
}

double terrain::nombreFauves() const
{
    return d_nombreFauves;
}

double terrain::nombrePieges() const
{
    return d_nombrePieges;
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
     return d_elems;
 }


void terrain::ajouterElement(std::unique_ptr<elements> elem, const position &pos)
{
      if(d_elems[pos.i()][pos.j()].get()==nullptr)
        {
            if(dynamic_cast<fauves*>(elem.get()))
            {
                d_nombreFauves++;
            }
            d_elems[pos.i()][pos.j()] = move(elem);
            d_nombreElements++;
        }
    }

void terrain::supprimerElement(const position &pos)
{

        auto obj = d_elems[pos.i()][pos.j()].get();
        if(obj!=nullptr)
        {
            if(dynamic_cast<fauves*>(obj))
            {
                d_nombreFauves--;
            }
            else if(dynamic_cast<pieges*>(obj))
            {
                d_nombrePieges--;
            }
            d_elems[pos.i()][pos.j()].reset();
            d_nombreElements--;
        }
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
           auto elem = d_elems[i][j].get();
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

std::vector<position> terrain::tabPosFauves() const
{
    std::vector<position> tabPosFauves;

    for(int i = 0 ; i < hauteur() ; i++)
    {
        for(int j = 0 ; j < largeur() ; j++)
        {
            auto elem = d_elems[i][j].get();
            if(elem!=nullptr)
            {
                if(dynamic_cast<fauves*>(elem))
                {
                    tabPosFauves.push_back(position{i,j});
                }
            }
        }
    }
    return tabPosFauves;
}

position terrain::posJoueur() const
{
    for(int i = 0 ; i < hauteur() ; i++)
    {
        for(int j = 0 ; j < largeur() ; j++)
        {
            auto elem = d_elems[i][j].get();
            if(elem!=nullptr)
            {
                if(dynamic_cast<joueur*>(elem))
                {
                    return position{i,j};
                }
            }
        }
    }
    return position{1000,1000};
}

void terrain::affiche(const interface &inter) const
{
    inter.afficheTerrain(*this);
}

void terrain::modifierNbElements(int elem)
{
    d_nombreElements = elem;
}

void terrain::modifierNbFauves(int fauves)
{
   d_nombreFauves = fauves;
}

void terrain::modifierNbPieges(int pieges)
{
    d_nombrePieges = pieges;
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

        int nbFauves = nbLions+nbTigres;
        int nbElements = nbLions+nbTigres+nbArbres+nbPieges;

        taille(hauteur,largeur);
        modifierNbElements(nbElements);
        modifierNbFauves(nbFauves);
        modifierNbPieges(nbPieges);


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
                    auto e{std::make_unique<joueurExpert>(p)};
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





