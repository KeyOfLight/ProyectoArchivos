#include "Rmdisk.h"

bool Rmdisk::eliminarDisco(string path) {

    string opcionEliminar = "n";

    cout << endl << "Desea eliminar el disco ? (s/n)" ;
    cin >> opcionEliminar;

    if (opcionEliminar == "s" || opcionEliminar == "S") {
        if (remove(path.c_str()) == 0) {
            cout << endl << " *** Disco eliminado exitosamente ***" << endl << endl;
            return true;
        } else {
            cout << endl << " *** Disco no existente ***" << endl << endl;
            return false;
        }
    }

    if (opcionEliminar == "n" || opcionEliminar == "N") {
        cout << endl << " *** Eliminacion del disco cancelada ***" << endl << endl;
        return false;
    }

    cout << endl << " *** No se reconoce la opcion indicada ***" << endl << endl;

    return false;


}