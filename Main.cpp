#include "Analizador.cpp"

int main(){
    Analizador analisis;
    string entradacmd = "";
    while(entradacmd != "exit"){
        cout << "*----------------------------------------------------------*" << endl;
        cout << "*                      [MIA] Proyecto 1                    *" << endl;
        cout << "*----------------------------------------------------------*" << endl;
        getline(cin,entradacmd);
        analisis.analizar(entradacmd);
    }
    return 0;
}