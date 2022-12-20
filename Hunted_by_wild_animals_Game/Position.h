#ifndef POSITION_H
#define POSITION_H
#include<cmath>

class position
{
    public:
    /**
            * @brief Constructor of joueur
            *
            * @param x : int
            * @param y : int
            * @return Create a position with x and y
            */
        position(int x=0,int y=0);
    /**
            * @brief fonction of position
            *
            * @return  x
            */
        double x()const;
    /**
            * @brief fonction of position
            *
            * @return  y
            */
        double y()const;
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
        double renvoyerDistance(const position& p)const;
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
    /**
            * @brief operator of position
            *
            *   @param p : position
            *
            */
        position& operator=(const position& p);
    private:
    //The position of the joueur x:columns / y:rows
        double d_x;
        double d_y;
};

#endif // POSITION_H
