#ifndef POSITION_H
#define POSITION_H

#include <fstream>

class position
{
public:
    position();
    position(int i, int j);
    position (const position &p);
    int getI() const;
    int getJ() const;
    void setI(int i);
    void setJ(int j);
    void affiche(std::ostream &ost) const;
    position& operator=(const position& p);
    bool operator!=(const position& p) const;
    bool operator==(const position& p) const;

private:
    int d_i, d_j;
};



#endif // POSITION_H
