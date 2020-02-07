// Encontrar la suma de numeros contigua mas grande dentro del arreglo
// Entrada son numeros enteros positivos y negativos
// Ejemplo: [1, 2, 3, 4, -10]
// Salida: 10

// Ejemplo: 1, 4, -7, 9, -1, 3, 5
// Salida: 16

// Ejemplo: -2, 1, -3, 4, -1, 2, 1, -5, 4
// Salida:  6


#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    // Leer la cantidad de numeros
    int cantidadNumeros;
    cin >> cantidadNumeros;
    // Leer los numeros
    vector<int> numeros(cantidadNumeros);
    for (int i = 0; i < cantidadNumeros; i++) {
        cin >> numeros[i];
    }

    int j = cantidadNumeros;
    int sumaMayor = INT_MIN;
    int sumaActual = 0;
    // Sumar todos los numeros, pero reiniciar la suma a 0
    // cada vez que se vuelva negativa. En cada paso, verificar
    // si la suma actual es mayor que sumaMayor
    for (int i = 0; i < j; i++) {
        sumaActual += numeros[i];
        if(sumaActual > sumaMayor) {
            sumaMayor = sumaActual;
        }
        if (sumaActual < 0) {
            sumaActual = 0;
        }
    }

    cout << sumaMayor << "\n";

    return 0;
}