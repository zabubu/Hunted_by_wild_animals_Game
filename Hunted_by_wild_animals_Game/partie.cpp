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

void partie::joue()
{
           int direction;
           bool joueurMort=false;
           joueurNormal* j;

           affiche();
           while(joueurMort == false && d_t.nombreFauves()>0)
           {

                       position posJoueur = d_t.posJoueur();
                       auto elem = d_t.tabElements()[posJoueur.i()][posJoueur.j()].get();


                       std::cout<<std::endl<<"Choisir une direction de deplacement"<<std::endl;

                       if(dynamic_cast<joueurNormal*>(elem))
                       {
                           std::cout<<"789"<<std::endl;
                           std::cout<<"4 6"<<std::endl;
                           std::cout<<"123"<<std::endl;
                           std::cout<<"on a "<<joueurMort<<" "<<d_t.nombreFauves()<<std::endl;
                           std::cin>>direction;

                               j = dynamic_cast<joueurNormal*>(d_t.tabElements()[posJoueur.i()][posJoueur.j()].get());
                               j->deplace(d_t,direction);

                               if(d_t.posJoueur().i()==-1 && d_t.posJoueur().j()==-1)
                               {
                                  joueurMort =  true;
                               }
                               affiche();
                       }



                           if( joueurMort ==  false)
                           {
                                std::vector<position> positionFauves = d_t.tabPositionFauves();
                               int j=0;

                               while(j<positionFauves.size() && d_t.nombreFauves()>0)
                               {
                                   d_t.miseAjourTabPosFauves();
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

                                   positionFauves = d_t.tabPositionFauves();

                                   if(positionFauves[j]==posFauves)
                                   {
                                       j++;
                                   }

                                   if(d_t.posJoueur().i()==-1 && d_t.posJoueur().j()==-1)
                                   {
                                      joueurMort =  true;
                                   }
                                   else
                                   {
                                        affiche();
                                   }
                               }
                           }



           }


           if(joueurMort == true)
           {
               std::cout<<"Vous avez perdu"<<std::endl;
           }
           else
           {
               std::cout<<"Vous avez gagne"<<std::endl;
           }
}
