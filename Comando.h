#ifndef COMANDO_H
#define COMANDO_H

#include <fstream>
#include <cstdio>
#include <iostream>
#include "stdlib.h"
#include <ctime>
#include <cstdlib>
#include <string>
#include <string.h>
#include <ctime>


using namespace std;

typedef struct{
    string Comando = " ";
    string Tamano = " ";
    string Dimensional = " ";
    string Id = " ";
    string Nombre = " ";
    string Direccion = " ";
    string FitType = " ";
    string PartType = " ";
    string Delete = " ";
    string Add = " ";
}Parametros;

typedef struct{
    int id;
    char nombre[15];
    int telefono;
    char direccion[15];
} Ejemplo;

class Comando{
    public:
        Parametros param;
        Mount Montar;
        void identificacionCMD(Parametros p);
        bool crearArchivo(string tam, string dim, string fittype,string dir);
        void escribir(string id, string nombre, string tel, string dir, string x);
        void Mount(string path, string Name);
        void vertodo();
        void verX(string x);
        void eliminarX(string x);
        void mostrar_struct(Ejemplo ejm);
        void exec(string dir);
        int fDisk(string size, string unit, string path, string PartType, string fittype, string del, string addition ,string name);
        void MKdisc();

};

#endif // COMANDO_H