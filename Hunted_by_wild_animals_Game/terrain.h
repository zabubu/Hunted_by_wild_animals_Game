#ifndef TERRAIN_H
#define TERRAIN_H

#include <memory>
#include <vector>

#include <fstream>

class interface;
class elements;
class position;



class terrain
{
public :
    terrain();
    terrain(int hauteur, int largeur, int nbElem, int nbFauves, int nbPieges);
    terrain(const terrain &t);

    void taille(int hauteur, int largeur);

    double nombreElements() const;
    double nombreFauves() const;
    double nombrePieges() const;
    double hauteur() const;
    double largeur() const;
    const std::vector<std::vector<std::unique_ptr<elements>>>& tabElements() const;
    std::vector<position> tabPosFauves() const;
    position posJoueur() const;

    void ajouterElement(std::unique_ptr<elements> elem, const position &p);
    void supprimerElement(const position &p);

    void lireDepuisFichier(std::istream& ist);
    void enregistreDansFichier(std::ostream& ost);
    void creeTerrain();
    void affiche(const interface & inter) const;

    void modifierNbElements(int elem);
    void modifierNbFauves(int fauves);
    void modifierNbPieges(int pieges);

private :
    int d_nombreElements;
    int d_nombreFauves;
    int d_nombrePieges;
    int d_hauteur;
    int d_largeur;
    std::vector<std::vector<std::unique_ptr<elements>>> d_elems;
};



#endif // TERRAIN_H

