#include "Zarz_oknem.h"
#include <iostream>

using namespace std;

Zarz_oknem::Zarz_oknem():
    okno( sf::VideoMode( 680, 680, 1 ), "Warcaby" ),
    stw_plansze(okno)
{
ust_pion.ustawianie(oryginal,kopia);
/*
for(int x=0;x<8;x++) {
        for(int y=0;y<8;y++) {
            cout<<oryginal[x][y]<<" ";
        }
        cout<<endl;
       }
       */
}
void Zarz_oknem::stworz()
{
	while (okno.isOpen())
	{
		wydarzenia();
		utworz();
		ai.ruch_komputera(oryginal,kopia,TURA);
		wygrana.Kto_wygrywa(oryginal,kopia,TURA,ig,ik);
	}
}

void Zarz_oknem::utworz()
{
	if (okno.isOpen())
	{
		stw_plansze.narysuj_plansze(oryginal,kopia,o_k,PLANSZA);
		okno.display();
	}
}

void Zarz_oknem::wydarzenia()
{
	while (okno.pollEvent(WYDARZENIE))
	{
		if (WYDARZENIE.type == sf::Event::Closed){
			okno.close();
		}
        if( WYDARZENIE.type == sf::Event::MouseButtonPressed && WYDARZENIE.mouseButton.button == sf::Mouse::Left && TURA==0){
                kordynacje.kordy(PLANSZA,WYDARZENIE,KX,KY);
                //cout<<KX<<endl<<KY<<endl;
                //KX=1;
                //KY=6;
                if(klik==1){
                 aktualizacja.Aktualizacja1(kopia,o_k,klik,KX,KY);
                 //o_k=1;
                // klik=2;
        }
        else if(klik==2){

                 aktualizacja.Aktualizacja1(oryginal,kopia,o_k,klik,KX,KY,TURA);
        }
        }

	}
}
