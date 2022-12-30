#ifndef ARBRES_H
#define ARBRES_H

#include <iostream>
#include "position.h"
#include "elements.h"


class arbres : public elements
{
public :
    arbres(const position & pos);
    std::unique_ptr<elements> clone() override;
    void affiche(const interface &inter) const override;

};




#endif // ARBRES_H


