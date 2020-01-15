// Divisor: Un numero que puede dividir a otro de forma exacta
// Por ejemplo:
// Los divisores de 10 son: 1, 2, 5 y 10
// Operacion    Resultado   Residuo 
// 10 / 1       10          0
// 10 / 2       5           0
// 10 / 5       2           0
// 10 / 10      1           0

// Un numero primo es aquel que solo tiene 2 divisores, que son el 1 y él mismo.
// Por ejemplo:
// 17, sus divisores son 1 y el 17.

// Programa para saber si un numero es primo
#include <iostream>

using namespace std;

int main() {
    int numero = 0;
    // Leer el valor de numero
    cin >> numero;
    // Ciclo desde 1 hasta el valor del numero, que nos
    // sirve para contar cuantos divisores tiene el numero
    int divisores = 0;
    for(int i = 1; i <= numero; i++) {
        // Si el residuo de la division de numero entre i es 0,
        // entonces i es un divisor de numero
        if (numero % i == 0) {
            divisores++;
        }
    }
    cout << "Divisores: " << divisores << "\n";
    // Si la cantidad de divisores es 2,
    // entonces numero es primo.
    if (divisores == 2) {
        cout << "Es primo\n";
    }
    else {
        cout << "No es primo\n";
    }


    return 0;
}