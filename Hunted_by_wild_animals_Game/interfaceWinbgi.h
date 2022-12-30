#ifndef INTERFACEWINBGI_H
#define INTERFACEWINBGI_H
#include "position.h"
#include "terrain.h"
#include "fauves.h"
#include "pieges.h"
#include "lion.h"
#include "tigre.h"
#include "interface.h"
#include<memory>
#include <iostream>


class interfaceWinbgi : public interface
{
    public :
         interfaceWinbgi();
    void afficheTerrain(const terrain& ter) const override;
    void afficheTigre(const tigre &t) const override;
    void afficheLion(const lion &l) const override;
    void affichePieges(const pieges &p) const override;
    void afficheArbres(const arbres& a) const override;
    void afficheJoueurExpert(const joueurExpert& a) const override;
    void afficheJoueurNormal(const joueurNormal& a) const override;
    private :
};




#endif // INTERFACEWINBGI_H