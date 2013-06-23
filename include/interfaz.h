#ifndef INTERFAZ_H_INCLUDED
#define INTERFAZ_H_INCLUDED
#include "player.h"

//#include <iostream>
//#include <string.h>
//#include <windows.h>
//#include <stdlib.h>

//using namespace std;

void impri(int n){
    cout << " Z";
    for (;n; --n){
        cout << "A";
    }
    cout << "X";
}

void cargando(){
    cout << "Kristhyan"<< endl;
    for(int i = 0; i < 10; ++i){
        cout << '\r' << i * 10;
        impri(i);
        //sleep(2);
    }
}

Player play[2];

void login(){
//    Sleep(2500);
    cout << "##-- B I E N V E N I D O S   A   B A T T L E   S H I P --##" << endl;
 //   Sleep(2500);
//    system("cls");
    cout << "\nIngrese el tamanio del tablero de juego: ";
    int tam;
    cin >> tam;
    play[0].crear(tam);
    play[1].crear(tam);

}

void startGame(){

}


#endif // INTERFAZ_H_INCLUDED
