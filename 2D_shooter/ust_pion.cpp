#include "ust_pion.h"

void Ust_pion::ustawianie(int pp[8][8],int pp2[8][8])  ////tworzy  poczatkowe ustawienie planszy
{
        for(int x=0;x<8;x++) {
        for(int y=0;y<8;y++) {
            if(((y+x)%2)==0){
                pp[x][y]=2;
                pp2[x][y]=2;
            }else{
                pp[x][y]=1;
                pp2[x][y]=1;
            }
        }
       }
        for(int x=0;x<8;x++) {
        for(int y=0;y<8;y++) {
          if(pp[x][y]==1 && (y<3 || y>4)){
             if(y<3){
                pp[x][y]=3;
                pp2[x][y]=3;
            }
            else if(y>4){
                pp[x][y]=4;
                pp2[x][y]=4;
                        }
            }
         }
        }

}
