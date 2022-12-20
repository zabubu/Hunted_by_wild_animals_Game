#ifndef FAUVES_H
#define FAUVES_H
#include "position.h"
#include "elements.h"
#include "joueur.h"

class fauves : public elements{
    public:
    /**
     * @brief Empty constructor of the class fauves
     * @param Name of the type of the fauves
     * @return Creation of an element of the class fauves
    */
    fauves(const std::string& type);
    /**
     * @brief position constructor of the class fauves
     * @param p : position
     * @return Creation of an element of the class fauves with the coordinates of p
    */
    fauves(const position &p,const std::string& type);
    /**
     * @brief Coordinates constructor of the class fauves
     * @param x : int
     * @param y : int
     * @return Creation of an element of the class fauves with the coordinates of (x,y)
    */
    fauves(int x, int y,const std::string& type);
    /**
     * @brief Change the position of the "fauves" if it's possible
     * @param j : Player where the "fauves" have to go
    */
    void deplaceVers(const joueur &j);
    /**
     * @brief Permission to move the "fauves"
     * @param p : position where the fauves need to go
     * @return True if the position is empty, false if a tree is on the position
    */
    bool deplacementAutorise(const position& p)const;
};

#endif
