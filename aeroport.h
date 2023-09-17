#ifndef AEROPORT_H_INCLUDED
#define AEROPORT_H_INCLUDED

#include "headers.h"

class Aeroport
{
private:
    /** Attribut **/
    int m_identifiant;
    std::string m_nom;
    int m_x;
    int m_y;
    int m_nbPistes;
    int m_nbPlaces;
    int m_attSol;
    int m_acces;
    int m_duree;
    int m_anticollision;
    int m_tempsDecollage;
    int m_boucle;
    int m_marque;

    std::vector<Aeroport*> m_aeroportsVoisin;
    std::vector<Avion*>m_avionsPiste;
    std::vector<Avion*>m_avionsSol;
    std::vector<Avion*>m_avionsAttente;
    std::vector<int> m_distance;    /// Ponderation avec les successeurs
    int m_distancetotale;   /// Distance depuis le sommet initial
    Aeroport* m_predecesseur; /// predecesseur

public:
    /** Constructeur**/
    Aeroport(int identifiant,std::string name,int piste,int place,int sol,int access,int duree,int anticol,int decollage,int bouc,int x,int y);

    /** Accesseurs **/
    std::string getNom()const;
    int getPistes()const;
    int getPlaces()const;
    int getSol()const;
    int getAcces()const;
    int getDuree()const;
    int getCollision()const;
    int getBoucle()const;
    int getDecollage()const;
    int getX();
    int getY();
    int getIdentifiant();
    int getMarque();
    std::vector<Aeroport*>&getVoisin();
    std::vector<Avion*>&getAvionsPiste();
    std::vector<Avion*>&getAvionsSol();
    std::vector<Avion*>&getAvionsAttente();
    void setMarque(int marque);
    void setDistancetot(int distance);
    int getDistancetot()const;
    std::vector<int> getDistance()const;
    void setDistance(int distance);
    Aeroport* getPredecesseur()const;
    void setPredecesseur(Aeroport* predecesseur);
    void setNom(std::string Name);
    void setPistes(int nombrPistes);
    void setPlaces(int nombrPlaces);
    void setSol(int atterisol);
    void setAcces(int acceder);
    void setDuree(int timer);
    void setCollision(int coli);
    void setBoucle(int bou);
    void setAjouterAvionsPiste(Avion*avion);
    void setAjouterAvionsSol(Avion*avion);
    void setAjouterAvionsAttente(Avion*avion);
    void setSupprimerAvionsPiste(int identifiant);
    void setSupprimerAvionsSol(int identifiant);
    void setSupprimerAvionsAttente(int identifiant);

    /** Méthodes **/
    void ajouterVoisin(Aeroport*voisin); /// Ajoute un aeroport adjacent
    void afficher()const; /// Affiche un aeroport
    bool placeDisponible(); /// Place disponible dans l aeroport
    bool pisteDisponible(); ///Piste disponible
};
class Arrete
{

private:
    /** Attributs **/
    int m_Aeroport1;
    int m_Aeroport2;
    int m_ponderation; ///distance entre les aeroports
    std::vector<Avion*> m_avionVol;
    std::vector<int>m_x;
    std::vector<int>m_y;

public:
    /** Constructeur **/
    Arrete(int ini, int fin, int ponderation);

    /** Accesseurs **/
    int getAeroport1()const;
    int getAeroport2()const;
    int getPonderation()const;
    std::vector<Avion*>&getAvionVol();
    std::vector<int>&getX();
    std::vector<int>&getY();
    void setPonderation(int pond);
    void setAjouterAvionVol(Avion*avion);
    void setSupprimerAvionVol(int numAvion);

    /** Méthode **/
    void affichage();/// Affiche les attributs de l'arrete

};
class Graphe
{
private:
    /** Attributs **/
    std::vector<Aeroport*> m_liste_aeroport;
    std::vector<Arrete*> m_arrete;
    std::vector<Avion*>m_listeAvions;
    std::vector<Avion*>m_crash;
public:
    /** Constructeur/Destructeur **/
    Graphe(std::string nomFichier);
    ~Graphe();

    /** Accesseurs **/
    std::vector<Avion*>&getListeAvions();
    std::vector<Avion*>&getCrash();
    std::vector<Aeroport*>&getListeAeroport();
    void setCrash(Avion*avion);

    /** Méthodes **/
    void afficher()const; /// Affiche attributs
    void ChargementAvions(); /// Charge les avions dans un fichier
    void gestionAeroport(); /// Gere les avions dans les differents aeroport
    void gestionVol(BITMAP*doubleBuffer); /// Gere les vols des différents avions
    void Dijkstra(Aeroport*aeroport,Avion*avion,bool automatique);/// Calcul la destination
    void affichageDijkstra(Aeroport*sommet,Avion*avion);/// Ajoute le trajet d'un avion
    void Naif(); /// Algorithme naif pour altitude des avions
    void changementCouleur(Avion*avion,BITMAP*doubleBuffer);/// Modifie les couleurs des avions en fonctions de leur altitude
    void gestionCrash(BITMAP*doubleBuffer);/// Liste des avions crashé
};
struct comparemarks{ /// Critère de comparaison priority queue
   bool operator()(Aeroport* s1, Aeroport *s2)
   {
      return s1->getDistancetot() > s2->getDistancetot();   /// Distance depuis le sommet initial
   }
};


#endif // AEROPORT_H_INCLUDED
