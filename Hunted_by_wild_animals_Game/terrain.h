#ifndef TERRAIN_H
#define TERRAIN_H

#include <memory>
#include <vector>
#include "elements.h"
#include "grille.h"

//terrain de jeu


class terrain : public grille {
public :
    terrain();
    terrain(int hauteur, int largeur, int nbElem, int nbMaxFauves, int nbMaxPieges);
    double nombreElements() const;
    double nombreFauves() const;
    double nombrePieges() const;
    double nombreMaxFauves() const;
    double nombreMaxPieges() const;
    void modifierNbFauvesMax(int FMax);
    void modifierNbPiegesMax(int PMax);
   /* void ajouterElement(std::unique_ptr<elements> elem, int i, int j);
    void supprimerElement(int i, int j);*/
private :
    int d_nombreElements;
    int d_nombreFauves;
    int d_nombrePieges;
    int d_nombreMaxFauves;
    int d_nombreMaxPieges;
    std::vector<std::vector<std::unique_ptr<elements>>> d_elems;
};



#endif // TERRAIN_H

