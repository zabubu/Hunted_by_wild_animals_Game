#ifndef JOUEUR_H
#define JOUEUR_H

#include "position.h"

class joueur : public element
{
	public :
	/**
        * @brief Constructor of joueur
        *
        *
        * @return Create a joueur with position
        */
	joueur();
	/**
        * @brief Constructor of joueur
        *
        * @param position : position (const point)
        *
        * @return Create a joueur with position
        */
	joueur(const position &p);
	/**
        * @brief Constructor of joueur
        *
        * @param x : int 
        * @param y : int
        *  
        * @return Create a joueur with position
        */
	joueur(int x,int y);
	/**
        * @brief fonction of joueur
        *
        * @param x : int 
        * @param y : int
        */
	void deplaceVers(int x,int y) override;
	/**
        * @brief fonction of joueur
        *
        * @param x : int 
        * @param y : int
        * 
        * @return position joueur 
        */
	position position();
	private :
	//The position of the joueur.
	position d_pos;
}


#endif // JOUEUR_H