#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>

#include "terrain.h"
#include "interface.h"

class menu
{
public:

    menu();
    void menuPrincipale();

    std::unique_ptr<interface> creationInterface() const;
    void choixInterface();

    void choixTerrain(std::string &nomF);
    void creeTerrain();

    void printGround(const std::string& nomFichier);

    private :
   int d_numInterface;
   int d_numTerrain;
};





#endif // MENU_H

