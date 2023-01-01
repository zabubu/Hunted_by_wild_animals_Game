#ifndef GRILLE_H
#define GRILLE_H

#include <iostream>
#include <string>

//grille de jeu
class grille
{
public :
    grille(int hauteur, int largeur);
    ~grille ()=default;
    double renvoiHauteur() const;
    double renvoiLargeur() const;
    void modifierHauteur(int h);
    void modifierLargeur(int l);
    void lit(std::istream &ist);
    void affiche(std::ostream &ost) const;

protected :
    int d_hauteur, d_largeur;
};

std::ostream& operator<<(std::ostream& ost, const grille & g);

std::istream& operator>>(std::istream& ist, grille& g);



#endif // GRILLE_H
