#include "pieges.h"
#include "position.h"
#include "interface.h"


pieges::pieges(const position & pos) : elements{pos}
{

}

std::unique_ptr<elements> pieges::clone()
{

}

void pieges::affiche(const interface &inter) const
{
    inter.affichePieges(*this);
}

