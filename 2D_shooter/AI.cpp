#include "AI.h"
#include <iostream>
 using namespace std;
 //klasa odpowiedzialna za sztuczna inteligencje ( ruchy pionka oraz zbicie pionka przeciwnika)
void AI::ruch_komputera(int ORYGINAL[8][8],int KOPIA[8][8],int &tura)
{
    prio=1;
    jnt=0;
    while(tura==1){
            if(prio==1){
            for(int x=0;x<8;x++){
            for(int y=0;y<8;y++){
            if(ORYGINAL[x][y]==3){
            if(y<=6 && x>=2 && x<=5){
                    if((ORYGINAL[x-1][y+1]==4 && ORYGINAL[x-2][y+2]==1) || (ORYGINAL[x+1][y+1]==4 && ORYGINAL[x+2][y+2]==1)){
                        if(ORYGINAL[x-1][y+1]==4){
                                Sleep(500);
                            ORYGINAL[x][y]=1;
                            ORYGINAL[x-1][y+1]=1;
                            ORYGINAL[x-2][y+2]=3;
                            jnt++;
                        }
                        else if(ORYGINAL[x+1][y+1]==4){
                            Sleep(500);
                            ORYGINAL[x][y]=1;
                            ORYGINAL[x+1][y+1]=1;
                            ORYGINAL[x+2][y+2]=3;
                            jnt++;
                        }
                    }
                    }

                    else if(y<=6 && (x==0 || x==1)){
                            if(ORYGINAL[x+1][y+1]==4 && ORYGINAL[x+2][y+2]==1){
                                    Sleep(500);
                            ORYGINAL[x][y]=1;
                            ORYGINAL[x+1][y+1]=1;
                            ORYGINAL[x+2][y+2]=3;
                            jnt++;
                    }
                    }
                    else if(y<=6 && (x==7 || x==6)){
                            if(ORYGINAL[x-1][y+1]==4 && ORYGINAL[x-2][y+2]==1){
                                    Sleep(500);
                            ORYGINAL[x][y]=1;
                            ORYGINAL[x-1][y+1]=1;
                            ORYGINAL[x-2][y+2]=3;
                            jnt++;
                    }
                    }

            }
            }
            }
            }//koniec prio 1
            if(jnt>0)prio=5;
            else prio=2;
            if(prio==2){
            for(int x=0;x<8;x++){
            for(int y=0;y<8;y++){
            if(ORYGINAL[x][y]==3 && y>=3 && y<7 && x>0 && x<7 && jnt==0){
                    if(ORYGINAL[x+1][y+1]==4 || ORYGINAL[x-1][y+1]==4){
                        if(ORYGINAL[x+1][y+1]==4){
                            if(ORYGINAL[x-1][y-1]==1){
                                if(x-2>0){
                                if(ORYGINAL[x-2][y-2]==3){
                                    Sleep(500);
                                    ORYGINAL[x-2][y-2]=1;
                                    ORYGINAL[x-1][y-1]=3;
                                    jnt=1;
                                    prio=5;
                                   }
                                   }
                                   else if(ORYGINAL[x][y-2]==3){
                                       Sleep(500);
                                    ORYGINAL[x][y-2]=1;
                                    ORYGINAL[x-1][y-1]=3;
                                    jnt=1;
                                    prio=5;
                                   }
                            }
                        }
                        if(ORYGINAL[x-1][y+1]==4){
                            if(ORYGINAL[x+1][y-1]==1){
                                if(x+2<7){
                                    if(ORYGINAL[x+2][y-2]==3){
                                            Sleep(500);
                                    ORYGINAL[x+2][y-2]=1;
                                    ORYGINAL[x+1][y-1]=3;
                                    jnt=1;
                                    prio=5;
                                   }
                                   }
                                   }
                                   else if(ORYGINAL[x][y-2]==3){
                                        Sleep(500);
                                    ORYGINAL[x][y-2]=1;
                                    ORYGINAL[x+1][y-1]=3;
                                    jnt=1;
                                    prio=5;
                                   }
                        }
                    }
            }
            }
            }
            }
            if(prio!=5)prio=3;
            if(prio==3){
            int zlicz1=0,zlicz2=0,zlicz3=0;
            for(int x=0;x<8;x++) {
            for(int y=0;y<8;y++) {
            if(x<=2 && ORYGINAL[x][y]==4)zlicz1++;
            else if(x>=2 && x<=5 && ORYGINAL[x][y]==4)zlicz2++;
            else if(x>=5 && ORYGINAL[x][y]==4)zlicz3++;
            }
            }
            if(zlicz1>zlicz2 && zlicz1>zlicz3){
               for(int x=0;x<8;x++) {
               for(int y=0;y<8;y++) {
                    if(y<7){
                   if(x<=3 && ORYGINAL[x][y]==3 && jnt==0){
                   if((x==0 && ORYGINAL[x+1][y+1]==1) || (x==3 && ORYGINAL[x-1][y+1]==1)){
                       if(x==0 && ORYGINAL[x+1][y+1]==1){
                        if(y<=5){
                    if(ORYGINAL[x][y+2]!=4 && ORYGINAL[x+2][y+2]!=4){
                            Sleep(500);
                    ORYGINAL[x][y]=1;
                    ORYGINAL[x+1][y+1]=3;
                    jnt=1;
                    prio=5;
                        }
                        }
                        else {
                            Sleep(500);
                    ORYGINAL[x][y]=1;
                    ORYGINAL[x+1][y+1]=3;
                    jnt=1;
                    prio=5;
                        }
                       }
                        if(x==3 && ORYGINAL[x-1][y+1]==1){
                        if(y<=5){
                    if(ORYGINAL[x][y+2]!=4 && ORYGINAL[x-2][y+2]!=4){
                        Sleep(500);
                    ORYGINAL[x][y]=1;
                    ORYGINAL[x-1][y+1]=3;
                    jnt=1;
                    prio=5;
                        }
                        }
                        else {
                            Sleep(500);
                    ORYGINAL[x][y]=1;
                    ORYGINAL[x-1][y+1]=3;
                    jnt=1;
                    prio=5;
                        }
                       }
                   }
                   else {
                        if((x==1 || x==2) && (ORYGINAL[x+1][y+1]==1 || ORYGINAL[x-1][y+1]==1)){
                        if(y<=5 && ORYGINAL[x+1][y+1]==1){
                            if(ORYGINAL[x][y+2]!=4 && ORYGINAL[x+2][y+2]!=4){
                                    Sleep(500);
                                ORYGINAL[x][y]=1;
                                ORYGINAL[x+1][y+1]=3;
                                jnt=1;
                                prio=5;
                            }
                        }
                        else if(y<=5 && ORYGINAL[x-1][y+1]==1){
                            if(ORYGINAL[x][y+2]!=4 || ORYGINAL[x-2][y+2]!=4){
                                    Sleep(500);
                                ORYGINAL[x][y]=1;
                                ORYGINAL[x-1][y+1]=3;
                                jnt=1;
                                prio=5;
                            }
                        }
                        else if(y>5 && ORYGINAL[x+1][y+1]==1){
                                Sleep(500);
                            ORYGINAL[x][y]=1;
                                ORYGINAL[x+1][y+1]=3;
                                jnt=1;
                                prio=5;
                        }
                        else if(y>5 && ORYGINAL[x-1][y+1]==1){
                            Sleep(500);
                            ORYGINAL[x][y]=1;
                                ORYGINAL[x-1][y+1]=3;
                                jnt=1;
                                prio=5;
                        }
                        }
                   }
               }
               }
               }
               }
               }//koniec zlicz1
               else if(zlicz2>zlicz1 && zlicz2>zlicz3){
               for(int x=0;x<8;x++) {
               for(int y=0;y<8;y++) {
                    if(y<7){
                   if(x>=2 && x<=5 && ORYGINAL[x][y]==3 && jnt==0){
                   if((x==2 && ORYGINAL[x+1][y+1]==1) || (x==5 && ORYGINAL[x-1][y+1]==1)){
                       if(x==2 && ORYGINAL[x+1][y+1]==1){
                        if(y<=5){
                    if(ORYGINAL[x][y+2]!=4 && ORYGINAL[x+2][y+2]!=4){
                            Sleep(500);
                    ORYGINAL[x][y]=1;
                    ORYGINAL[x+1][y+1]=3;
                    jnt=1;
                    prio=5;
                        }
                        }
                        else {
                            Sleep(500);
                    ORYGINAL[x][y]=1;
                    ORYGINAL[x+1][y+1]=3;
                    jnt=1;
                    prio=5;
                        }
                       }
                        if(x==5 && ORYGINAL[x-1][y+1]==1){
                        if(y<=5){
                    if(ORYGINAL[x][y+2]!=4 && ORYGINAL[x-2][y+2]!=4){
                        Sleep(500);
                    ORYGINAL[x][y]=1;
                    ORYGINAL[x-1][y+1]=3;
                    jnt=1;
                    prio=5;
                        }
                        }
                        else {
                            Sleep(500);
                    ORYGINAL[x][y]=1;
                    ORYGINAL[x-1][y+1]=3;
                    jnt=1;
                    prio=5;
                        }
                       }
                   }
                   else {
                        if((x==3 || x==4) && (ORYGINAL[x+1][y+1]==1 || ORYGINAL[x-1][y+1]==1)){
                        if(y<=5 && ORYGINAL[x+1][y+1]==1){
                            if(ORYGINAL[x][y+2]!=4 && ORYGINAL[x+2][y+2]!=4){
                                    Sleep(500);
                                ORYGINAL[x][y]=1;
                                ORYGINAL[x+1][y+1]=3;
                                jnt=1;
                                prio=5;
                            }
                        }
                        else if(y<=5 && ORYGINAL[x-1][y+1]==1){
                            if(ORYGINAL[x][y+2]!=4 || ORYGINAL[x-2][y+2]!=4){
                                    Sleep(500);
                                ORYGINAL[x][y]=1;
                                ORYGINAL[x-1][y+1]=3;
                                jnt=1;
                                prio=5;
                            }
                        }
                        else if(y>5 && ORYGINAL[x+1][y+1]==1){
                                Sleep(500);
                            ORYGINAL[x][y]=1;
                                ORYGINAL[x+1][y+1]=3;
                                jnt=1;
                                prio=5;
                        }
                        else if(y>5 && ORYGINAL[x-1][y+1]==1){
                            Sleep(500);
                            ORYGINAL[x][y]=1;
                                ORYGINAL[x-1][y+1]=3;
                                jnt=1;
                                prio=5;
                        }
                        }
                   }
               }
               }
               }
               }
               }
               else if(zlicz3>zlicz1 && zlicz3>zlicz2){
               for(int x=0;x<8;x++) {
               for(int y=0;y<8;y++) {
                    if(y<7){
                   if(x>=4 && ORYGINAL[x][y]==3 && jnt==0){
                   if((x==4 && ORYGINAL[x+1][y+1]==1) || (x==7 && ORYGINAL[x-1][y+1]==1)){
                       if(x==4 && ORYGINAL[x+1][y+1]==1){
                        if(y<=5){
                    if(ORYGINAL[x][y+2]!=4 && ORYGINAL[x+2][y+2]!=4){
                            Sleep(500);
                    ORYGINAL[x][y]=1;
                    ORYGINAL[x+1][y+1]=3;
                    jnt=1;
                    prio=5;
                        }
                        }
                        else {
                            Sleep(500);
                    ORYGINAL[x][y]=1;
                    ORYGINAL[x+1][y+1]=3;
                    jnt=1;
                    prio=5;
                        }
                       }
                        if(x==7 && ORYGINAL[x-1][y+1]==1){
                        if(y<=5){
                    if(ORYGINAL[x][y+2]!=4 && ORYGINAL[x-2][y+2]!=4){
                        Sleep(500);
                    ORYGINAL[x][y]=1;
                    ORYGINAL[x-1][y+1]=3;
                    jnt=1;
                    prio=5;
                        }
                        }
                        else {
                            Sleep(500);
                    ORYGINAL[x][y]=1;
                    ORYGINAL[x-1][y+1]=3;
                    jnt=1;
                    prio=5;
                        }
                       }
                   }
                   else {
                        if((x==5 || x==6) && (ORYGINAL[x+1][y+1]==1 || ORYGINAL[x-1][y+1]==1)){
                        if(y<=5 && ORYGINAL[x+1][y+1]==1){
                            if(ORYGINAL[x][y+2]!=4 && ORYGINAL[x+2][y+2]!=4){
                                    Sleep(500);
                                ORYGINAL[x][y]=1;
                                ORYGINAL[x+1][y+1]=3;
                                jnt=1;
                                prio=5;
                            }
                        }
                        else if(y<=5 && ORYGINAL[x-1][y+1]==1){
                            if(ORYGINAL[x][y+2]!=4 || ORYGINAL[x-2][y+2]!=4){
                                    Sleep(500);
                                ORYGINAL[x][y]=1;
                                ORYGINAL[x-1][y+1]=3;
                                jnt=1;
                                prio=5;
                            }
                        }
                        else if(y>5 && ORYGINAL[x+1][y+1]==1){
                                Sleep(500);
                            ORYGINAL[x][y]=1;
                                ORYGINAL[x+1][y+1]=3;
                                jnt=1;
                                prio=5;
                        }
                        else if(y>5 && ORYGINAL[x-1][y+1]==1){
                            Sleep(500);
                            ORYGINAL[x][y]=1;
                                ORYGINAL[x-1][y+1]=3;
                                jnt=1;
                                prio=5;
                        }
                        }
                   }
               }
               }
               }
               }
            }
            }
            if(prio!=5)prio=4;
            if(prio==4){
            for(int x=0;x<8;x++) {
            for(int y=0;y<8;y++) {
            if(ORYGINAL[x][y]==3 && jnt==0){
                if(y<=6){
                    if(x==0 && ORYGINAL[x+1][y+1]==1){
                            Sleep(500);
                    ORYGINAL[x][y]=1;
                    ORYGINAL[x+1][y+1]=3;
                    jnt=1;
                    prio=5;
                    }
                    else if(x==7 && ORYGINAL[x-1][y+1]==1){
                        Sleep(500);
                    ORYGINAL[x][y]=1;
                    ORYGINAL[x-1][y+1]=3;
                    jnt=1;
                    prio=5;
                    }
                    else if(x>0 && x<7 && (ORYGINAL[x-1][y+1]==1 || ORYGINAL[x+1][y+1]==1)){
                        if(ORYGINAL[x-1][y+1]==1){
                            Sleep(500);
                        ORYGINAL[x][y]=1;
                    ORYGINAL[x-1][y+1]=3;
                    jnt=1;
                    prio=5;
                        }
                        else if(ORYGINAL[x+1][y+1]==1){
                            Sleep(500);
                    ORYGINAL[x][y]=1;
                    ORYGINAL[x+1][y+1]=3;
                    jnt=1;
                    prio=5;
                        }
                    }
                }
            }
            }
            }
            }
            if(prio==5){
            for(int x=0;x<8;x++) {
            for(int y=0;y<8;y++) {
            KOPIA[x][y]=ORYGINAL[x][y];
            }
            }
            tura=0;
            }
          }//koniec tury
}
