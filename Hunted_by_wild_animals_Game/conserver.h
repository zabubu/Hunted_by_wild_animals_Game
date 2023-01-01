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
                                               }*/
                                               else if(dynamic_cast<lion*>(elem))
                                               {
                                                        s=0;
                                                        auto ti{std::make_unique<lion>(p)};
                                                        std::vector<int> tabDirection = directionDeplacementLion(p1,std::move(ti));


                                                         do
                                                         {
                                                           direction = tabDirection[s];
                                                           auto l{std::make_unique<lion>(p)};
                                                           position dir = newPosLion(direction, std::move(l));

                                                           auto ll{std::make_unique<lion>(p)};
                                                           int situation = situationLion(dir, d_t,std::move(ll));

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
                                                                                             auto elem{std::make_unique<lion>(dir)};
                                                                                             d_t.ajouterElement(std::move(elem),dir);
                                                                                             tourFini = true;


                                                                                                 position asup{dir};
                                                                                                 int k=0;
                                                                                                 while(tabF[k].i() != asup.i() && tabF[k].j() != asup.j())
                                                                                                 {
                                                                                                     k++;
                                                                                                 }
                                                                                                 for(int l=k ; l<tabF.size();l++)
                                                                                                 {
                                                                                                     std::swap(tabF[l],tabF[l+1]);
                                                                                                 }
                                                                                                 tabF.resize(tabF.size()-1);
                                                                                           }
                                                                                            else if(situation == 3)
                                                                                           {
                                                                                             d_t.supprimerElement(p);
                                                                                             tourFini = true;
                                                                                              if(d_t.nombreFauves()==0)
                                                                                               {
                                                                                                   fauvesMorts==true;
                                                                                                   break;
                                                                                               }

                                                                                           }
                                                                                           else if(situation == 0)
                                                                                           {
                                                                                              auto elem{std::make_unique<lion>(dir)};
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
