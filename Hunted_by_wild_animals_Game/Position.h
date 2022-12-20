#ifndef POSITION_H
#define POSITION_H
#include<cmath>

class Position
{
    public:
    /**
            * @brief Constructor of joueur
            *
            * @param x : int
            * @param y : int
            * @return Create a position with x and y
            */
        Position(int x=0,int y=0);
    /**
            * @brief fonction of position
            *
            * @return  x
            */
        double renvoyerX()const;
    /**
            * @brief fonction of position
            *
            * @return  y
            */
        double renvoyerY()const;
    /**
            * @brief fonction of position
            *
            *   change x
            */
        void modifierX(double x);
    /**
            * @brief fonction of position
            *
            *   change x
            */
        void modifierY(double y);
    /**
            * @brief fonction of position
            *
            *   @param p : position
            *
            *   @return  distance
            */
        double renvoyerDistance(const Position& p)const;
    /**
            * @brief operator of position
            *
            *   @param p : position
            *
            */
        bool operator==(const position& p) const;
    /**
            * @brief operator of position
            *
            *   @param p : position
            *
            */
        bool operator!=(const position& p) const;
    private:
    //The position of the joueur x:columns / y:rows
        double d_x;
        double d_y;
};

#endif // POSITION_H
