#include "Stw_plansze.h"
#include <iostream>
 using namespace std;
Stw_plansze::Stw_plansze(sf::RenderTarget& ref_okna) : odn_okna(&ref_okna)
{
}
void Stw_plansze::narysuj_plansze(int ORYGINAL[8][8],int KOPIA[8][8],int O_K,sf::Sprite plansza) //przypisuje odpowiedni schemat  planszy i go wywoluje
{
    //stworzenie paternu planszy
       if(O_K==0){
            for(int x=0;x<8;x++) {
        for(int y=0;y<8;y++) {
            board[x][y]=ORYGINAL[x][y];
            }
        }
        //board[8][8]=ORYGINAL[8][8];
       }
       else if(O_K==1){
           for(int x=0;x<8;x++) {
        for(int y=0;y<8;y++) {
            board[x][y]=KOPIA[x][y];
            }
        }
       // board[8][8]=KOPIA[8][8];
       }
       //wyrysowanie w oknie
        odn_okna->clear();

        sf::Texture p_jasne,p_ciemne,ps_jasne,ps_ciemne,czerwony,niebieski;   //wczytywanie tekstur
        p_jasne.loadFromFile("tekstury/pola/jasna.bmp");
        p_ciemne.loadFromFile("tekstury/pola/ciemna.bmp");
        ps_jasne.loadFromFile("tekstury/pola/jasny_pod.bmp");
        ps_ciemne.loadFromFile("tekstury/pola/ciemny_pod.bmp");
        czerwony.loadFromFile("tekstury/pionki/czerwony.png");
        niebieski.loadFromFile("tekstury/pionki/niebieski.png");

        for(int x=0;x<8;x++) {
        for(int y=0;y<8;y++) {
        if(board[x][y]==1){
        plansza.setTexture( p_ciemne );
        odn_okna->draw(plansza);
        plansza.move(sf::Vector2f(0,85));
        }
          else if(board[x][y]==2) {
            plansza.setTexture( p_jasne );
            odn_okna->draw(plansza);
            plansza.move(sf::Vector2f(0,85));
          }
          else if(board[x][y]==3) {
          plansza.setTexture( p_ciemne );
          odn_okna->draw(plansza);
            plansza.setTexture( czerwony );
            odn_okna->draw(plansza);
            plansza.move(sf::Vector2f(0,85));
          }
          else if(board[x][y]==4) {
            plansza.setTexture( p_ciemne );
            odn_okna->draw(plansza);
            plansza.setTexture( niebieski );
            odn_okna->draw(plansza);
            plansza.move(sf::Vector2f(0,85));
          }
          else if(board[x][y]==5) {
            plansza.setTexture( ps_ciemne );
            odn_okna->draw(plansza);
            plansza.move(sf::Vector2f(0,85));
          }
          else if(board[x][y]==6) {
            plansza.setTexture( ps_ciemne );
            odn_okna->draw(plansza);
            plansza.setTexture( niebieski );
            odn_okna->draw(plansza);
            plansza.move(sf::Vector2f(0,85));
          }
          else if(board[x][y]==7) {
            plansza.setTexture( p_ciemne );
            odn_okna->draw(plansza);
            plansza.setTexture( czerwony );
            odn_okna->draw(plansza);
            plansza.move(sf::Vector2f(0,85));
          }
        }
        plansza.move(sf::Vector2f(85,-680));
        }

}

