#ifndef LION_H
#define LION_H

#include "fauves.h"
#include <iostream>
#include <memory>

class elements;
class interface;
class position;
class terrain;

class lion : public fauves
{
public:
    lion(const position & pos);
    position avanceVers(int i) override;
    int deplaceEn(const position &pos,terrain &t) override;
    std::unique_ptr<elements> clone() override;
    void affiche(const interface &inter) const override;
    std::vector<int> directionDeplacement(const position &posJoueur) const override;

};



#endif // LION_H
