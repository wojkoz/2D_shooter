#include "Kordynacje.h"
#include <iostream>

using namespace std;
void Kordynacje::kordy(sf::Sprite plansza,sf::Event wydarzenie,int &kx,int &ky) //sprawdza i zapisuje parametry pola
{
            plansza.setPosition(wydarzenie.mouseButton.x, wydarzenie.mouseButton.y);
            xpoz=plansza.getPosition().x;
            ypoz=plansza.getPosition().y;

            spr=0;
            kx=1;
            ky=1;
            while(spr < 2)
            {
                while (spr < 1)
                {
                 if(xpoz>(kx-1)*85 && xpoz<kx*85){
                        spr++;
                 }
                 else kx++;
                }
                if(ypoz>(ky-1)*85 && ypoz<ky*85)spr++;
                 else ky++;
            }

}
