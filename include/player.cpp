#include "player.h"

Player::Player():id(sello), ini(false)
{
    ++sello;
    stUnidad = 1;
}

Player::~Player()
{
    for (;tam; --tam ){
        delete [] *(tabla + tam-1) ;
    }
    delete [] tabla;
}

void Player::crear(int n){
    if (n < 10){
        n = 10;
    }

    tam = n;
    ini = true;
    //name = name_;
    tabla = new int * [n];
    for (register int i = 0; i < n; ++i)
        tabla[i] = new int [n];

    for(register int i = 0; i < tam; ++i){
        for (int j = 0; j < tam; ++j)
            tabla[i][j] = 0;
    }

    for (;n > 10; n = n - 5){
        ++ stUnidad;
    }

    nRestantes = stUnidad + (stUnidad << 1) + (stUnidad* 3);
}

bool Player::atacado(int & a, int & b){
    if (tabla[a][b] == 1){
        tabla[a][b] = 2;
        --nRestantes;
    }

    return bool (nRestantes);
}

void Player::imprimirTablero(){
    for (int i = 0; i < tam; ++i){
        cout << endl;
        for (int j = 0; j < tam; ++j){
            if (not tabla[i][j])
                //cout << "W";
            switch (tabla[i][j]){
                case 0: cout << " ";
                        break;

                case 1: cout << "O";
                        break;

                case 2: cout << "x";
                        break;

            }
        }
    }

}

bool Player::pose(int & a, int & b){
    if (tabla[a][b] == 1)
        return false;
    tabla[a][b] = (tabla[a][b] == 0) ? 1 : 1;
    return true;
}

void Player::pintar(){
    int a[2];
    int b[2];
    int c[2];
    bool check = false;

    cout << "Ingrese posicion: ";
    cin >> a[0];
    cin >> a[1];
    pose(a[0], a[1]);

    while(not check){
        cout << "Ingrese posicion: ";
        cin >> a[0];
        cin >> a[1];
        bool n = pose(a[0] , a[1] );
        cout << "Ingrese posicion: ";
        cin >> b[0];
        cin >> b[1];
        bool m = pose(b[0], b[1]);
        check = ( (a[0] == b[0]) or (a[1] == b[1])) ?  true : false;
        check = n and m;
    }

    check = false;

    while(not check){
        cout << "Ingrese posicion: ";
        cin >> a[0];
        cin >> a[1];
        bool n = pose(a[0], a[1]);
        cout << "Ingrese posicion: ";
        cin >> b[0];
        cin >> b[1];
        bool m = pose(b[0], b[1]);
        check = ( (a[0] == b[0]) or (a[1] == b[1])) ?  true : false;
        check = n and m;
        cout << "Ingrese posicion: ";
        cin >> c[0];
        cin >> c[1];
    }

}

int Player::sello = 0;
