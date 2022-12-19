#include "joueur.h"

//---------- Constructors----------------------------
joueur::joueur():d_pos{0,0}{}

joueur::joueur(const position &p):d_pos{p.positionX,p.positionY}{}

joueur::joueur(int x,int y):d_pos{x,y}{}

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