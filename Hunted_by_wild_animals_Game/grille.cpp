#include "grille.h"

grille::grille(int hauteur, int largeur) : d_hauteur{hauteur}, d_largeur{largeur}
{

}

double grille::renvoiHauteur() const
{
    return d_hauteur;
}

double grille::renvoiLargeur() const
{
    return d_largeur;
}

void grille::modifierHauteur(int h)
{
   d_hauteur = h;
}

void grille::modifierLargeur(int l)
{
   d_largeur = l;
}


