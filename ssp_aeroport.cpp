#include "headers.h"

using namespace std;

Aeroport::Aeroport(int identifiant,std::string name,int piste,int place,int sol,int access,int duree,int anticol,int decollage,int bouc,int x,int y):
    m_identifiant{identifiant},m_nom{name},m_x(x),m_y(y),m_nbPistes{piste},m_nbPlaces{place},m_attSol{sol},m_acces{access},m_duree{duree},m_anticollision{anticol},m_tempsDecollage{decollage},m_boucle{bouc}{}

std::vector<int>Aeroport::getDistance()const{return m_distance;}
int Aeroport::getDistancetot()const{return m_distancetotale;}
void Aeroport::setDistance(int distance){m_distance.push_back(distance);}
void Aeroport::setDistancetot(int distance){m_distancetotale=distance;}
 Aeroport* Aeroport:: getPredecesseur()const{return m_predecesseur;}
 void Aeroport::setPredecesseur(Aeroport* predecesseur){m_predecesseur=predecesseur;}


std::string Aeroport::getNom()const{return m_nom;}
int Aeroport::getPistes()const{return m_nbPistes;}
int Aeroport::getPlaces()const{return m_nbPlaces;}
int Aeroport::getSol()const{return m_attSol;}
int Aeroport::getAcces()const{return m_acces;}
int Aeroport::getDuree()const{return m_duree;}
int Aeroport::getCollision()const{return m_anticollision;}
int Aeroport::getBoucle()const{return m_boucle;}
int Aeroport::getDecollage()const{return m_tempsDecollage;}
int Aeroport::getX(){return m_x;}
int Aeroport::getY(){return m_y;}
int Aeroport::getIdentifiant(){return m_identifiant;}
int Aeroport::getMarque(){return m_marque;}
std::vector<Aeroport*>& Aeroport::getVoisin(){return m_aeroportsVoisin;}
std::vector<Avion*>&Aeroport::getAvionsPiste(){return m_avionsPiste;}
std::vector<Avion*>&Aeroport::getAvionsSol(){return m_avionsSol;}
std::vector<Avion*>&Aeroport::getAvionsAttente(){return m_avionsAttente;}

void Aeroport::setMarque(int marque){m_marque=marque;}
void Aeroport::setNom(std::string Name){m_nom=Name;}
void Aeroport::setPistes(int nombrPistes){m_nbPistes=nombrPistes;}
void Aeroport::setPlaces(int nombrPlaces){m_nbPlaces=nombrPlaces;}
void Aeroport::setSol(int atterisol){m_attSol=atterisol;}
void Aeroport::setAcces(int acceder){m_acces=acceder;}
void Aeroport::setDuree(int timer){m_duree=timer;}
void Aeroport::setCollision(int coli){m_anticollision=coli;}
void Aeroport::setBoucle(int bou){m_boucle=bou;}
void Aeroport::ajouterVoisin(Aeroport*voisin){m_aeroportsVoisin.push_back(voisin);}
void Aeroport::setAjouterAvionsPiste(Avion*avion)
{
    if(m_nbPistes>m_avionsPiste.size())
        m_avionsPiste.push_back(avion);
    else
        std::cout<<"Piste de : "<<m_nom<<"pleine";
}
void Aeroport::setAjouterAvionsSol(Avion*avion)
{
    if(m_nbPlaces>m_avionsSol.size())
        m_avionsSol.push_back(avion);
    else
        std::cout<<"L aeroport de : "<<m_nom<<"est complet";
}
void Aeroport::setAjouterAvionsAttente(Avion*avion){m_avionsAttente.push_back(avion);}
void Aeroport::setSupprimerAvionsPiste(int identifiant)
{
    int i=0;
    while(m_avionsPiste[i]->getIdentifiant()!=identifiant)
    {
        i++;
    }
    m_avionsPiste.erase(m_avionsPiste.begin()+i);
}
void Aeroport::setSupprimerAvionsSol(int identifiant)
{
    int i=0;
    while(m_avionsSol[i]->getIdentifiant()!=identifiant)
    {
        i++;
    }
    m_avionsSol.erase(m_avionsSol.begin()+i);
}
void Aeroport::setSupprimerAvionsAttente(int identifiant)
{
    int i=0;
    while(m_avionsAttente[i]->getIdentifiant()!=identifiant)
    {
        i++;
    }
    m_avionsAttente.erase(m_avionsAttente.begin()+i);
}
void Aeroport::afficher()const
{
    std::cout<<" Aeroport: "<<m_nom<<std::endl;
    std::cout<<" Identifiant: "<<m_identifiant<<std::endl;
    std::cout<<" Coordonnees: "<<m_x<<" "<<m_y<<std::endl;
    std::cout<<" Nombre de pistes: "<<m_nbPistes<<std::endl;
    std::cout<<" Nombre de piste occupe:"<<m_avionsPiste.size()<<std::endl;
    std::cout<<" Nombre places au sol: "<<m_nbPlaces<<std::endl;
    std::cout<<" Nombre avions au sol:"<<m_avionsSol.size()<<std::endl;
    std::cout<<" Temps d'attente au sol: "<<m_attSol<<std::endl;
    std::cout<<" Temps d acces aux pistes: "<<m_acces<<std::endl;
    std::cout<<" Duree de la boucle : "<<m_duree<<std::endl;
    std::cout<<" Nombre d avion en boucle:"<<m_avionsAttente.size()<<std::endl;
    std::cout<<" Temps anti-collision: "<<m_anticollision<<std::endl;
    std::cout<<" Duree de la boucle: "<<m_boucle<<std::endl;
    std::cout<<" Temps decollage/atterissage: "<<m_tempsDecollage<<std::endl;

    std::cout<<" Aeroport adjacent : ";
    for(auto voisin:m_aeroportsVoisin)
    {
        std::cout<<voisin->getNom()<<", ";
    }
    std::cout<<std::endl;

    std::cout<<" Avion en attente au sol : ";
    std::cout<<std::endl;
    for(auto avion:m_avionsSol)
    {
        avion->afficher();
    }
    std::cout<<std::endl;
    std::cout<<" Avion en attente sur piste : ";
    std::cout<<std::endl;
    for(auto avion:m_avionsPiste)
    {
        avion->afficher();
    }
    std::cout<<std::endl;

    std::cout<<" Avion en attente en boucle : ";
    std::cout<<std::endl;
    for(auto avion:m_avionsAttente)
    {
        avion->afficher();
    }
    std::cout<<std::endl;
    std::cout<<std::endl;
}
bool Aeroport::pisteDisponible()
{
    if(m_nbPistes>m_avionsPiste.size())
        return true;
    else return false;
}
bool Aeroport::placeDisponible()
{
    if(m_nbPlaces>m_avionsSol.size())
        return true;
    else return false;
}
Arrete::Arrete(int ini, int fin, int ponderation):
    m_Aeroport1{ini},m_Aeroport2{fin},m_ponderation{ponderation}
{
    int nombre;
    int x,y;
    std::string nomFichier=to_string(ini)+"_"+to_string(fin)+".txt";
    /***************************** Ouverture du fichier ******************************/
    std::ifstream ifs{nomFichier};
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier );
    /*******************************************************************************/
    /***************************** Lecture de le nombre  ********************/
    ifs >> nombre;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture nombre");
    /*******************************************************************************/
    for(int i=0;i<nombre;i++)
    {
        ifs>>x>>y;
        if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture parcours"+ nomFichier);
        m_x.push_back(x);
        m_y.push_back(y);
    }
}

///getters
int Arrete::getAeroport1()const{return m_Aeroport1;}
int Arrete::getAeroport2()const{return m_Aeroport2;}
int Arrete::getPonderation()const{return m_ponderation;}
std::vector<Avion*>&Arrete::getAvionVol(){return m_avionVol;}
std::vector<int>&Arrete::getX(){return m_x;}
std::vector<int>&Arrete::getY(){return m_y;}
///setters
void Arrete::setPonderation(int pond){m_ponderation=pond;}
void Arrete::setAjouterAvionVol(Avion*avion){m_avionVol.push_back(avion);}
void Arrete::setSupprimerAvionVol(int identifiant)
{
    int i=0;
    while(m_avionVol[i]->getIdentifiant()!=identifiant)
    {
        i++;
    }
    m_avionVol.erase(m_avionVol.begin()+i);
}

void Arrete::affichage()
{
    std::cout<<"Aeroport initial: "<<m_Aeroport1<<" aeroport final: "<<m_Aeroport2<<" distance: "<<m_ponderation<<std::endl;
}

Graphe::Graphe(std::string nomFichier)
{
    int ordre,taille;
    std::string nomAero;
    int PISTE,PLACE,SOL,ACC,DUR,COL,BOU,decol,identifiant,x,y;
    int ponde;
    int id1,id2;

    std::ifstream ifs{nomFichier};

    if(!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier );

    ifs >> ordre;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture ordre");

        for(int i=0;i<ordre;i++)
        {
           ifs>>identifiant>>nomAero>>PISTE>>PLACE>>SOL>>ACC>>DUR>>COL>>decol>>BOU>>x>>y;
            if ( ifs.fail() )
                throw std::runtime_error("Probleme lecture sommet");

            m_liste_aeroport.push_back(new Aeroport{identifiant,nomAero,PISTE,PLACE,SOL,ACC,DUR,COL,decol,BOU,x,y});
        }

        ifs>>taille;
          if ( ifs.fail() )
            throw std::runtime_error("Probleme lecture taille du graphe");

        for(int i=0;i<taille;i++)
        {
            ifs>>id1>>id2>>ponde;
            if ( ifs.fail() )
                throw std::runtime_error("Probleme lecture arc");
            m_liste_aeroport[id1]->ajouterVoisin(m_liste_aeroport[id2]);
            m_liste_aeroport[id2]->ajouterVoisin(m_liste_aeroport[id1]);
            m_liste_aeroport[id2]->setDistance(ponde);
            m_liste_aeroport[id1]->setDistance(ponde);
            m_arrete.push_back(new Arrete{id1,id2,ponde});
        }
        ChargementAvions();
        int random;
        for(auto avion:m_listeAvions)
        {
            do
            {
                random=rand()%(m_liste_aeroport.size());
            }while(m_liste_aeroport[random]->placeDisponible()==false);
            avion->setX(m_liste_aeroport[random]->getX());
            avion->setY(m_liste_aeroport[random]->getY());
            m_liste_aeroport[random]->setAjouterAvionsSol(avion);
        }

}

Graphe::~Graphe()
{
        for(auto s: m_liste_aeroport)
            delete s;
    }
std::vector<Avion*>&Graphe::getListeAvions(){return m_listeAvions;}
std::vector<Aeroport*>&Graphe::getListeAeroport(){return m_liste_aeroport;}
std::vector<Avion*>&Graphe::getCrash(){return m_crash;}
void Graphe::setCrash(Avion*avion)
{
    m_crash.push_back(avion);
    avion->setAvion();
}
void Graphe::afficher()const
{
    for(auto j : m_liste_aeroport)
        j->afficher();

    std::cout<<std::endl;
}
void Graphe::ChargementAvions()
{
    int nombre;
    std::string nomFichier="Avion.txt";

    /***************************** Ouverture du fichier ******************************/
    std::ifstream ifs{nomFichier};
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier );
    /*******************************************************************************/

    /***************************** Lecture de le nombre d'avions ********************/
    ifs >> nombre;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture nombre");
    /*******************************************************************************/

    /******************** Ajout des sucesseurs et de la distance avec le sommet *******************/
    int reservoir,consommation,identifiant;
    std::string type;
    for (int i=0;i<nombre;++i){
        ifs>>type>>identifiant>>consommation>>reservoir;
        if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture arc");
        m_listeAvions.push_back(new Avion{type,identifiant,reservoir});
    }
    /*******************************************************************************/
}
void Graphe::gestionAeroport()
{
    for(auto aeroport:m_liste_aeroport)
    {
        /** Gestion des avions sur la piste **/
        for(auto avion:aeroport->getAvionsPiste())
        {   /** Avion en train de décoller/atterir**/
            if(avion->getUT()==(aeroport->getDecollage()+aeroport->getAcces()))
            {   /** Avion devant décoller **/
                if(avion->getReservoir()==avion->getCarburant())
                {
                    avion->setSupprimerTrajet();
                    for(auto arrete:m_arrete)
                    {
                        if((arrete->getAeroport1()==aeroport->getIdentifiant()&&arrete->getAeroport2()==avion->getTrajet().back())||(arrete->getAeroport2()==aeroport->getIdentifiant()&&arrete->getAeroport1()==avion->getTrajet().back()))
                        {
                            arrete->setAjouterAvionVol(avion);
                        }
                    }
                    std::cout<<"LE vol : "<<avion->getIdentifiant();
                    std::cout<<" Decolle de "<<aeroport->getNom();
                    std::cout<<" pour "<<m_liste_aeroport[avion->getTrajet().back()]->getNom();
                    std::cout<<std::endl;
                    avion->setUT(0);
                    avion->setVitesse(1000);
                    aeroport->setSupprimerAvionsPiste(avion->getIdentifiant());
                } /** Avion devant atterir **/
                else if(aeroport->placeDisponible()==true)
                {
                    std::cout<<"Le vol : "<<avion->getIdentifiant();
                    std::cout<<" a pu atterrir a : " <<aeroport->getNom()<<std::endl;
                    std::cout<<std::endl;
                    avion->setUT(0);
                    avion->setVitesse(0);
                    aeroport->setAjouterAvionsSol(avion);
                    aeroport->setSupprimerAvionsPiste(avion->getIdentifiant());
                }
            }/** Avion en cours d'acces au piste **/
            else
            {
                std::cout<<"Le vol : "<<avion->getIdentifiant()<<" est sur la piste de : " <<aeroport->getNom()<<std::endl;
                avion->setUT(avion->getUT()+1);
            }
        }
        /** Gestion des avions en attente **/
        for(auto avion:aeroport->getAvionsAttente())
        {   /** Avion ayant plus de carburant **/
            if(avion->getCarburant()<=0)
            {
                aeroport->setSupprimerAvionsAttente(avion->getIdentifiant());
                setCrash(avion);
                std::cout<<"Le vol "<<avion->getIdentifiant();
                std::cout<< " s est crashe"<<std::endl;
            }/** Avion ayant encore du carburant **/
            else
            {   /** Avion ayant finis la boucle d'avion **/
                if(avion->getUT()==aeroport->getBoucle())
                {   /** Place disponible pour atterir **/
                    if(aeroport->pisteDisponible()==true)
                    {   /** Place disponible dans l'aeroport **/
                        if(aeroport->placeDisponible()==true)
                        {
                            avion->setUT(0);
                            aeroport->setAjouterAvionsPiste(avion);
                            aeroport->setSupprimerAvionsAttente(avion->getIdentifiant());
                            std::cout<<"Le vol : "<<avion->getIdentifiant();
                            std::cout<<" va pouvoir atterrir a : " <<aeroport->getNom()<<std::endl;
                        }   /** Pas de place disponible dans l'aeroport **/
                        else
                        {
                            avion->setUT(0);
                            std::cout<<"Il n y a pas de place a "<<aeroport->getNom();
                            std::cout<<" pour le vol "<<avion->getIdentifiant()<<std::endl;
                        }
                    }   /** Pas de piste disponible dans l'aeroport **/
                    else
                    {
                        avion->setUT(0);
                        std::cout<<"Il n y a pas de piste a "<<aeroport->getNom();
                        std::cout<<" pour le vol "<<avion->getIdentifiant()<<std::endl;
                    }
                }   /** Avion en cours de boucle **/
                else
                {
                    avion->setUT(avion->getUT()+1);
                    avion->setCarburant(avion->getCarburant()-avion->getConsommation()*0.8);
                    std::cout<<"Le vol "<<avion->getIdentifiant();
                    std::cout<<" est en attente au dessus de "<<aeroport->getNom()<<std::endl;
                }
            }
        }
        /** Gestion des avions au sol **/
        for(auto avion:aeroport->getAvionsSol())
        {   /** Avion ayant finis l'attente dans l'aeroport **/
            if(avion->getUT()==aeroport->getSol())
            {
                if(aeroport->pisteDisponible()==true)/** Piste disponible **/
                {
                    avion->setUT(0);
                    avion->setCarburant(avion->getReservoir());
                    aeroport->setAjouterAvionsPiste(avion);
                    aeroport->setSupprimerAvionsSol(avion->getIdentifiant());
                    std::cout<<"Le vol : "<<avion->getIdentifiant();
                    std::cout<<" va pouvoir decoller de : " <<aeroport->getNom()<<std::endl;
                }
                else /** Pas de piste disponible **/
                {
                    std::cout<<"Le vol : "<<avion->getIdentifiant();
                    std::cout<<" attend une piste pour pouvoir decoller de : " <<aeroport->getNom()<<std::endl;
                }

            }   /** Avion venant d'arriver **/
            else if(avion->getUT()==0)
            {
                if(!avion->getTrajet().empty())
                {   /** Avion arriver a destination **/
                    if(avion->getTrajet().front()==aeroport->getIdentifiant())
                    {
                        std::cout<<"L avion : "<<avion->getIdentifiant();
                        std::cout<<" est arrive a "<<aeroport->getNom();
                        std::cout<<" sa destination"<<std::endl;
                        avion->setSupprimerTrajet();
                        Dijkstra(aeroport,avion,true);
                    }/** Avion en escale **/
                    else
                    {
                        std::cout<<"L avion : "<<avion->getIdentifiant();
                        std::cout<<" fait escale "<<aeroport->getNom();
                        std::cout<<std::endl;
                    }
                }   /** Avion ayant fini son trajet **/
                else
                    Dijkstra(aeroport,avion,true);

                avion->setUT(avion->getUT()+1);
            }   /** Avion en train d'attendre dans l'aeroport **/
            else
            {
                avion->setUT(avion->getUT()+1);
                std::cout<<"Le vol : "<<avion->getIdentifiant();
                std::cout<<" est en attente a : " <<aeroport->getNom()<<std::endl;
            }
        }
    }
}
void Graphe::gestionVol(BITMAP*doubleBuffer)
{   /** Parcoours des différentes arrêtes **/
    for(auto arrete:m_arrete)
    {   /** Parcours des différents avions **/
        for(auto avion:arrete->getAvionVol())
        {   /** Avion ayant plus de Carburant **/
            if(avion->getCarburant()<=0)
            {
                arrete->setSupprimerAvionVol(avion->getIdentifiant());
                setCrash(avion);
                std::cout<<"Le vol "<<avion->getIdentifiant();
                std::cout<< " s est crashe"<<std::endl;
            }   /** Avion ayant encore du carburant **/
            else
            {   /** Avion ayant finis son voyage **/
                if(avion->getUT()==arrete->getX().size())
                {   /** Avion pouvant atterrir **/
                    if(m_liste_aeroport[avion->getTrajet().back()]->placeDisponible()==true&&m_liste_aeroport[avion->getTrajet().back()]->pisteDisponible()==true)
                    {
                        std::cout<<"L avion " <<avion->getIdentifiant();
                        std::cout<<" va pouvoir atterir a "<<m_liste_aeroport[avion->getTrajet().back()]->getNom()<<std::endl;
                        m_liste_aeroport[avion->getTrajet().back()]->setAjouterAvionsPiste(avion);
                    }/** Avion devant attendre **/
                    else
                    {
                        std::cout<<"L avion " <<avion->getIdentifiant();
                        std::cout<<" va devoir attendre au dessus de "<<m_liste_aeroport[avion->getTrajet().back()]->getNom()<<std::endl;
                        m_liste_aeroport[avion->getTrajet().back()]->setAjouterAvionsAttente(avion);
                    }
                avion->setUT(0);
                arrete->setSupprimerAvionVol(avion->getIdentifiant());

                }   /** Avion en cours de voyage **/
                else
                {   /** Avion voyageant de l'arrete 1 à 2 **/
                    if(avion->getTrajet().back()==arrete->getAeroport2())
                    {
                        avion->setX(arrete->getX()[avion->getUT()]);
                        avion->setY(arrete->getY()[avion->getUT()]);
                    }/** Avion voyageant de l'arrete 2 à 1 **/
                    else
                    {
                        avion->setX(arrete->getX()[arrete->getX().size()-1-avion->getUT()]);
                        avion->setY(arrete->getY()[arrete->getY().size()-1-avion->getUT()]);
                    }
                    std::cout<<"Le vol : "<<avion->getIdentifiant();
                    std::cout<<" est en vol entre ";
                    std::cout<<m_liste_aeroport[arrete->getAeroport1()]->getNom();
                    std::cout<<" et ";
                    std::cout<<m_liste_aeroport[arrete->getAeroport2()]->getNom();
                    std::cout<<" de puis : "<<avion->getUT()<<" UT ";
                    std::cout<<"carburant restant "<<avion->getCarburant()<<std::endl;

                    changementCouleur(avion,doubleBuffer);

                    avion->setUT(avion->getUT()+1);
                    avion->setCarburant(avion->getCarburant()-avion->getConsommation());
                }
            }
        }
    }
}
void Graphe::gestionCrash(BITMAP*doubleBuffer)
{
    for(auto avion:m_crash)
    {
        blit(avion->getAvion(),doubleBuffer,0,0,avion->getX(),avion->getY(),avion->getAvion()->w,avion->getAvion()->h);
    }
}
void Graphe::Dijkstra(Aeroport* aeroport,Avion*avion,bool automatique)
{
    int initial,numSucc,arrivee;
    Aeroport* sommet=NULL;
    std::priority_queue<Aeroport*,std::vector<Aeroport*>,comparemarks> file;    /// File des sommets à traiter

    initial=aeroport->getIdentifiant();

    m_liste_aeroport[initial]->setPredecesseur(NULL);  /// Sommet initial n'a pas de predecesseur
    m_liste_aeroport[initial]->setDistance(0);         /// La distance avec le predecesseur du sommet initial vaut 0
    m_liste_aeroport[initial]->setDistancetot(0);      /// La distance total du sommet initial vaut 0


    file.push(m_liste_aeroport[initial]); /// on ajoute le sommet initial sur la file des sommets à traiter


    while(!file.empty()){   /// tant que la file n'est pas nulle
        numSucc=0;
        for(auto elem:file.top()->getVoisin()) /// on parcours les successeurs de l'élément à traiter
        {
            /// si le sommet n'a pas encore été découvert
            if(elem->getMarque()==0)
            {
                if(file.top()->getDistance()[numSucc]<=avion->getReservoir())
                {
                    elem->setDistancetot(file.top()->getDistance()[numSucc]+file.top()->getDistancetot());  /// ajoute la distance aux successeurs
                    elem->setPredecesseur(file.top());  /// ajoute le predeceseur
                    elem->setMarque(1);
                    file.push(elem);    /// on ajoute le successeur dans le site des sommets à traiter
                }
            }
            /// si le sommet a été découvert
            else if(elem->getMarque()==1)
            {
                /// si la nouvelle distance est inférieur à l'ancienne
                if(elem->getDistancetot() > file.top()->getDistance()[numSucc]+file.top()->getDistancetot())
                {
                    elem->setDistancetot(file.top()->getDistance()[numSucc]+file.top()->getDistancetot());  /// on modifie la distance
                    elem->setPredecesseur(file.top());  /// on modifie le predecesseur
                }
            }
            numSucc++;
        }
        sommet=file.top();
        sommet->setMarque(2);   /// traitement de sommet fini
        file.pop();     /// supprime le sommet de la file
    }
    if(automatique==true)
    {   /** génération d'un nouveau trajet tant qu'il n'est pas accessible **/
        do
        {
            arrivee=rand()%(m_liste_aeroport.size());
        }while(m_liste_aeroport[arrivee]->getMarque()==0||arrivee==initial);
    }
    else
    {   /** choix d'un nouveau trajet tant qu'il n'est pas accessible **/
        do
        {
            std::cout<<"Saisir l arrivee : ";
            std::cin>>arrivee;
        }while(m_liste_aeroport[arrivee]->getMarque()==0||arrivee==initial);
    }

    std::cout<<"L avion : "<<avion->getIdentifiant();
    std::cout<<" commence un nouveau voyage";
    std::cout<< "il passera par les aeroport de "<<std::endl;

    affichageDijkstra(m_liste_aeroport[arrivee],avion);
    std::cout<<std::endl;
    std::cout<<"La distance est : "<<m_liste_aeroport[arrivee]->getDistancetot()<<std::endl;
    for(auto aeroport:m_liste_aeroport)
            aeroport->setMarque(0);
}
void Graphe::affichageDijkstra(Aeroport*sommet,Avion*avion)
{
    std::cout<<sommet->getNom();    /// Affiche la sommet
    avion->setAjouterTrajet(sommet->getIdentifiant());

    if(sommet->getPredecesseur()!=NULL)     /// Si ce n'est pas le sommet initial
    {
        std::cout<<" <--(+"<<sommet->getDistancetot()-sommet->getPredecesseur()->getDistancetot()<<")-- ";  /// On affiche la distance avec le predecesseur
        affichageDijkstra(sommet->getPredecesseur(),avion);   /// On affiche le predecesseur
    }
}
void Graphe::Naif()
{
    int couleur=0;
    std::vector<Avion*>avionsTraiter;

    /** Parcours des différents avions **/
    for(auto avion:m_listeAvions)
    {
        couleur=0;
        /** Parcours des avins déjà traiter **/
        for(auto precedents:avionsTraiter)
        {   /** Avion ayant à peu près la même position **/
            if(precedents->getX()>avion->getX()-80&&precedents->getX()<=avion->getX()+80&&precedents->getY()>=avion->getY()-70&&precedents->getY()<=avion->getY()+70)
            {
                couleur++;
            }
        }
        avionsTraiter.push_back(avion);
        avion->setAltitude(couleur);
    }
}
void Graphe::changementCouleur(Avion*avion,BITMAP*doubleBuffer)
{
    int x,y,c=0,rouge,vert,bleu;

    /** Altitude 0 **/
    if(avion->getAltitude()==0)
    {
        blit(avion->getAvion(),doubleBuffer,0,0,avion->getX(),avion->getY(),avion->getAvion()->w,avion->getAvion()->h);
    }   /** Altitude 1 / Bleu **/
    if(avion->getAltitude()==1)
    {
        for(y=0; y<avion->getAvion()->h; y++)
        {
            for(x=0; x<avion->getAvion()->w; x++)
            {
                c = getpixel(avion->getAvion(),x,y);        //recupere la couleur du pixel
                bleu = getb(c);                 //recupere la composante bleue de pixel
                putpixel(doubleBuffer,avion->getX()+x,avion->getY()+y,makecol(0,0,bleu));
            }
        }
    }   /** Altitude 2 / Rouge **/
    if(avion->getAltitude()==2)          ///afficher la composante rouge de chaque pixel de l'image
    {
        for(y=0; y<avion->getAvion()->h; y++)
        {
            for(x=0; x<avion->getAvion()->w; x++)
            {
                c = getpixel(avion->getAvion(),x,y);        //recupere la couleur du pixel
                rouge = getr(c);                //recupere la composante rouge de pixel
                putpixel(doubleBuffer,avion->getX()+x,avion->getY()+y,makecol(rouge,0,0));
            }
        }
    }   /** Altitude 3 / Vert **/
    if(avion->getAltitude()==3)
    {
        for(y=0; y<avion->getAvion()->h; y++)
        {
            for(x=0; x<avion->getAvion()->w; x++)
            {
                c = getpixel(avion->getAvion(),x,y);        //recupere la couleur du pixel
                vert = getg(c);                 //recupere la composante verte de pixel
                putpixel(doubleBuffer,avion->getX()+x,avion->getY()+y,makecol(0,vert,0));
            }
        }
    }   /** Altitude 4 / Jaune **/
    if(avion->getAltitude()==4)
    {
        for(y=0; y<avion->getAvion()->h; y++)
        {
            for(x=0; x<avion->getAvion()->w; x++)
            {
                c = getpixel(avion->getAvion(),x,y);        //recupere la couleur du pixel
                vert = getg(c);
                rouge = getr(c);                //recupere la composante verte de pixel
                putpixel(doubleBuffer,avion->getX()+x,avion->getY()+y,makecol(rouge,vert,0));
            }
        }
    }   /** Altitude 5 / Turquoise **/
    if(avion->getAltitude()==5)
    {
        for(y=0; y<avion->getAvion()->h; y++)
        {
            for(x=0; x<avion->getAvion()->w; x++)
            {
                c = getpixel(avion->getAvion(),x,y);        //recupere la couleur du pixel
                vert = getg(c);
                bleu = getb(c);   //recupere la composante bleu de pixel
                putpixel(doubleBuffer,avion->getX()+x,avion->getY()+y,makecol(0,vert,bleu));
            }
        }
    }   /** Altitude 6 / Magenta **/
    if(avion->getAltitude()==6)          ///afficher la composante verte de chaque pixel de l'image
    {
        for(y=0; y<avion->getAvion()->h; y++)
        {
            for(x=0; x<avion->getAvion()->w; x++)
            {
                c = getpixel(avion->getAvion(),x,y);        //recupere la couleur du pixel
                rouge = getr(c);
                bleu = getb(c);                //recupere la composante verte de pixel
                putpixel(doubleBuffer,avion->getX()+x,avion->getY()+y,makecol(rouge,0,bleu));
            }
        }
    }
}

