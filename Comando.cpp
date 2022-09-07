#include "Comando.h"
#include "Mkdisk.h"
#include "Rmdisk.h"
#include "Fdisk.h"
#include "Mount.h"

#include <vector>

void Comando::identificacionCMD(Parametros p){
    if(p.Comando=="mkdisk"){ 
        if(p.Tamano != " " && p.Direccion != " "){ //
            crearArchivo(p.Tamano,p.Dimensional, p.FitType, p.Direccion);
        }else{
            cout << "Error creando Disco: Parametros obligatorios no definidos." << endl;
        }
    }else if(p.Comando=="vertodo"){
        vertodo();
    }else if(p.Comando=="execut"){
        if(p.Direccion != " "){ // ------------------------TERMINAR EL COMANDO
            
            exec(p.Direccion);
        }else{
            cout << "Error elimando x registro: Parametros obligatorios no definidos." << endl;
        }
    }else if(p.Comando=="rmdisk"){
        if(p.Direccion != " "){ //------------------------TERMINAR EL COMANDO
            eliminarX(p.Direccion);
        }else{
            cout << "Error elimando x registro: Parametros obligatorios no definidos." << endl;
        }
    }else if(p.Comando=="fdisk"){
        if(p.Tamano != " " && p.Direccion !=" " && p.Nombre != " "){ 
            fDisk(p.Tamano, p.Dimensional, p.Direccion, p.PartType, p.FitType, p.Delete, p.Add, p.Nombre);
        }else{
            cout << "Error creando la particion del disco duro" << endl;
        }
    }else if(p.Comando=="mount"){ // Se identifica el tipo de comando
        if(p.Direccion !=" " && p.Nombre != " "){ 
            Mount(p.Direccion, p.Nombre);
        }else{
            cout << "Error creando la particion del disco duro" << endl;
        }
    }                      
}

void Comando::exec(string dir){

    vector <string> lines;
    string filename("Prueba.txt");
    string line;
    Parametros param;

    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << filename << "'" << endl;
        cout << "tamano: " << endl;
    }

    while (getline(input_file, line)){
        lines.push_back(line);
    }

    for (const auto &i : lines){
        param.Comando = i;
        identificacionCMD(param);
    }

    input_file.close();
}


bool Comando::crearArchivo(string tam, string dim, string fittype ,string dir){
    int size_file = 0;

    size_file = tamao(tam, dim);

    Mkdisk mkdisk;
    return mkdisk.crearDisco(size_file, dir);



}


void Comando::escribir(string id, string nombre, string tel, string dir, string x){
    FILE *archivo_binario;
    Ejemplo ejm;
    string nm = "", direc = "";
    int registros = atoi(x.c_str());

    archivo_binario = fopen("Ejemplo3.dsk", "rb+");
    for (int i = 0; i < registros; i++){
        // Seteo de parametros en Struct
        ejm.id = i + atoi(id.c_str());
        nm = nombre;
        nm += " " + to_string(ejm.id);
        strcpy(ejm.nombre, nm.c_str());
        ejm.telefono = (rand() + i) + atoi(tel.c_str());
        direc = dir;
        direc += " " + to_string(ejm.id);
        strcpy(ejm.direccion, direc.c_str());
        // Movimiento de puntero y escritura de Struct en archivo binario 
        fseek(archivo_binario, i * sizeof(Ejemplo), SEEK_SET);
        fwrite(&ejm, sizeof(ejm), 1, archivo_binario);
        nm = "";
        direc = "";
    }
    fclose(archivo_binario);
}


int Comando::fDisk(string size, string unit, string path, string partType, string fitType, string del, string addition,string name){
    
    Fdisk fdisk;
    return fdisk.administrarParticion(stoi(size), path, name, unit, partType, fitType, del, addition);
}


void Comando::vertodo(){
    FILE *archivo_binario;
    Ejemplo ejm;
    int cont = 0;
    archivo_binario = fopen("Ejemplo3.dsk", "rb+");
    while (!feof(archivo_binario)){
        // Movimiento de puntero y lectura de Struct en archivo binario 
        fseek(archivo_binario,cont*sizeof(Ejemplo), SEEK_SET);
        fread(&ejm, sizeof(ejm), 1, archivo_binario);
        mostrar_struct(ejm);
        cont++;
    }
    cont = 0;
    fclose(archivo_binario);
}

void Comando::verX(string x){
    FILE *archivo_binario;
    Ejemplo ejm;
    int xreg = atoi(x.c_str()) - 1;
    archivo_binario = fopen("Ejemplo3.dsk", "rb+");
    // Movimiento de puntero y lectura de Struct en archivo binario 
    fseek(archivo_binario, xreg * sizeof(Ejemplo), SEEK_SET);
    fread(&ejm, sizeof(ejm), 1, archivo_binario);
    mostrar_struct(ejm);
    fclose(archivo_binario);
}

void Comando::eliminarX(string dir){

    Rmdisk rmdisk;
    rmdisk.eliminarDisco(dir);
}

void Comando::Mount(string Path, string Name){

    Montar.montarParticion(Path, Name);
}

int tamao(string tam, string dim){

    int size_file = 0, tamano = atoi(tam.c_str());
    char dimen = dim.at(0);
    if (dimen == 'k' || dimen == 'K')
    {
        size_file = tamano;
    }
    else if (dimen == 'm' || dimen == 'M')
    {
        size_file = tamano * 1024;
    }
    else if (dimen == 'g' || dimen == 'G')
    {
        size_file = tamano * 1024 * 1024;
    }

    return size_file;
}

void Comando::mostrar_struct(Ejemplo ejm){
    if(ejm.id > 0 && ejm.nombre != "" && ejm.telefono > 0 && ejm.direccion != ""){
        cout << "ID: ";
        cout << ejm.id;
        cout << ", Nombre: ";
        cout << ejm.nombre;
        cout << ", Telefono: ";
        cout << ejm.telefono;
        cout << ", Direccion: ";
        cout << ejm.direccion << endl;
    }
}