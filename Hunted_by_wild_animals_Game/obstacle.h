#ifndef OBSTACLE_H
#define OBSTACLE_H
#include <iostream>
#include "position.h"

class obstacle
{
    public:
        obstacle(const position &pos, const std::string &type);
        void modifierPosition (int x, int y);

    private:
        position d_position;
        std::string d_type;
};

#endif // OBSTACLE_H
