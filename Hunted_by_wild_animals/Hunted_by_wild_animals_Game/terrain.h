#ifndef TERRAIN_H
#define TERRAIN_H

#include <memory>
#include <vector>

#include <fstream>
#include <iostream>
#include <algorithm>
class interface;
class elements;
class position;
class elementsDeplacable;
class joueurNormal;
class elementMover;
class joueurExpert;



class terrain
{
public :
    terrain();
    terrain(int hauteur, int largeur);
    terrain(const terrain &t);

    void taille(int hauteur, int largeur);

    double hauteur() const;
    double largeur() const;

    const std::vector<std::vector<std::unique_ptr<elements>>>& tabElements() const;
    const std::vector<position>& tabPositionFauves() const;
    position posJoueur() const;
    int typeElementSurCase(const position &pos);

    void ajouterElement(std::unique_ptr<elements> elem, const position &p);
    void supprimerElement(const position &p);
    void supprimerCaseTabPositionFauves(const position &pos);

    void lireDepuisFichier(std::istream& ist);
    void enregistreDansFichier(std::ostream& ost);
    void creeTerrain();
    void affiche(const interface & inter) const;

    static constexpr int TYPE_LION {1};
    static constexpr int TYPE_TIGRE {2};
    static constexpr int TYPE_JOUEUR_NORMAL {3};
    static constexpr int TYPE_JOUEUR_EXPERT {4};
    static constexpr int TYPE_ARBRE {5};
    static constexpr int TYPE_PIEGE{6};
    static constexpr int CASE_VIDE{7};

    int typeElementCase(const position &pos) const;
    void changeCase(int iAct,int jAct,int iNouv,int jNouv);

    int nombreFauves() const;
    bool joueurEnVie();
    void miseAjourTabPosFauves();



private :
    int d_nombreFauves;
    int d_hauteur;
    int d_largeur;
    int d_nbFauves;
    std::vector<std::vector<std::unique_ptr<elements>>> d_tabElements;
    std::vector<position> d_tabPosFauves;
};



#endif // TERRAIN_H

