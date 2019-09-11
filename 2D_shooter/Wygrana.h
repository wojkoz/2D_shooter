#ifndef WYGRANA_H
#define WYGRANA_H


class Wygrana
{
    public:
        void Kto_wygrywa(int ORYGINAL[8][8],int KOPIA[8][8],int &tura,int &ilosc_gracza,int &ilosc_komputera);
    private:
        int aktualnag,aktualnak;
        int punkty_gracza=0,punkty_komputera=0;
        int gracz_wygral=0,komputer_wygral=0;
};

#endif // WYGRANA_H
