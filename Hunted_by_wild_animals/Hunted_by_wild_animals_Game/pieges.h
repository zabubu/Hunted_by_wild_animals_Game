#ifndef PIEGES_H
#define PIEGES_H

#include <iostream>
#include "elements.h"
#include <memory>

class interface;
class position;

class pieges : public elements
{
public :
    pieges(const position & pos);
    std::unique_ptr<elements> clone() override;
    void affiche(const interface &inter) const override;
};




#endif // PIEGES_H
