// Problema 1:
// Buscar el numero x en el arreglo de tamanio n
// Limites 1 <= n <= 1,000,000

// Problema 2:
// Buscar k numeros en el arreglo de tamanio n
// Limites 1 <= k <= 10,000
// Limites 1 <= n <= 1,000,000
#include <iostream>
#include <vector>

using namespace std;

bool busca_elemento(vector<int> v, int x) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == x) return true;
    }
    return false;
}

int main() {
    int n = 1000000; // Tamanio del arreglo
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = i;
    }
    int x = 999999; // Elemento a buscar
    int k = 10000;   // Numero de veces que vamos a buscar

    // Buscar k veces el numero x en el arreglo de tamanio n
    for (int i = 0; i < k; i++) {
        bool encontrado = busca_elemento(v, x); // Complejidad lineal O(n)
        // cout << encontrado << "\n";
    }
    cout << "Termine!";

    return 0;
}