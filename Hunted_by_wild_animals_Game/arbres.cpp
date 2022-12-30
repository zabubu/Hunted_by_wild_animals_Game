#include "arbres.h"
#include "interface.h"

arbres::arbres(const position & pos) : elements{pos}
{

}

std::unique_ptr<elements> arbres::clone()
{

}

void arbres::affiche(const interface &inter) const
{
    inter.afficheArbres(*this);
}

