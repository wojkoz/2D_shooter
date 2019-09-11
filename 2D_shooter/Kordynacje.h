#ifndef KORDYNACJE_H
#define KORDYNACJE_H
#include <SFML/Graphics.hpp>

class Kordynacje
{
    public:
    void kordy(sf::Sprite plansza,sf::Event wydarzenie,int &kx,int &ky);
    private:
    int xpoz,ypoz,spr;
};

#endif // KORDYNACJE_H
