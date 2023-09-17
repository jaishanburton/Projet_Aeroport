#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
#include "headers.h"

class Map
{

   private :
   /***Attributs***/
   BITMAP* m_planisphere;
   int m_positionX;
   int m_positionY;

   public :
    /***Constructeur & Destructeur ***/
    Map();
    ~Map();

    /***Accesseurs***/
    int getX();
    int getY();
    BITMAP* getPlanisphere();

    /***Méthodes***/
    void affichage(BITMAP *doublebuffer); /// Affiche l'ensemble des élements
    void initialisationAllegro(); /// Initilisation de la biblio graphique
    void affichage_coordonnees(BITMAP *doublebuffer);/// Affichage coordonnées de la souris
    void affichage_sommet(BITMAP* doublebuffer,std::vector<Aeroport*>listeAeroport);  /// Affichage des aeroport
    void affichage_arete(BITMAP* doublebuffer,std::vector<Aeroport*>listeAeroport); /// Affichage des arrete
    void affichage_image(BITMAP* doublebuffer); /// Affiche le planisphère
    void affichage_quadrillage(BITMAP* doublebuffer);/// Affichage quadrillage


};

#endif // MAP_H_INCLUDED
