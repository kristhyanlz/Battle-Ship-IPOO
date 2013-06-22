#include "player.h"

Player::Player():id(sello), ini(false)
{
    ++sello;
    stLancha = stBuque = stPortaAviones = 1;
}

Player::~Player()
{
    //dtor
}

void Player::crear(int n){
    if (n < 10)
        n = 10;

    for (;n > 10; n = n - 5){
        ++stLancha; ++stBuque; ++stPortaAviones;
    }

    tam = n;
    ini = true;
    //name = name_;
    tabla = new int * [n];
    for (register int i = 0; i < n; ++i)
        tabla[i] = new int [n];

    for(register int i = 0; i < tam; ++i){
        for (register int j = 0; j < tam; ++j)
            tabla[i][j] = 0;
    }
}

int Player::sello = 0;
