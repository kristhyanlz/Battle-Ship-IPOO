#include "player.h"

Player::Player():id(sello){
    ++sello;
}

Player::~Player()
{
    for (register int idx = 0; idx < 2; ++idx){
        for (register int i = 0;i < tam; ++i ){
            delete [] tabla[idx][tam - 1] ;
        }
        delete [] tabla[idx];
    }

}

void Player::crear(int n){// void ini() // Metodo
    if (n < 10)
        n = 10;

    tam = n;

    for(register int idx = 0; idx < 2 ; ++idx ){
        tabla[idx] = new int * [n];
        for (register int j = 0; j < n; ++j)
            tabla[idx][j] = new int [n];

        for (register int j = 0; j < tam; ++j){
            for (int k = 0; k < tam; ++k)
                tabla[idx][j][k] = 0;
        }
    }

    nRestantes = 6;
}

void Player::imprimirTablero(bool idx){
    for (register int i = 0; i < tam; ++i){
        cout << endl;
        for (register int j = 0; j < tam; ++j){
            //if (not tabla[idx][i][j])
                //cout << "W";
            switch (tabla[idx][i][j]){
                case 0: cout << "  ";
                        break;

                //case 0: cout << "  ";
                        //break;

                case 1: cout << " O";
                        break;

                case 2: cout << " x";
                        break;

                case 3: cout << " -";
                        break;

            }
        }
    }
    cout << endl;

}

bool Player::pose(int a, int b, bool idx){
    --a; --b;
    int cond = (int(idx)) + 1;
    if ( (tabla[0][a][b] == cond) or (tabla[0][a][b] == (cond + 1) ) )
        return false;



    tabla[0][a][b] = (tabla[0][a][b] == idx)? cond : cond + 1;

    if (tabla[0][a][b] == 2)
        --nRestantes;

    return true;
}

bool Player::pintar(){
    cout << "Ubique sus naves " << name << ": \n";
    int a[3][2];
    bool check = false;

    char temp[2][3];//Una cordenada

        cout << "\nIngrese posicion del bote: ";
        //cin >> a[0][0];
        cin >> temp[0];
        cin >> temp[1];

        a[0][0] = atoi(temp[0]);
        a[0][1] = atoi(temp[1]);

        if ( ( not a[0][0]) or (not a[0][1]) ){
            restart();
            return false;
        }

        pose(a[0][0] , a[0][1] );

    while(not check){
        cout << "\nIngrese posicion del buque: ";
        cin >> temp[0];
        cin >> temp[1];

        a[0][0] = atoi(temp[0]);
        a[0][1] = atoi(temp[1]);

        if ( (not a[0][0]) or (not a[0][1]) ){
            restart();
            return false;
        }
        bool n = pose(a[0][0] , a[0][1] );

        cout << "\Ingrese posicion: ";
        cin >> temp[0];
        cin >> temp[1];

        a[1][0] = atoi(temp[0]);
        a[1][1] = atoi(temp[1]);

        if (not (a[1][0]) or (not a[1][1]) ){
            restart();
            return false;
        }
        n = n and pose(a[1][0], a[1][1]);

        check =  ( (a[0][0] == a[1][0]) or (a[0][1] == a[1][1]) ) and n;
        if(not check){
            for (register int i = 0; i < 2; ++i)
                tabla[0][ (a[i][0] - 1) ][ (a[i][1] - 1) ] = 0;
            cout << "\nLo que ha ingresado es incorrecto";
            Sleep(2000);
            system("cls");
        }
    }

    check = false;

    while(not check){

        cout << "\nIngrese posicion del porta aviones: ";
        cin >> temp[0];
        cin >> temp[1];

        a[0][0] = atoi(temp[0]);
        a[0][1] = atoi(temp[1]);

        if ( (a[0][0] < 1) or (a[0][1] < 1) ){
            restart();
            return false;
        }
        bool n = pose(a[0][0] , a[0][1] );

        cout << "Ingrese posicion: ";
        cin >> temp[0];
        cin >> temp[1];

        a[1][0] = atoi(temp[0]);
        a[1][1] = atoi(temp[1]);

        n = n and pose(a[1][0], a[1][1]);

        if ( (not a[1][0]) or (not a[1][1]) ){
            restart();
            return false;
        }

        cout << "Ingrese posicion: ";
        cin >> temp[0];
        cin >> temp[1];

        a[2][0] = atoi(temp[0]);
        a[2][1] = atoi(temp[1]);
        n = n and pose(a[2][0], a[2][1]);

        check = (((a[0][0] == a[1][0]) and (a[0][0] == a[2][0]) ) or ((a[0][1] == a[1][1]) and (a[0][1]) == a[2][1]) ) and n;

        if (not check){
            for (register int i = 0; i < 3; ++i)
                tabla[0][ (a[i][0] - 1) ][ (a[i][1] - 1) ] = 0;
            cout << "\nLo que ha ingresado es incorrecto";
            Sleep(2000);
            system("cls");
        }
    }
    return true;
}

void Player::restart(bool idx){
    for (register int j = 0; j < tam; ++j){
            for (int k = 0; k < tam; ++k)
                tabla[idx][j][k] = 0;
    }
}

//Fichero Player::records = "mono.txt";

int Player::sello = 0;
