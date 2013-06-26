#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
//#include <unistd.h>
//
#include <windows.h>
#include "fichero.h"

using namespace std;

class Player
{
    public:
        Player();
        virtual ~Player();
        void crear(int n);
        bool pose(int a, int b, bool idx = false);
        void imprimirTablero(bool idx = false);
        bool pintar();
        void restart(bool idx = false);

        friend void login();
        friend void game();

        friend void game();

    protected:
    private:
        string name;
        static int tam;
        int **tabla[2], nRestantes;// tabla[0][i][j]
};

#endif // PLAYER_H
