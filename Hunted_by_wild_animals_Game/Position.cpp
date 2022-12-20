#include "position.h"

//---------- Constructors----------------------------
position::position(int x,int y):
    d_x{x},
    d_y{y}
{
}
//---------- End of constructors---------------------

void position::modifierX(double x)
{
    d_x=x;
}

void position::modifierY(double y)
{
     d_y=y;
}

double position::x()const
{
  return d_x;
}

double position::y()const
{
   return d_y;
}

double position::renvoyerDistance(const position& p)const
{
    return sqrt(  ( (d_x-p.x()) * (d_x-p.x()) ) + ( (d_y-p.y()) * (d_y-p.y()) )   );
}

bool position::operator==(const position& p) const
{
    return (d_x == p.x()) && (d_y == p.y());
}

bool position::operator!=(const position& p) const
{
    return (x() != p.x()) || (y() != p.y());
}

position& position::operator=(const position& p)
{
    if(this != &p)
    {
        d_x = p.x();
        d_y = p.y();
    }
    return *this;
}

