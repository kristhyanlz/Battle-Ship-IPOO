#ifndef PLAYER_H
#define PLAYER_H
#include <string.h>

class Player
{
    public:
        Player();
        virtual ~Player();
        void crear(int n);
        void atacado(int & a, int & b);
    protected:
    private:
//        string name;
        int tam, id, **tabla, nRestantes;
        int stLancha, stBuque, stPortaAviones;
        static int sello;
        bool ini;
};

#endif // PLAYER_H
