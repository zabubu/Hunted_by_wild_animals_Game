#include "partie.h"

partie::partie(std::unique_ptr<interface> inter) : d_t{}, d_inter{std::move(inter)}
{

}

partie::partie(const terrain &t, std::unique_ptr<interface> inter) : d_t{t}, d_inter{std::move(inter)}
{

}

bool partie::positionValide(const position & pos)
{

    if(pos.i() > d_t.hauteur() || pos.j() > d_t.largeur())
    {
       return false;
    }
    else
    {
        return true;
    }
}


void partie::ajoutePiege(const position& pos)
{
    if(positionValide(pos))
    {
        auto obj = d_t.tabElements()[pos.i()][pos.j()].get();
        if(obj!=nullptr)
        {
            if(!dynamic_cast<pieges*>(obj))
            {
                d_t.supprimerElement(pos);
                d_t.ajouterElement(std::make_unique<pieges>(pos), pos);
            }
        }
        else
        {
            d_t.ajouterElement(std::make_unique<pieges>(pos), pos);
        }
    }
    else
    {
        std::cerr << "ERROR: the position is not on the ground" << std::endl;
    }
}


void partie::ajouteLion(const position& pos)
{
    if(positionValide(pos))
    {
        auto obj = d_t.tabElements()[pos.i()][pos.j()].get();
        if(obj!=nullptr)
        {
            if(!dynamic_cast<lion*>(obj))
            {
                d_t.supprimerElement(pos);
                d_t.ajouterElement(std::make_unique<lion>(pos), pos);
            }
        }
        else
        {
                d_t.ajouterElement(std::make_unique<lion>(pos),pos);
        }
    }
    else
    {
        std::cerr << "ERROR: the position is not on the ground" << std::endl;
    }
}

void partie::ajouteTigre(const position& pos)
{
    if(positionValide(pos))
    {
        auto obj = d_t.tabElements()[pos.i()][pos.j()].get();
        if(obj!=nullptr)
        {
            if(!dynamic_cast<tigre*>(obj))
            {
                d_t.supprimerElement(pos);
                d_t.ajouterElement(std::make_unique<tigre>(pos), pos);
            }
        }
        else
        {
                d_t.ajouterElement(std::make_unique<tigre>(pos),pos);
        }
    }
    else
    {
        std::cerr << "ERROR: the position is not on the ground" << std::endl;
    }
}

void partie::lireFichier(const std::string& nomFichier)
{
    if(nomFichier == "")
    {
        std::cout<<"PAS BON";
    }

    else
    {
         std::ifstream ifs;
         ifs.open(nomFichier);

         if(!ifs.is_open())
         {
            std::cout<<"PAS BON";
         }
         else
         {
             d_t.lireDepuisFichier(ifs);
         }

    }
}

void partie::nouveauTerrain()
{
    d_t.creeTerrain();
}

void partie::affiche() const
{
    d_inter->afficheTerrain(d_t);
}

position partie::newPosTigre(int i, std::unique_ptr<tigre> elem) const
{
         return elem->avanceVers(i);
}
position partie::newPosLion(int i, std::unique_ptr<lion> elem) const
{
     return elem->avanceVers(i);
}
position partie::newPosJExpert(int i, std::unique_ptr<joueurExpert> elem) const
{
     return elem->avanceVers(i);
}
position partie::newPosJNormal(int i, std::unique_ptr<joueurNormal> elem) const
{
    return elem->avanceVers(i);
}

int partie::situationTigre(const position &p, terrain &t, std::unique_ptr<tigre> elem) const
{
     return elem->deplaceEn(p,t);
}

int partie::situationLion(const position &p, terrain &t, std::unique_ptr<lion> elem) const
{
     return elem->deplaceEn(p,t);
}

int partie::situationJExpert(const position &p, terrain &t, std::unique_ptr<joueurExpert> elem) const
{
   return elem->deplaceEn(p,t);
}

int partie::actionJNormal(const position &p, terrain &t, std::unique_ptr<joueurNormal> elem) const
{
    return elem->deplaceEn(p,t);
}

void partie::joue()
{
   bool joueurMort = false, fauvesMorts = false;
   int direction;
   int situation;
   position p1 = d_t.posJoueur();
   auto elem = d_t.tabElements()[p1.i()][p1.j()].get();


   do
   {
       affiche();
       std::cout<<std::endl<<"Choisir une direction de deplacement"<<std::endl;

       if(dynamic_cast<joueurNormal*>(elem))
       {
           std::cout<<"789"<<std::endl;
           std::cout<<"456"<<std::endl;
           std::cout<<"123"<<std::endl;
           std::cin>>direction;

           auto joueurN{std::make_unique<joueurNormal>(p1)};
           position dir = newPosJNormal(direction, std::move(joueurN));

           auto joueurNo{std::make_unique<joueurNormal>(p)};
           int action = actionJNormal(dir, d_t,std::move(joueurNo));


           if(situation == 1)
           {
               std::cout<<"redepalcer";
           }
           else if(situation == 3)
           {
              d_t.supprimerElement(p);
           }
           else if(situation == 0)
           {
              auto elem{std::make_unique<joueurNormal>(dir)};
              d_t.ajouterElement(std::move(elem),dir);
              d_t.supprimerElement(p);
           }


       }
       else
        {
            std::cout<<"expert";
        }


       std::vector<position> tabF = d_t.tabPosFauves();


       if(tabF.size()>0)
       {
                   for(int i=0; i<tabF.size(); i++)
                   {
                           position p=tabF[i];
                           elem = d_t.tabElements()[p.i()][p.j()].get();
                           int direction;

                           std::cout<<std::endl<<"Deplacement du fauve "<<i<<std::endl;
                           std::cin>>direction;


                           if(dynamic_cast<tigre*>(elem))
                           {
                               auto t{std::make_unique<tigre>(p)};
                               position dir = newPosTigre(direction, std::move(t));

                               auto tt{std::make_unique<tigre>(p)};
                               int situation = situationTigre(dir, d_t,std::move(tt));

                                                           if(situation == 1)
                                                           {
                                                              std::cout<<"redepalcer";
                                                           }
                                                           else if(situation == 2)
                                                           {
                                                             d_t.supprimerElement(dir);
                                                             auto elem{std::make_unique<tigre>(dir)};
                                                             d_t.ajouterElement(std::move(elem),dir);
                                                           }
                                                            else if(situation == 3)
                                                           {
                                                             d_t.supprimerElement(p);
                                                           }
                                                           else if(situation == 0)
                                                           {
                                                              auto elem{std::make_unique<tigre>(dir)};
                                                              d_t.ajouterElement(std::move(elem),dir);
                                                              d_t.supprimerElement(p);
                                                           }
                           }
                           else if(dynamic_cast<lion*>(elem))
                           {
                               auto l{std::make_unique<lion>(p)};
                               position dir = newPosLion(direction, std::move(l));

                               auto ll{std::make_unique<lion>(p)};
                               int situation = situationLion(dir, d_t,std::move(ll));

                                                              if(situation == 1)
                                                               {
                                                                  std::cout<<"redepalcer";
                                                               }
                                                               else if(situation == 2)
                                                               {
                                                                 d_t.supprimerElement(dir);
                                                                 auto elem{std::make_unique<lion>(dir)};
                                                                 d_t.ajouterElement(std::move(elem),dir);
                                                               }
                                                                else if(situation == 3)
                                                               {
                                                                 d_t.supprimerElement(p);
                                                               }
                                                               else if(situation == 0)
                                                               {
                                                                  auto elem{std::make_unique<lion>(dir)};
                                                                  d_t.ajouterElement(std::move(elem),dir);
                                                                  d_t.supprimerElement(p);
                                                               }
                           }
                      }
       }
       else
       {
           fauvesMorts=true;
       }




     position ps = d_t.posJoueur();
     if(ps.i()==1000 && ps.j()==1000)
     {
         joueurMort = true;
     }





   }while(joueurMort==false && fauvesMorts==false);
   affiche();
}


/*
void game::run()
{
    int choice, max_choices = 3;
    position p;

    do
    {
        cout<<"========================== MENU =========================="<<endl;
        cout<<"1 - Creer un terrain"     <<endl;
        cout<<"1 - Ajouter un miroir"  <<endl;
        cout<<"2 - Enlever un miroir"  <<endl;
        cout<<"3 - Afficher le terrain"<<endl;
        cout << "> ";
        cin>>choice;

        //There are 4 possibilities (can evolve)
        switch(choice)
        {
            //Shoot the laser
            case 0:
                {
                    start();
                    break;
                }
            //Adding mirrors in game
            case 1:
                {
                    //If adding mirrors is authorized
                    if(d_ground.getNbOfMirrors() < d_ground.getNbMirrorMax())
                    {
                        //Asking the sense of the installed mirror
                        sens s = askSens();
                        //Asking the position of the installed mirror
                        position = askPosition();
                        addMirror(position, s);
                    }
                    else cout<<"Le nombre maximum de miroirs a ete atteint ! "<<endl;
                    break;
                }
            //Removing mirror in game
            case 2 :
                {
                    //Asking the position of the removed mirror
                    position = askPosition();
                    removeMirror(position);
                    break;
                }
            //Print the ground of the game
            case 3 :
                {
                    d_viewer->printGround(d_ground);
                    break;
                }
            //The choice contains an invalid integer
            default:
                {
                    cerr << "Erreur, entrez un nombre entre 0 et " << max_choices << endl;
                    break;
                }
        }
        cout << endl;
    }
    while(choice != 0);
}
*/
