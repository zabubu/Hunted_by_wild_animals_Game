#ifndef JOUEUR_H
#define JOUEUR_H

#include "position.h"
#include "elements.h"

class joueur : public elements
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
        *
        * @return position joueur
        */
	position position();
    /**
        * @brief fonction of joueur
        *
        * @return life joueur
        */
    bool isAlive() const;
        /**
        * @brief fonction of joueur
        *
        * kill joueur
        */
    void KillJoueur();
	private :
    bool d_alive;
};


#endif // JOUEUR_H
