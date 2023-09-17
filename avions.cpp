#include "headers.h"
Avion::Avion(std::string type,int identifiant,int reservoir):
    m_type(type),m_identifiant(identifiant),m_carburant(reservoir),m_reservoir(reservoir)
{
    std::string Name;
    m_consommation=100;
    m_ut=0;
    m_vitesse=0;

    /**** Convertion string en char ****/
    Name="images/avion"+type+".bmp";
    char *image_avion= new char [Name.size()+1];
    strncpy(image_avion,Name.c_str(),Name.size()+1);
    /************************************/
    m_avion=load_bitmap(image_avion,NULL);
}
Avion::~Avion()
{
    destroy_bitmap(m_avion);
}
void Avion::afficher()
{
    std::cout<<"******* AVION N "<<m_identifiant<<"********"<<std::endl;
    std::cout<<"Type : "<<m_type<<std::endl;
    std::cout<<"Position : "<<m_x<<" "<<m_y<<std::endl;
    std::cout<<"Reservoir : "<<m_reservoir<<std::endl;
    std::cout<<"Carburant : "<<m_carburant<<std::endl;
    std::cout<<"Consommation : "<<m_consommation<<std::endl;
    std::cout<<"UT : "<<m_ut<<std::endl;
}

/*********** Accesseurs *****************/
int Avion::getConsommation(){return m_consommation;}
int Avion::getReservoir(){return m_reservoir;}
int Avion::getCarburant(){return m_carburant;}
int Avion::getIdentifiant(){return m_identifiant;}
int Avion::getUT(){return m_ut;}
int Avion::getX(){return m_x;}
int Avion::getY(){return m_y;}
int Avion::getVitesse(){return m_vitesse;}
int Avion::getAltitude(){return m_altitude;}
std::vector<int>&Avion::getTrajet(){return m_trajet;}
BITMAP*Avion::getAvion()
{
    return m_avion;
}
void Avion::setAvion(){m_avion=load_bitmap("images/crash.bmp",NULL);}
void Avion::setAltitude(int altitude){m_altitude=altitude;}
void Avion::setAjouterTrajet(int id){m_trajet.push_back(id);}
void Avion::setSupprimerTrajet()
{
    m_trajet.pop_back();
}
void Avion::setVitesse(int vitesse){m_vitesse=vitesse;}
void Avion::setX(int x){m_x=x;}
void Avion::setY(int y){m_y=y;}
void Avion::setUT(int temps){m_ut=temps;}
void Avion::setCarburant(int carburant){m_carburant=carburant;}
void Avion::setConsomation(int consommation){m_consommation=consommation;}
/****************************************/

