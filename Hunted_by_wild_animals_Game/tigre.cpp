#include "tigre.h"


void tigre::deplaceVers(const joueur &j)// lion
{
	int positionJoueurX = j.position().x();
	int positionJoueurY = j.position().y();
	int positionX = position().x();
	int positionY = position().y();

	if(abs(positionJoueurX - positionX)>abs(positionJoueurY-positionY) && positionX>0)
	{
		DeplaceEn(positionX-1,positionY);
	}
	else(if positionY>0)
	{
		DeplaceEn(positionX,positionY-1);
	}
}
/*
vector<int> tigre::PositionsPossibles()
{
	vector<int> t(8,true);
	switch(position())
	{
		case(position().x()=0):
		t[1,2,3]=false;
		case(position().y()=0):
		t[1,4,7]=false;
	}
    return t;
}
*/
