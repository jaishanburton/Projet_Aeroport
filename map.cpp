#include "headers.h"
using namespace std;

void Map::initialisationAllegro()
{
    allegro_init();
    install_keyboard();
    install_mouse();

    set_color_depth(desktop_color_depth());
    if((set_gfx_mode(GFX_AUTODETECT_WINDOWED,1200,650,0,0))!=0)
    {
        allegro_message("Pb de mode graphique") ;
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    show_mouse(screen);   /// pour avoir la souris dans la console de compilation
    install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,NULL);
}

Map::Map()
{
    m_positionX=0;
    m_positionY=0;
}

Map::~Map()
{

}

BITMAP*Map::getPlanisphere()
{
    return m_planisphere;
}

int Map::getX()
{
    return m_positionX;
}
int Map::getY()
{
    return m_positionY;
}

void Map::affichage_coordonnees(BITMAP *doublebuffer)
{
    textprintf_ex(doublebuffer,font, 1060, 20,makecol(0,0,0),-1, " x: %d y: %d", mouse_x,mouse_y);
    textprintf_ex(doublebuffer,font, 1060, 20,makecol(0,0,0),-1, " x: %d y: %d", mouse_x,mouse_y);
}

void Map::affichage_image(BITMAP* doublebuffer)
{
    m_planisphere=load_bitmap("images/planisphere.bmp",NULL);
    blit(getPlanisphere(),doublebuffer, 0, 0,getX(), getY(), getPlanisphere()->w, getPlanisphere()->h);
    destroy_bitmap(getPlanisphere());
}

void Map::affichage_sommet(BITMAP* doublebuffer,std::vector<Aeroport*>listeAeroport)
{
    for(auto aeroport:listeAeroport)
        circlefill(doublebuffer,aeroport->getX(),aeroport->getY(),5,makecol(255,0,0));
}

void Map::affichage_arete(BITMAP* doublebuffer,std::vector<Aeroport*>listeAeroport)
{
    for(auto aeroport:listeAeroport)
    {
        for(auto voisin:aeroport->getVoisin())
        {
            line(doublebuffer,aeroport->getX(),aeroport->getY(),voisin->getX(),voisin->getY(),makecol(255,0,0));
        }
    }
}

void Map::affichage_quadrillage(BITMAP* doublebuffer)
{
    int i;
    int j;
    for(i=0;i<39;i++)
    {
        for(j=0;j<20;j++)
        {
            hline(doublebuffer,310,215+17*j,1070,makecol(0,0,0));
            vline(doublebuffer,310+20*i,215,538,makecol(0,0,0));

        }
    }
}

void Map::affichage(BITMAP *doublebuffer)
{
    /** Varibale **/
    int choix,depart,UT=0;
    Avion*avion=NULL;
    std::string type;
    Graphe g{"aeroport.txt"}; /// Chargement du graphe
    doublebuffer=create_bitmap(SCREEN_W,SCREEN_H); /// Creation double buffer
    m_planisphere=load_bitmap("images/planisphere.bmp",NULL);


    do
    {   /** Affichage du MENU  et choix utilisateur **/
        std::cout<<"**** MENU ****"<<std::endl;
        std::cout<<"1) PCC"<<std::endl;
        std::cout<<"2) Simulation"<<std::endl;
        std::cout<<"3) Affichage Aeroport"<<std::endl;
        std::cout<<"4) Quitter"<<std::endl;
        do
        {
            std::cout<<"Choix : ";
            std::cin>>choix;
        }while(choix<1||choix>4);

        /** Affichage PCC **/
        if(choix==1)
        {
            do
            {
                std::cout<<"Type d'avion : ";
                std::cin>>type;
            }while(type!="Court"&&type!="Long"&&type!="Moyen");

            if(type=="Court")
                avion=new Avion{type,0,8000};
            else if(type=="Moyen")
                avion=new Avion{type,0,10000};
            else if(type=="Long")
                avion=new Avion{type,0,15000};

            std::cout<<"0) Paris"<<std::endl;
            std::cout<<"1) Dubai"<<std::endl;
            std::cout<<"2) New_York"<<std::endl;
            std::cout<<"3) Rio"<<std::endl;
            std::cout<<"4) Cap_Town"<<std::endl;
            std::cout<<"5) Sydney"<<std::endl;
            std::cout<<"6) Tokyo"<<std::endl;
            do
            {
                std::cout<<"Aeroport de depart : ";
                std::cin>>depart;
            }while(depart<0||depart>g.getListeAeroport().size()-1);
            g.Dijkstra(g.getListeAeroport()[depart],avion,false);

            while(!key[KEY_ESC])
            {
                clear_bitmap(doublebuffer);
                affichage_image(doublebuffer);
                affichage_sommet(doublebuffer,g.getListeAeroport());
                for(int i=1;i<avion->getTrajet().size();i++)
                {
                    line(doublebuffer,g.getListeAeroport()[avion->getTrajet()[i-1]]->getX(),g.getListeAeroport()[avion->getTrajet()[i-1]]->getY(),g.getListeAeroport()[avion->getTrajet()[i]]->getX(),g.getListeAeroport()[avion->getTrajet()[i]]->getY(),makecol(255,0,0)); ///arête NY vers Paris
                }
                blit(doublebuffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);///affichage du double Buffer
            }
            avion->~Avion();
        }
        /** Affichage Simulation **/
        else if(choix==2)
        {
            UT=0;
            while(UT<100)
            {
                UT++;
                std::cout<<"********** TOUR "<<UT<<" ****************"<<std::endl;
                clear_bitmap(doublebuffer);

                affichage_image(doublebuffer);
                affichage_coordonnees(doublebuffer);
                affichage_quadrillage(doublebuffer);
                affichage_arete(doublebuffer,g.getListeAeroport());
                affichage_sommet(doublebuffer,g.getListeAeroport());

                /** Affiche Aeroport et Avion par clique **/
                 if(mouse_b&1)
                    {
                        for(auto aeroport:g.getListeAeroport())
                        {
                            if(mouse_x>aeroport->getX()-10&&mouse_x<aeroport->getX()+10&&mouse_y>aeroport->getY()-8&&mouse_y<aeroport->getY()+8)
                                aeroport->afficher();
                        }
                        for(auto avion:g.getListeAvions())
                        {
                            if(mouse_x>avion->getX()-10&&mouse_x<avion->getX()+10&&mouse_y>avion->getY()-8&&mouse_y<avion->getY()+8)
                                avion->afficher();
                        }
                    }
                g.Naif();
                g.gestionAeroport();
                g.gestionVol(doublebuffer);
                g.gestionCrash(doublebuffer);

                blit(doublebuffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);///affichage du double Buffer
                rest(1000);

            }
        }
        /** Afficher les aeroports **/
        else if(choix ==3)
        {
            g.afficher();
        }
    }while(choix!=4);
    destroy_bitmap(doublebuffer);
}

