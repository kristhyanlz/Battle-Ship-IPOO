#ifndef INTERFAZ_H_INCLUDED
#define INTERFAZ_H_INCLUDED
#include "player.h"

//#include <iostream>
//#include <string.h>
//#include <windows.h>
//#include <stdlib.h>

//using namespace std;

void impri(int n){
        cout << " [";
    for(;n;--n){
        cout << "#";
    }
    cout << "]  Loading...";
}

void cargando(){
    for(int i = 0; i < 11; ++i){
        cout << '\r' << i * 10;
        impri(i);
        Sleep(560);
        system("cls");
    }
    cout << "Carga completa!";
    Sleep(1500);
    system("cls");
}

Player play[2];
Fichero records;

bool start(){
    records.ini("records.txt");

    Sleep(1700);
    system("cls");
    cout << "\n===========================================================" << endl;
    cout << "\n##-- B I E N V E N I D O S   A   B A T T L E   S H I P --##" << endl;
    cout << "\n===========================================================" << endl;

    cout << "\nIngrese el tamanio del tablero de juego: ";


    char tam[3];
    cin >> tam;

    int tam_ = atoi(tam);
    if ( (tam_ > 40) or (not tam_) ){
        system("cls");
        cout << "Lo ingresado es incorrecto\n";
        return false;
    }

    play[0].crear(tam_);
    play[1].crear(tam_);

    system("cls");
    return true;

}

void login(){
    cout << "Ingrese el nombre del Jugador 1: ";
    cin >> play[0].name;
    cout << "Ingrese el nombre del Jugador 2: ";
    cin >> play[1].name;
    system("cls");
}

string itostr(int a){
    string rp;
    string temp[3];

    temp[0] = ((a%10) + 48);
    temp[1] = 48;
    temp[2] = 48;

    for(register int i = 1;a;++i){
        temp[i] = ((a%10) + 48);
        a = a/10;
    }
    rp = temp[2] + temp[1] + temp[0];
    return rp;
}

void game(){

    int cont = 0;
    ++cont;
    for (register int i = 0; i < 2; ++i){
        cout << "  " <<play[0].name << "  Vs.\n" << "  " << play[1].name << "\n===========================================================\n" ;
        while (not play[i].pintar()){}
        play[i].imprimirTablero();
        Sleep(2000);
        system("cls");
    }
    bool turno = false;
    while (play[turno].nRestantes){/// Poner
        play[turno].imprimirTablero(true);
        char temp[2][3];//Una cordenada
        int coor[2];
        cout << "  " <<play[0].name << "  Vs.\n" << "  " << play[1].name << "\n===========================================================\n" ;
        cout << "Es el turno de " << play[turno].name << " :\n";

        cin >> temp[0];
        cin >> temp[1];

        coor[0]= atoi(temp[0]);
        coor[1] = atoi(temp[1]);

        if ( (( not coor[0]) or (not coor[1])) or (not play[not turno].pose(coor[0], coor[1], true)))
            continue;

        play[turno].tabla[1][(coor[0])][(coor[1])] = play[not turno].tabla[1][(coor[0])][(coor[1])];

        turno = not turno;
        ++cont;
        system("cls");
    }
    string texto = play[not turno].name;
    texto += "  Gano! en: ";
    texto += itostr(cont);
    texto += " turnos.";
    records.agregarDatos(texto);
    cout << texto << endl; // GANO!


}


#endif // INTERFAZ_H_INCLUDED
