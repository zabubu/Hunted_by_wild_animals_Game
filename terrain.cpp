#include "terrain.h"
#include <sstream>
#include <string>

terrain::terrain() : grille{0, 0},
                     nombreElements{0},
                     nombreFauves{0},
                     nombrePieges{0},
                     nombreMaxFauves{0},
                     nombreMaxPieges{0}
{}


terrain::terrain(int largeur, int hauteur, int nbElem, int nbMaxFauves, int nbMaxPieges) : grille{largeur, hauteur},
                                                                                  d_nombreElements{0},
                                                                                  d_nombreFauves{0},
                                                                                  d_nombrePieges{0},
                                                                                  d_nombreMaxFauves{nbMaxFauves},
                                                                                  d_nombreMaxPieges{nbMaxPieges}
{
   d_elems.resize(hauteur);
   for(int i=0; i<hauteur; i++)
   {
       d_elems[i].resize(largeur);
   }
}

terrain::terrain(const terrain &t) :  grille{t.renvoiHauteur(), t.renvoiLargeur},
                                      d_nombreElements{t.nombreElements()},
                                      d_nombreFauves{t.nombreFauves()},
                                      nombrePieges{t.nombrePieges()},
                                      nombreMaxFauves{t.nombreMaxFauves()},
                                      nombreMaxPieges{t.nombreMaxPieges()}
{
    d_elems.resize(hauteur);
    for(int i=0; i<hauteur; i++)
    {
        elems[i].resize(largeur);
        for(int j=0; j<t.tabElements()[i].size(); j++)
        {
            auto elem = t.tabElements[i][j].get()->clone();
            elems[i][j] = std::move(elem);
        }
    }
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

double terrain::nombreMaxFauves() const
{
    return d_nombreMaxFauves;
}

double terrain::nombreMaxPieges() const
{
    return d_nombreMaxPieges;
}

const vector<vector<std::unique_ptr<object>>>& terrain::tabElements() const
 {
     return d_elems;
 }


void terrain::modifierNbFauvesMax(int FMax)
{
    d_nombreMaxFauves = FMax;
}

void terrain::modifierNbPiegesMax(int PMax)
{
    d_nombreMaxPieges = PMax;
}

void terrain::ajouterElement(std::unique_ptr<elements> elem, int i, int j)
{
    if(i > d_hauteur)
    {
        throw std::out_of_range("addObject: the i index is out of range");
    }
    else if(j > d_largeur)
    {
        throw std::out_of_range("addObject: the j index is out of range");
    }
    else
    {
        if(!d_elems[i][j].get())
        {
            if(dynamic_cast<fauves*>(elem.get()))
            {
                d_nombreFauves++;
            }
            d_elems[i][j] = move(elem);
            d_nombreElements++;
        }
    }
}


const vector<std::unique_ptr<fauve>>& terrain::tabFauves() const
{
    vector<std::unique_ptr<fauve>> tabFauves;

    for(int i = 0 ; i < d_hauteur ; i++)
    {
        for(int j = 0 ; j < d_largeur ; j++)
        {
            auto elem = d_elems[i][j].get();
            if(elem)
            {
                if(dynamic_cast<fauve*>(elem))
                {
                    tabFauves.push_back(*dynamic_cast<fauve*>(elem));
                }
            }
        }
    }
}




const vector<std::unique_ptr<pieges>& terrain::tabPieges() const
{
    vector<std::unique_ptr<pieges>> tabPieges;

    for(int i = 0 ; i < d_hauteur ; i++)
    {
        for(int j = 0 ; j < d_largeur ; j++)
        {
            auto elem = d_elems[i][j].get();
            if(elem)
            {
                if(dynamic_cast<pieges*>(elem))
                {
                    tabPieges.push_back(*dynamic_cast<pieges*>(elem));
                }
            }
        }
    }
}

void terrain::supprimerElement(int i, int j)
{

    if(i > d_hauteur)
    {
        throw std::out_of_range("The i index is out of range");
    }
    else if(j > d_largeur)
    {
        throw std::out_of_range("The j index is out of range");
    }
    else
    {
        auto elem = d_elems[i][j].get();
        if(elem)
        {
            if(dynamic_cast<fauve*>(elem))
            {
                d_nombreFauves--;
            }
            else if(dynamic_cast<pieges*>(elem))
            {
                d_nombrePieges--;
            }
            objects[i][j].reset();
            d_nombreObjects--;
        }
    }
}
















