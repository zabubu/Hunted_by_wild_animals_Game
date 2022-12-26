#ifndef JEU_H
#define JEU_H
#include <iostream>

class jeu
{
    public:
        jeu();
        virtual ~jeu();
        void AfficheMenu();
        void AfficheDifficulte();
        void AfficheConsigne();
        bool fin();

    private:
};

#endif // JEU_H
