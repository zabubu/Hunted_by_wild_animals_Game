#ifndef INTERFACE_H
#define INTERFACE_H

class terrain;
class tigre;
class lion;
class pieges;
class arbres;
class joueurExpert;
class joueurNormal;

class interface
{

    public :
     ~interface() = default;
     virtual void afficheTerrain(const terrain& ter) const = 0;
     virtual void afficheTigre(const tigre &t) const = 0;
     virtual void afficheLion(const lion &l) const = 0;
     virtual void affichePieges(const pieges &p) const = 0;
     virtual void afficheArbres(const arbres& a) const = 0;
     virtual void afficheJoueurExpert(const joueurExpert& a) const = 0;
     virtual void afficheJoueurNormal(const joueurNormal& a) const = 0;
};


#endif // INTERFACE_H

