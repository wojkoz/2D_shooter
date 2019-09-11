#ifndef ZARZ_OKNEM_H
#define ZARZ_OKNEM_H
#include "ust_pion.h"
#include "Stw_plansze.h"
#include "Aktualizacja.h"
#include "Kordynacje.h"
#include "Zarz_oknem.h"
#include "AI.h"
#include "Wygrana.h"
#include <SFML/Graphics.hpp>

class Zarz_oknem
{
    public:
        Zarz_oknem();
        void stworz();
        void utworz();
        void wydarzenia();
    private:
        sf::RenderWindow okno;
        sf::Event WYDARZENIE;
        sf::Sprite PLANSZA;
        Stw_plansze stw_plansze;
        Ust_pion ust_pion;
        int oryginal[8][8],kopia[8][8];
        int o_k=0,klik=1;
        int KX,KY;
        Kordynacje kordynacje;
        Aktualizacja aktualizacja;
        int TURA=0;
        AI ai;
        int ig=12,ik=12;
        Wygrana wygrana;
};

#endif // ZARZ_OKNEM_H
