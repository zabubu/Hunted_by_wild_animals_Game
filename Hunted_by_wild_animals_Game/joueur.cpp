#include "joueur.h"

//---------- Constructors----------------------------
joueur::joueur():elements{0,0,"player"},d_alive{true}{}

joueur::joueur(int x,int y):elements{x,y,"player"},d_alive{true}{}

//---------- End of constructors---------------------

position joueur::position()
{
	return position();
}

bool joueur::isAlive() const
{
	return d_alive;
}

void joueur::KillJoueur()
{
	d_alive=false;
}
