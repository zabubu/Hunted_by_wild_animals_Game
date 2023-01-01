#ifndef GRILLE_H
#define GRILLE_H

#include <iostream>

class grille
{
public :
    grille(int hauteur, int largeur);
    ~grille ()=default;
    double renvoiHauteur() const;
    double renvoiLargeur() const;
    void modifierHauteur(int h);
    void modifierLargeur(int l);

private :
    int d_hauteur, d_largeur;
};


#endif // GRILLE_H
