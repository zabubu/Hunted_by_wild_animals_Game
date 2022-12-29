#ifndef INTERFACET_H
#define INTERFACET_H

#include "interface.h"
#include <iostream>


class interfaceT : public interface
{
public :
    interfaceT();
    void afficheTerrain(const terrain& ter) const override;
    void afficheTigre(const tigre &t) const override;
    void afficheLion(const lion &l) const override;
    void affichePieges(const pieges &p) const override;
    void afficheArbres(const arbres& a) const override;
    void afficheJoueurExpert(const joueurExpert& a) const override;
    void afficheJoueurNormal(const joueurNormal& a) const override;
};




#endif // INTERFACET_H
