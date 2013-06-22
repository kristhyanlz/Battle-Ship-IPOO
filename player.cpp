#include "player.h"

Player::Player():id(sello), ini(false)
{
    ++sello;
}

Player::~Player()
{
    //dtor
}

void Player::crear(int n): ini(true){
    tabla = new int * n;
    for (register int i = 0; i < n; ++i)
        tabla[i] = new int n;
}

int Player::sello = 0;
