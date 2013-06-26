#ifndef FICHERO_H
#define FICHERO_H

#include <iostream>
#include <unistd.h>// Aqui se encuentra la funcion: sleep(int);
//#include <lib for sleep>
//#include <windows.h>
#include <stdlib.h>// Aqui se encuentra la funcion: system("pause")
#include <string>
#include <fstream>
using namespace std;

class Fichero
{
    public:
        Fichero(string _file);
        Fichero();
        virtual ~Fichero();
        fstream write;
        ifstream read;
        void agregarDatos(string text);
        void restart();
        void clearf();
        void ini(string  __file);
        //void hide(string & txt);
    protected:
        int lv;

    private:
        char * file;
        void copyTo(string raiz);

};

#endif // FICHERO_H
