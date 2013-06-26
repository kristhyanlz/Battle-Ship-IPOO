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

void Fichero::agregarDatos(string text){
    text += "\n";
    string line, acum;
    getline(read, line);
    acum = line;
    acum += "\n";

    while(read.good()){
        getline(read, line);
        acum += line;
        acum += "\n";
    }

    acum[acum.length() - 1] = '\0';

    clearf();

    write << text;
    write << acum;
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


void Fichero::copyTo(string raiz)
{
    file = new char[raiz.length() + 1];

    for(register int i = 0; i <= raiz.length(); ++i)
        file[i] = raiz[i];

    //file[raiz.length()] = '\0';
}

