#include "Aktualizacja.h"
#include <iostream>

using namespace std;

void Aktualizacja::Aktualizacja1(int KOPIA[8][8],int &O_K,int &KLIK,int kx,int ky)  //oznacza pole dostepne do poruszania sie pionka
{

    if(KOPIA[kx-1][ky-1]==4){
        if((kx-1)!=0 && (kx-1)!= 7 && (ky-1)!=0){
                if(ky-2>=0){
                    if(KOPIA[kx][ky-2]==1 || KOPIA[kx-2][ky-2]==1){
                        if(KOPIA[kx][ky-2]==1){
                                KOPIA[kx-1][ky-1]=6;
                                KOPIA[kx][ky-2]=5;
                                O_K=1;
                                KLIK=2;
                        }
                        if(KOPIA[kx-2][ky-2]==1){
                                KOPIA[kx-1][ky-1]=6;
                                KOPIA[kx-2][ky-2]=5;
                                O_K=1;
                                KLIK=2;
                        }
                    }
                if(KOPIA[kx][ky-2]==3 || KOPIA[kx-2][ky-2]==3){
                            if(ky-3>=0){
                                if(KOPIA[kx+1][ky-3]==1 && KOPIA[kx][ky-2]==3){
                                    KOPIA[kx-1][ky-1]=6;
                                    KOPIA[kx][ky-2]=7;
                                    KOPIA[kx+1][ky-3]=5;
                                    O_K=1;
                                    KLIK=2;
                                }
                                if(KOPIA[kx-3][ky-3]==1 && KOPIA[kx-2][ky-2]==3){
                                    KOPIA[kx-1][ky-1]=6;
                                    KOPIA[kx-2][ky-2]=7;
                                    KOPIA[kx-3][ky-3]=5;
                                    O_K=1;
                                    KLIK=2;
                                }


                            }
                    }
                }

        }

        else if((kx-1)==0 && (ky-1)!=0){
                if(ky-2>=0){
                    if(KOPIA[kx][ky-2]==1 || KOPIA[kx][ky-2]==3){
                    if(KOPIA[kx][ky-2]==1){
                       KOPIA[kx-1][ky-1]=6;
                       KOPIA[kx][ky-2]=5;
                       O_K=1;
                       KLIK=2;
                    }
                    else if(KOPIA[kx][ky-2]==3){
                            if(ky-3>=0){
                                if(KOPIA[kx+1][ky-3]==1){
                                    KOPIA[kx-1][ky-1]=6;
                                    KOPIA[kx][ky-2]=7;
                                    KOPIA[kx+1][ky-3]=5;
                                    O_K=1;
                                    KLIK=2;
                                }
                            }
                    }
                }
        }
        }
        else if((kx-1)==7 && (ky-1)!=0){
                if(ky-2>=0){
                    if(KOPIA[kx-2][ky-2]==1 || KOPIA[kx-2][ky-2]==3){
                    if(KOPIA[kx-2][ky-2]==1){
                       KOPIA[kx-1][ky-1]=6;
                       KOPIA[kx-2][ky-2]=5;
                       O_K=1;
                       KLIK=2;
                    }
                    else if(KOPIA[kx-2][ky-2]==3){
                            if(ky-3>=0){
                                if(KOPIA[kx-3][ky-3]==1){
                                    KOPIA[kx-1][ky-1]=6;
                                    KOPIA[kx-2][ky-2]=7;
                                    KOPIA[kx-3][ky-3]=5;
                                    O_K=1;
                                    KLIK=2;
                                }
                            }
                    }
                }
        }
    }
}

}
void Aktualizacja::Aktualizacja1(int ORYGINAL[8][8],int KOPIA[8][8],int &O_K,int &KLIK,int kx,int ky,int &tura)  //sprawdza czy oznaczone pole zostalo
                                                                                                                 //nacisniete w przeciwnym przypadku cofa
{                                                                                                               //dzialanie poprzedniej metody
    if(KOPIA[kx-1][ky-1]==5){
        KOPIA[kx-1][ky-1]=4;
        for(int x=0;x<8;x++) {
        for(int y=0;y<8;y++) {
            if(KOPIA[x][y]==5 || KOPIA[x][y]==6 || KOPIA[x][y]==7)
            KOPIA[x][y]=1;
            }
        }
        for(int x=0;x<8;x++) {
        for(int y=0;y<8;y++) {
            ORYGINAL[x][y]=KOPIA[x][y];
            }
        }
        O_K=0;
        KLIK=1;
        tura=1;
    }
    else{
        for(int x=0;x<8;x++) {
        for(int y=0;y<8;y++) {
            KOPIA[x][y]=ORYGINAL[x][y];
            }
        }
    O_K=0;
    KLIK=1;
    }
}
