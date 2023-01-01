#ifndef PARTIE_H
#define PARTIE_H

#include "position.h"
#include "terrain.h"
#include "fauves.h"
#include "pieges.h"
#include "lion.h"
#include "tigre.h"
#include "interface.h"
#include "interfaceWinbgi.h"
#include "interfaceT.h"
#include "joueurNormal.h"
#include "joueurExpert.h"
#include <string>

#include <memory>
#include <iostream>


class partie
{
public :
    partie(std::unique_ptr<interface> inter);
    partie(const terrain &t, std::unique_ptr<interface> inter);
    bool positionValide(const position &pos);
    void ajoutePiege(const position &pos);
    void ajouteLion(const position &pos);
    void ajouteTigre(const position &pos);

    position newPosTigre(int i, std::unique_ptr<tigre> elem) const;
    position newPosLion(int i, std::unique_ptr<lion> elem) const;
    position newPosJExpert(int i, std::unique_ptr<joueurExpert> elem) const;
    position newPosJNormal(int i, std::unique_ptr<joueurNormal> elem) const;

    int situationTigre(const position &p, terrain &t, std::unique_ptr<tigre> elem) const;
    int situationLion(const position &p, terrain &t, std::unique_ptr<lion> elem) const;
    int situationJExpert(const position &p, terrain &t, std::unique_ptr<joueurExpert> elem) const;
    int situationJNormal(const position &p, terrain &t, std::unique_ptr<joueurNormal> elem) const;

    std::vector<int> directionDeplacementTigre(const position &posJoueur, std::unique_ptr<tigre> elem) const;
    std::vector<int> directionDeplacementLion(const position &posJoueur, std::unique_ptr<lion> elem) const;

    void lireFichier(const std::string& nomFichier);
    void affiche() const;
    void nouveauTerrain();
    void joue();
private :
    terrain d_t;
    std::unique_ptr<interface> d_inter;
};



#endif // PARTIE_H
