#ifndef POSITION_H
#define POSITION_H

#include <fstream>

class position
{
public:
    position();
    position(int i, int j);
    position (const position &p);
    int i() const;
    int j() const;
    void modifieI(int i);
    void modifieJ(int j);
    void affiche(std::ostream &ost) const;
      position& operator=(const position& p);
      bool operator!=(const position& p) const;
      bool operator==(const position& p) const;

private:
    int d_i, d_j;
};



#endif // POSITION_H
