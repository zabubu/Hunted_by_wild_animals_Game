#include "position.h"
position::position() : d_i{0}, d_j{0}
{

}

position::position(int i, int j) : d_i{i}, d_j{j}
{

}


position::position(const position &p) : d_i{p.getI()}, d_j{p.getJ()}
{

}

int position::getI() const
{
    return d_i;
}

int position::getJ() const
{
    return d_j;
}

void position::setI(int i)
{
    d_i=i;
}

void position::setJ(int j)
{
    d_j = j;
}

void position::affiche(std::ostream &ost) const
{
    ost<<"["<<d_i<<";"<<d_j<<"]";
}

position& position::operator=(const position& p)
{
    if(this != &p)
    {
        d_i = p.getI();
        d_j = p.getJ();
    }
    return *this;
}

bool position::operator!=(const position& p) const
{
    return (d_i != p.getI()) || (d_j != p.getJ());
}

bool position::operator==(const position& p) const
{
    return (d_i == p.getI()) && (d_j == p.getJ());
}




