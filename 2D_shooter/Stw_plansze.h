#ifndef STW_PLANSZE_H
#define STW_PLANSZE_H

#include <SFML/Graphics.hpp>
class Stw_plansze
{
    public:
        Stw_plansze(sf::RenderTarget& ref_okna);
        void narysuj_plansze(int ORYGINAL[8][8],int KOPIA[8][8],int O_K,sf::Sprite plansza);

    private:
        sf::RenderTarget* odn_okna;
        int board[8][8];
};

#endif // STW_PLANSZE_H
