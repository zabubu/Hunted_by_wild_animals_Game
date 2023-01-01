#ifndef TIGRE_H
#define TIGRE_H


#include "fauves.h"
#include <iostream>


class position;
class terrain;
class interface;

class tigre : public fauves
{
    public :
    tigre(const position &pos);
    std::unique_ptr<elements> clone() override;
    void affiche(const interface &inter) const override;
    void deplace(terrain &t , int direction)override;

};



#endif // TIGRE_H


