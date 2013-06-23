#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <unistd.h>
#include <windows.h>
//#include <stdlib.h>

using namespace std;

class Player
{
    public:
        Player();
        virtual ~Player();
        void crear(int n);
        bool atacado(int & a, int & b);
        bool pose(int & a, int & b);
        void imprimirTablero();
        bool pintar();

        friend void startGame();
    protected:
    private:
        string name;
        int tam, id, **tabla, nRestantes;
        int stUnidad;
        static int sello;
        bool ini;
};

#endif // PLAYER_H
