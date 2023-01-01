#include "position.h"
position::position() : d_i{0}, d_j{0}
{

}

position::position(int i, int j) : d_i{i}, d_j{j}
{

}


position::position(const position &p) : d_i{p.i()}, d_j{p.j()}
{

}

int position::i() const
{
    return d_i;
}

int position::j() const
{
    return d_j;
}

void position::modifieI(int i)
{
    d_i=i;
}

void position::modifieJ(int j)
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
        d_i = p.i();
        d_j = p.j();
    }
    return *this;
}

bool position::operator!=(const position& p) const
{
    return (d_i != p.i()) || (d_j != p.j());
}

bool position::operator==(const position& p) const
{
    return (d_i == p.i()) && (d_j == p.j());
}




