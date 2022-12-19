#ifndef OBSTACLE_H
#define OBSTACLE_H


class obstacle
{
    public:
        obstacle (const Position &pos, const string &type);
        void modifierPosition (int x, int y);

    private:
        Position d_position;
        string d_type;
};

#endif // OBSTACLE_H
