// Buscar parejas de elementos cuya suma sea k e imprimir la cantidad de parejas.
// a + b = k
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n; // cantidad de elementos
    int k; // suma
    cin >> n;
    cin >> k;
    vector<int> numeros(n);

    map<int, int> cubeta; // Guardar la frecuencia con que aparece cada numero. valor -> frecuencia
    

    int parejas = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        int b = k - a; // a + b = k, al despejar b se obtiene b = k - a
        parejas += cubeta[b];
        cubeta[a]++;
    }
    cout << parejas << "\n";


    return 0;
}