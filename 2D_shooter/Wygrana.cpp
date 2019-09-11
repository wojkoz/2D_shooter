#include "Wygrana.h"
#include <iostream>

using namespace std;
void Wygrana::Kto_wygrywa(int ORYGINAL[8][8],int KOPIA[8][8],int &tura,int &ilosc_gracza,int &ilosc_komputera) //sprawdza warunki wygranej
{
    for(int x=0;x<8;x++){
    for(int y=0;y<8;y++){
        if(y==7 && ORYGINAL[x][y]==3){
            ORYGINAL[x][y]=1;
            KOPIA[x][y]=1;
            punkty_komputera=punkty_komputera+2;
        }
        else if (y==0 && ORYGINAL[x][y]==4){
            ORYGINAL[x][y]=1;
            KOPIA[x][y]=1;
            punkty_gracza=punkty_gracza+2;
        }
    }
    }
    for(int x=0;x<8;x++){
    for(int y=0;y<8;y++){
        if(ORYGINAL[x][y]==3)aktualnak++;
        else if(ORYGINAL[x][y]==4)aktualnag++;
    }
    }
    if(aktualnak > 0 && aktualnag > 0){
        punkty_komputera=punkty_komputera+(ilosc_gracza-aktualnag);
        punkty_gracza=punkty_gracza+(ilosc_komputera-aktualnak);
        punkty_komputera=aktualnak;
        punkty_gracza=aktualnag;
    }
    else{
        if(aktualnak == 0){
                if(punkty_komputera>punkty_gracza){
                komputer_wygral=1;
                cout<<"komputer wygral";
                }
                else {
                gracz_wygral=1;
                cout<<"gracz wygral";
                }
        }
        else if(aktualnag == 0){
                if(punkty_komputera<punkty_gracza){
                gracz_wygral=1;
                cout<<"gracz wygral";
                }
                else{
                   komputer_wygral=1;
                cout<<"komputer wygral 'nie plywaj zeglowka pod wiatr ~~T.Ziel 2k19'";
                }
        }
    }
}
