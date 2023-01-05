#include "arbres.h"
#include "interface.h"

arbres::arbres(const position & pos) : elements{pos}
{

}

std::unique_ptr<elements> arbres::clone()
{
    auto a {std::make_unique<arbres>(posElem())};
    return a;
}

void arbres::affiche(const interface &inter) const
{
    inter.afficheArbres(*this);
}

