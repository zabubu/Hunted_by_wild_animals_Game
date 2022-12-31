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
    std::unique_ptr<elements> clone() override;
    void affiche(const interface &inter) const override;
    void deplace(terrain &t , int direction)override;

};



#endif // LION_H
