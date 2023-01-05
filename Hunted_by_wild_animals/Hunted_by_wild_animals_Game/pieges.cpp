#include "pieges.h"
#include "position.h"
#include "interface.h"


pieges::pieges(const position & pos) : elements{pos}
{

}

std::unique_ptr<elements> pieges::clone()
{
     auto p {std::make_unique<pieges>(posElem())};
    return p;
}

void pieges::affiche(const interface &inter) const
{
    inter.affichePieges(*this);
}

