#include "terrain.h"
#include <sstream>
#include <string>

//terrain de jeu
terrain::terrain() : grille{0,0},
                     d_nombreElements{0},
                     d_nombreFauves{0},
                     d_nombrePieges{0},
                     d_nombreMaxFauves{0},
                     d_nombreMaxPieges{0}
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


void terrain::modifierNbFauvesMax(int FMax)
{
    d_nombreMaxFauves = FMax;
}

void terrain::modifierNbPiegesMax(int PMax)
{
    d_nombreMaxPieges = PMax;
}

/*void terrain::ajouterElement(std::unique_ptr<elements> elem, int i, int j)
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
            if(dynamic_cast<fauves>(elem.get()))
            {
                d_nombreFauves++;
            }
            d_elems[i][j] = move(elem);
            d_nombreElements++;
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
*/















