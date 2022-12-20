#include "Position.h"

//---------- Constructors----------------------------
Position::Position(int x,int y):
    d_x{x},
    d_y{y}
{
}
//---------- End of constructors---------------------

void Position::modifierX(double x)
{
    d_x=x;
}

void Position::modifierY(double y)
{
     d_y=y;
}

double Position::renvoyerX()const
{
  return d_x;
}

double Position::renvoyerY()const
{
   return d_y;
}

double Position::renvoyerDistance(const Position& p)const
{
    return sqrt(  ( (d_x-p.renvoyerX()) * (d_x-p.renvoyerX()) ) + ( (d_y-p.renvoyerY()) * (d_y-p.renvoyerY()) )   );
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

