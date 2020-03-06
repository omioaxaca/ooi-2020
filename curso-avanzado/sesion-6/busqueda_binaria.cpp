// $1 a que adivino un numero entero entre 0 y 100 con menos de 7 pistas
//
// 1. [0  100] 50 mayor
// 2. [51 100] 75 mayor
// 3. [76 100] 88 menor
// 4. [76  87] 82 menor
// 5. [76  81] 79 menor
// 6. [76  78] 77 Correcto!

// Busqueda binaria
// Se tiene un arreglo ordenado de menor a mayor y se quieren buscar k elementos.
#include <iostream>
#include <vector>

using namespace std;
//                 0  1  2  3  4  5   6    7
vector<int> arr = {1, 3, 4, 7, 8, 11, 20, 23};

// Complejidad O(n)
bool busqueda_lineal(int x) {
    for (int i = 0; i < arr.size(); i++) {
        if(x == arr[i]) {
            return true;
        }
    }
    return false;
}

// Complejidad O(log2n)
bool busqueda_binaria(int inicio, int fin, int x) {
    // Verificar que estemos en un rango correcto.
    if (inicio > fin) return false;
    // Calcular la mitad del rango.
    int mitad = (inicio + fin) / 2;
    // Comprobar si la mitad contiene el numero que busco.
    if( x == arr[mitad]) return true; // Lo encontre!
    // Buscar en el rango superior o inferior, dependiendo
    // de si x es mayor o menor que la mitad.
    if( x < arr[mitad]) {
        return busqueda_binaria(inicio, mitad - 1, x);
    }
    else { // x es mayor
        return busqueda_binaria(mitad + 1, fin, x);
    }
}

int main() {
    int k = 5;
    int x;

    for (int i = 0; i < k; i++) {
        cin >> x;
        cout << "Busqueda lineal: "  << busqueda_lineal(x);
        cout << "Busqueda binaria: " << busqueda_binaria(0, arr.size() - 1, x);
    }

    return 0;
}