#include "fichero.h"

Fichero::Fichero(string _file){
    ini(_file);
}

Fichero::Fichero(){}

Fichero::~Fichero(){
    delete []file;
    write.close();
    read.close();
}

void Fichero::restart()
{
    write.close();
    read.close();
    ini(file);
}

void Fichero::clearf()
{
    ofstream tmp(file);
    restart();
}

void Fichero::copyTo(string raiz)
{
    int tam;
    for(tam = 0; raiz[tam]; tam++){}

    file = new char[tam + 1];

    for(int i = 0; i <= tam; i++)
        file[i] = raiz[i];

    file[tam] = '\0';
}

void Fichero:: ini(string  __file)
{
    copyTo(__file);

    if (write.is_open())
        write.close();

    write.open(file);

    if(not write.is_open())
    {
        ofstream tmp(file);
        write.open(file);
    }
    read.open(file);
}
