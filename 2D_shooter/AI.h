#ifndef AI_H
#define AI_H
#include <windows.h>

class AI
{
    public:
    void ruch_komputera(int ORYGINAL[8][8],int KOPIA[8][8],int &tura);
    private:
    int prio,jnt;
};

#endif // AI_H
