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
                case 0: cout << "  ";
                        break;

                case 1: cout << " O";
                        break;

                case 2: cout << " x";
                        break;

            }
        }
    }
    cout << endl;

}

bool Player::pose(int & a, int & b){
    --a; --b;
    if (tabla[a][b] == 1)
        return false;

    tabla[a][b] = 1;
    return true;
}

bool Player::pintar(){
    int a[3][2];
    bool check = false;

    char temp[2][2];//Una cordenada

        cout << "Ingrese posicion del bote: ";
        //cin >> a[0][0];
        cin >> temp[0];
        cin >> temp[1];

        a[0][0] = atoi(temp[0]); a[0][1] = atoi(temp[1]);

        if ( (a[0][0] < 1) or ( a[0][1] < 1) )
            return false;
        pose(a[0][0], a[0][1]);

    while(not check){
        cout << "Ingrese posicion del buque: ";
        cin >> temp[0];
        cin >> temp[1];

        a[0][0] = atoi(temp[0]); a[0][1] = atoi(temp[1]);

        if ( (a[0][0] < 1) or (a[0][1] < 1) )
            return false;
        bool n = pose(a[0][0] , a[0][1] );

        cout << "Ingrese posicion: ";
        cin >> temp[0];
        cin >> temp[1];

        a[1][0] = atoi(temp[0]);
        a[1][1] = atoi(temp[1]);

        if ( (a[1][0] < 1) or (a[1][1] < 1) )
            return false;
        n = n and pose(a[1][0], a[1][1]);

        check = ( ( (a[0][0] == a[1][0]) or (a[0][1] == a[1][1]) ) ?  true : false) and n;
        if(not check){
            cout << "\nLo que ha ingresado es incorrecto";
            Sleep(2000);
            system("cls");
        }
    }

    check = false;

    while(not check){

        cout << "Ingrese posicion del porta aviones: ";
        cin >> temp[0];
        cin >> temp[1];

        a[0][0] = atoi(temp[0]);
        a[0][1] = atoi(temp[1]);

        if ( (a[0][0] < 1) or (a[0][1] < 1) )
            return false;
        bool n = pose(a[0][0] , a[0][1] );

        cout << "Ingrese posicion: ";
        cin >> temp[0];
        cin >> temp[1];

        a[1][0] = atoi(temp[0]);
        a[1][1] = atoi(temp[1]);
        n = n and pose(a[1][0], a[1][1]);

        if ( (a[1][0] < 1) or (a[1][1] < 1) )
            return false;

        cout << "Ingrese posicion: ";
        cin >> temp[0];
        cin >> temp[1];

        a[2][0] = atoi(temp[0]);
        a[2][1] = atoi(temp[1]);
        n = n and pose(a[2][0], a[2][1]);
        check = (check and (( (a[0][0] == a[2][0]) or (a[0][1] == a[2][1])) ?  true : false) ) and n;

        if (not check){
            cout << "\nLo que ha ingresado es incorrecto";
            Sleep(2000);
            system("cls");
        }
    }
    return true;
}

int Player::sello = 0;
