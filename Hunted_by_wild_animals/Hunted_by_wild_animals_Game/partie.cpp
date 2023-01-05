#include "partie.h"
partie::partie(std::unique_ptr<interface> inter) : d_t{}, d_inter{std::move(inter)}
{

}

partie::partie(const terrain &t, std::unique_ptr<interface> inter) : d_t{t}, d_inter{std::move(inter)}
{

}

bool partie::positionValide(const position & pos)
{

    if(pos.getI() > d_t.hauteur() || pos.getJ() > d_t.largeur())
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
        auto obj = d_t.tabElements()[pos.getI()][pos.getJ()].get();
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
}


void partie::ajouteLion(const position& pos)
{
    if(positionValide(pos))
    {
        auto obj = d_t.tabElements()[pos.getI()][pos.getJ()].get();
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

}

void partie::ajouteTigre(const position& pos)
{
    if(positionValide(pos))
    {
        auto obj = d_t.tabElements()[pos.getI()][pos.getJ()].get();
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
}

void partie::lireFichier(const std::string& nomFichier)
{
         std::ifstream ifs;
         ifs.open(nomFichier);

         if(!ifs.is_open())
         {
            std::cout<<"ERROR: MAUVAIS FICHIER";
         }
         else
         {
             d_t.lireDepuisFichier(ifs);
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
                       auto elem = d_t.tabElements()[posJoueur.getI()][posJoueur.getJ()].get();


                       std::cout<<std::endl<<"Choisir une direction de deplacement"<<std::endl;

                       if(dynamic_cast<joueurNormal*>(elem))
                       {
                           std::cout<<"789"<<std::endl;
                           std::cout<<"4 6"<<std::endl;
                           std::cout<<"123"<<std::endl;
                           std::cin>>direction;

                               j = dynamic_cast<joueurNormal*>(d_t.tabElements()[posJoueur.getI()][posJoueur.getJ()].get());
                               j->deplaceJoueur(d_t,direction);

                               if(d_t.posJoueur().getI()==-1 && d_t.posJoueur().getJ()==-1)
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

                                   auto elem = d_t.tabElements()[posFauves.getI()][posFauves.getJ()].get();

                                   if(dynamic_cast<tigre*>(elem))
                                   {
                                      tigre* t = dynamic_cast<tigre*>(d_t.tabElements()[posFauves.getI()][posFauves.getJ()].get());
                                      t->deplace(d_t);
                                   }
                                   else if(dynamic_cast<lion*>(elem))
                                   {
                                      lion* l = dynamic_cast<lion*>(d_t.tabElements()[posFauves.getI()][posFauves.getJ()].get());
                                      l->deplace(d_t);
                                   }

                                   positionFauves = d_t.tabPositionFauves();

                                   if(positionFauves[j]==posFauves)
                                   {
                                       j++;
                                   }

                                   if(d_t.posJoueur().getI()==-1 && d_t.posJoueur().getJ()==-1)
                                   {
                                      joueurMort =  true;
                                   }
                                   else
                                   {
                                        affiche();
                                   }
                               }
                           }

                           resultatPartie(joueurMort);

           }

}

void partie::resultatPartie(bool t) const
{
           if(t == true)
           {
               std::cout<<"Vous avez perdu"<<std::endl;
           }
           else
           {
               std::cout<<"Vous avez gagne"<<std::endl;
           }
}
