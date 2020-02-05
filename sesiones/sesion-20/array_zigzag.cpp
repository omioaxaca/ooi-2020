// Dado un conjunto de numeros
// Tu tarea es presentarlos de tal forma que los valores queden en forma de zig zag
// o, mejor dicho que el arreglo contenga numeros crecientes y decrecientes.
// a1 >= a2 <= a3 >= a4 <= a5.....
// Ejemplo:
// Dado [1, 2, 3, 4]
// La respuesta seria: [2, 1, 4, 3]
// Tambien es valido:  [4, 1, 3, 2]
// Ejemplo 2:
// [6, 8, 1, 4, 3, 2, 5, 7]
// [3, 1, 4, 2, 7, 5, 8, 6]
// 3 > 1 < 4 > 2 < 7 > 5 < 8 > 6

// Solucion:

// 1 <= 2 <= 3 <= 4 <= 5 <= 6 <= 7 <= 8
// 2 >= 1 <= 4 >= 3 <= 6 >= 5 <= 8 >= 7
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Leer cantidad de datos
    int N;
    cin >> N;
    // Declarar un vector de tamanio N para almacenar los numeros
    vector<int> numeros(N);
    // Leer los numeros
    for (int i = 0; i < N; i++) {
        cin >> numeros[i];
    }
    // Ordenar los numeros de menor a mayor
    sort(numeros.begin(), numeros.end());
    // Intercambiar las parejas de numeros consecutivas
    for (int i = 0; i < N; i += 2) {
        // Hacer el cambio solo si aun no nos hemos salido del arreglo
        if (i + 1 < N) {
            // Intercambia los valores de las variables
            swap(numeros[i], numeros[i + 1]);
        }
    }
    for (int i = 0; i < N; i++) {
        cout << numeros[i] << " ";
    }

    return 0;
}






