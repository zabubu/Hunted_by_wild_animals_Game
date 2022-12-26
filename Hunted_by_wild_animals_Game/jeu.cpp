#include "jeu.h"

jeu::jeu()
{

}

jeu::~jeu()
{}

void jeu::AfficheMenu()
{
    int numero;
    std::cout << "le jeu est en cours d'execution..."<<std::endl;
    std::cout << "---------------------------------------------"<<std::endl;
    std::cout << "-----------     Menu Principale    ----------"<<std::endl;
    std::cout << "-------- Press 1 to create a new map --------"<<std::endl;
    std::cout << "-------- Press 2 to get a map save   --------"<<std::endl;
    std::cout << "-------- Press 3 to show the map     --------"<<std::endl;
    std::cout << "-------- Press 4 to Exit             --------"<<std::endl;
    std::cin>>numero;

    if(numero==1) AfficheDifficulte();
    else if(numero==2)
    {}
    else if(numero==3)
    {}
     else if(numero==4)
    {}
    else
    {}
}


void jeu::AfficheDifficulte()
{
    int lvl;
    std::cout <<std::endl<< "------------------------------------------------"<<std::endl;
    std::cout << "-------------     Map creation     -------------"<<std::endl;
    std::cout << "-------- Press 1 to create a simple map --------"<<std::endl;
    std::cout << "-------- Press 2 to create a hard map   --------"<<std::endl;
    std::cout << "-------- Press 3 to create a expert map --------"<<std::endl;
    std::cout << "-------- Press 4 to Exit                --------"<<std::endl;
    std::cin>>lvl;
    if(lvl==1)
    {


    }
    else if(lvl==2)
    {

    }
    else if(lvl==3)
    {

    }
    else if(lvl==4) {}
}
void jeu::AfficheConsigne()
{
    std::cout<<std::endl;
    std::cout<<"-le P vous represente"<<std::endl<<"-les O sont les pieges "<<std::endl<<"-les F sont les fauves dont vous devez echapper"<<std::endl;
    std::cout<<"vous pouvez vous deplacer en entrant des numero comme ceci :"<<std::endl<<std::endl;
    std::cout<<"       123"<<std::endl;
    std::cout<<"       8P4"<<std::endl;
    std::cout<<"       765"<<std::endl<<std::endl;
    std::cout<<"appuyer sur 0 pour avoir le Menu "<<std::endl;
}
bool jeu::fin()
{

}
