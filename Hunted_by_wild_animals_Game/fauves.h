#ifndef FAUVES_H
#define FAUVES_H
#include "position.h"
#include "ElementsEnMouvements"

class fauves : public ElementsEnMouvements{
    public:
    fauves();
    fauves(const position &p);
    fauves(int x, int y);
    virtual void deplaceVers(const joueur &j) const = 0;
    void deplaceEn(const position &p);
    bool deplacementAutorise(const position& p)const;
};

#endif