#include "joueur.h"

//---------- Constructors----------------------------
joueur::joueur():d_pos{0,0},d_alive{true}{}

joueur::joueur(const position &p):d_pos{p.positionX,p.positionY},d_alive{true}{}

joueur::joueur(int x,int y):d_pos{x,y},d_alive{true}{}

//---------- End of constructors---------------------

void joueur::deplaceVers(int x,int y)
{
	int positionX = x;
	int positionY = y;
}

position joueur::position()
{
	return d_pos;
}

bool joueur::isAlive() const
{
	return d_alive;
}

void KillJoueur()
{
	d_alive==false;
}