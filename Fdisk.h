#ifndef FILESYSTEM_FDISK_H
#define FILESYSTEM_FDISK_H

#include <iostream>
#include <string>
#include <cstring>
#include "Structs.h"

using namespace std;

class Fdisk {
public:
    Fdisk();
    bool administrarParticion(int size, string path, string name, string unit, string type, string fit, string del, string add);
    bool deleteParticion(string del, string path, string name);
    bool addParticion(string add, string unit, string name, string path);
    bool createParticion(int size, string unit, string path, string name, string fit, string type);
    bool createParticionLogica(Particion particion, string path);
    void showParticiones(string path);
};


#endif //FILESYSTEM_FDISK_H
