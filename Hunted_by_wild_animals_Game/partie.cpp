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


/*

void partie::joue()
{
   bool joueurMort = false, fauvesMorts = false;
   int direction;

   affiche();
   int r=0;
   while(joueurMort == false &&  fauvesMorts == false)
   {
          position p1 = d_t.posJoueur();
          auto elem = d_t.tabElements()[p1.i()][p1.j()].get();
          std::cout<<std::endl<<"Choisir une direction de deplacement"<<std::endl;

       if(dynamic_cast<joueurNormal*>(elem))
       {
           std::cout<<"789"<<std::endl;
           std::cout<<"4 6"<<std::endl;
           std::cout<<"123"<<std::endl;
           std::cin>>direction;

           position p = d_t.posJoueur();

           auto joueurN{std::make_unique<joueurNormal>(p)};
           position dir = newPosJNormal(direction, std::move(joueurN));

           auto joueurNo{std::make_unique<joueurNormal>(p)};
           int situation = situationJNormal(dir, d_t,std::move(joueurNo));


           if(situation == 1)
           {
               std::cout<<"redepalcer";
           }
           else if(situation == 3)
           {
              d_t.supprimerElement(p);
              joueurMort=true;
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
              if(joueurMort == true)
              {
                break;
              }

                       std::vector<position> tabF = d_t.tabPosFauves();
                       p1 = d_t.posJoueur();
                       unsigned int s;


               if(tabF.size()>0)
               {
                           for(unsigned int i=0; i<tabF.size(); i++)
                           {
                                               affiche();
                                               bool tourFini = true;
                                               position p=tabF[i];
                                               elem = d_t.tabElements()[p.i()][p.j()].get();
                                               int direction;

                                               std::cout<<std::endl<<"Le fauve "<<i+1<<" se deplace..."<<std::endl;

                                               if(dynamic_cast<tigre*>(elem))
                                               {
                                                   deplaceTigre();
                                                         /*s=0;
                                                         auto ti{std::make_unique<tigre>(p)};
                                                         std::vector<int> tabDirection = directionDeplacementTigre(p1,std::move(ti));

                                                         do
                                                         {
                                                           direction = tabDirection[s];

                                                           auto t{std::make_unique<tigre>(p)};
                                                           position dir = newPosTigre(direction, std::move(t));

                                                           auto tt{std::make_unique<tigre>(p)};
                                                           int situation = situationTigre(dir, d_t,std::move(tt));

                                                                               if(situation == 1)
                                                                               {
                                                                                    tourFini = false;
                                                                               }
                                                                               else if(situation == 2)
                                                                               {
                                                                                     position t = d_t.posJoueur();
                                                                                     if(t.i()==dir.i() && t.j()==dir.j())
                                                                                        joueurMort=true;

                                                                                     d_t.supprimerElement(p);
                                                                                     d_t.supprimerElement(dir);
                                                                                     auto elem{std::make_unique<tigre>(dir)};
                                                                                     d_t.ajouterElement(std::move(elem),dir);
                                                                                     tourFini = true;

                                                                                     position asup{dir};

                                                                                     int k=0;
                                                                                     while(tabF[k].i() != asup.i() && tabF[k].j() != asup.j())
                                                                                     {
                                                                                         k++;
                                                                                     }

                                                                                     for(int l=k+1 ; l<tabF.size();l++)
                                                                                     {
                                                                                         std::swap(tabF[l],tabF[l+1]);
                                                                                     }
                                                                                     tabF.resize(tabF.size()-1);
                                                                               }
                                                                               else if(situation == 3)
                                                                               {
                                                                                     d_t.supprimerElement(p);
                                                                                     tourFini = true;
                                                                               }
                                                                               else if(situation == 0)
                                                                               {
                                                                                      auto elem{std::make_unique<tigre>(dir)};
                                                                                      d_t.ajouterElement(std::move(elem),dir);
                                                                                      d_t.supprimerElement(p);
                                                                                      tourFini = true;
                                                                               }
                                                                               s++;
                                                            }while(tourFini==false && s<tabDirection.size());
                                               }
                                               if(joueurMort == true )
                                                   break;
                                               std::cout<<"la"<<d_t.nombreFauves()<<std::endl;
                                               if(d_t.nombreFauves()==0)
                                               {
                                                   fauvesMorts=true;
                                                   break;
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




    affiche();
   }

   if(joueurMort)
    std::cout<<"Vous etes mort"<<std::endl;
   else
    std::cout<<"Vous avez gagne"<<std::endl;

}
*/

void partie::joue()
{
           int direction;
           affiche();
           position posJoueur = d_t.posJoueur();
           auto elem = d_t.tabElements()[posJoueur.i()][posJoueur.j()].get();


           std::cout<<std::endl<<"Choisir une direction de deplacement"<<std::endl;

           if(dynamic_cast<joueurNormal*>(elem))
           {
               std::cout<<"789"<<std::endl;
               std::cout<<"4 6"<<std::endl;
               std::cout<<"123"<<std::endl;
               std::cin>>direction;

               joueurNormal* j = dynamic_cast<joueurNormal*>(d_t.tabElements()[posJoueur.i()][posJoueur.j()].get());
               j->deplace(d_t,direction);
               affiche();
           }

           std::vector<position> positionFauves = d_t.tabPositionFauves();
           int j=0;

           do
           {
               positionFauves = d_t.tabPositionFauves();
               position posFauves = positionFauves[j];

               auto elem = d_t.tabElements()[posFauves.i()][posFauves.j()].get();

               if(dynamic_cast<tigre*>(elem))
               {
                  tigre* t = dynamic_cast<tigre*>(d_t.tabElements()[posFauves.i()][posFauves.j()].get());
                  t->deplace(d_t,direction);
               }
               else if(dynamic_cast<lion*>(elem))
               {
                  lion* l = dynamic_cast<lion*>(d_t.tabElements()[posFauves.i()][posFauves.j()].get());
                  l->deplace(d_t,direction);
               }


               affiche();

               positionFauves = d_t.tabPositionFauves();

               if(positionFauves[j]==posFauves)
               {
                   std::cout<<std::endl<<"j++"<<std::endl;;
                   j++;
               }
           }
           while(j<positionFauves.size());



}
