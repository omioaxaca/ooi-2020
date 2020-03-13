#include <iostream>
#include <vector>
#include <string>
#include <map>

// Complejidad de insertar O(log2n)
// Complejidad de consultar O(log2n)

using namespace std;

int main() {
    vector<string> palabras = {"Daniel", "viene", "a", "Oaxaca", "a", "visitar", "a", "Nicolas", "la", "proxima", "semana", "pero", "Nicolas", "no", "estara"};
    // Un map de la STL nos permite guardar elementos utilizando una llave unica y
    // asignar un valor dentro para esa llave.
    // map < LLAVE, VALOR>
    // map < TIPO_DE_DATO, VALOR_QUE_GUARDA >
    map<string, int> frecPalabras;
    for (int i = 0; i < palabras.size(); i++) {
        frecPalabras[palabras[i]]++;
    }

    for (int i = 0; i < palabras.size(); i++) {
        cout << palabras[i] << " : " << frecPalabras[palabras[i]] << "\n";
    }


    return 0;
}