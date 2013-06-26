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

bool start(){
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

void game(){

    register int cont = 0;
    ++cont;
    for (register int i = 0; i < 2; ++i){
        cout << "  " <<play[0].name << "  Vs.\n" << "  " << play[1].name << "\n===========================================================" << endl;
        while (not play[i].pintar()){}
        play[i].imprimirTablero();
        Sleep(2000);
        system("cls");
    }



}


#endif // INTERFAZ_H_INCLUDED
