#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
//#include <unistd.h>
#include <windows.h>
#include "fichero.h"

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

        friend void login();
    protected:
    private:
        Fichero records;
        string name;
        int tam, id, **tabla, nRestantes;
        static int sello;
        bool ini;
};

#endif // PLAYER_H
