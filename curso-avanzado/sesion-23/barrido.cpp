// Buscar rangos contiguos de elementos cuya suma sea k e imprimir la cantidad de rangos.
// sumatoria(a, b) = k
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n; // cantidad de elementos
    int k; // suma
    cin >> n;
    cin >> k;

    map<int, int> cubeta; // Guardar la frecuencia con que aparece cada numero. valor -> frecuencia

    int rangos = 0;
    int sumatoria = 0; // Representa la sumatoria desde el 0
    for (int i = 0; i < n; i++) {
        int numero;
        cin >> numero;
        sumatoria += numero;
        // Dada la relacion k = sumatoria(a) - sumatoria(b)
        // Al despejar, se tiene sumatoria(b) = sumatoria(a) - k
        rangos += cubeta[sumatoria - k];
        // si el rango por si solo es igual a k, contarlo por si mismo.
        if (sumatoria == k) {
            rangos++;
        }
        cubeta[sumatoria]++;
    }
    cout << rangos << "\n";


    return 0;
}