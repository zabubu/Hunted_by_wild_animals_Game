#include "grille.h"
//grille de jeu

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

void grille::affiche(std::ostream &ost) const
{
    std::string s =  "[" + std::to_string(d_hauteur) + " ; " + std::to_string(d_largeur) + "]";
    ost<<s;
}

void grille::lit(std::istream &ist)
{
    double hauteur, largeur;
    char c;
    ist>>c>>hauteur>>c>>largeur>>c;
    if(ist.good())
    {
        d_hauteur  = hauteur;
        d_largeur = largeur;
    }
}

std::ostream& operator<<(std::ostream& ost, const grille& g)
{
    g.affiche(ost);
    return ost;
}

std::istream& operator>>(std::istream& ist, grille& g)
{
    g.lit(ist);
    return ist;
}
