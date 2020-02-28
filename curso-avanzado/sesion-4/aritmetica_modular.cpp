// Demostracion de las operaciones basicas de aritmetica modular
#include <iostream>

using namespace std;

int main() {
    // Variable para guardar el modulo;
    int m = 7;
    // Variables de ejemplo
    int a = 8;
    int b = 5;
    int c;

    // Suma
    c = a + b; // 13
    // Suma modular
    // Es lo mismo sumar todos los elementos y al final obtener el modulo m
    // que obtener el modulo de cada elemento y sumarlo y obtener el modulo al final.
    int d;
    d = (a % m + b % m) % m; // 5 + 1 = 6
    if (c % m == d) {
        cout << "La aritmetica modular funciona en sumas!\n";
    }
    // 5 + 8 = 13
    // 13 % 7 = 6

    // 10 + 15 + 22 = 47
    // 47 % 7 = 5

    // 10 % 7 = 3
    // 15 % 7 = 1
    // 22 % 7 = 1
    // 3 + 1 + 1 = 5
    // 5 % 7 = 5

    // Resta
    c = a - b;
    // Resta modular
    // Es lo mismo restar todos los elementos y al final obtener el modulo m
    // que obtener el modulo de cada elemento y restarlos y obtener el modulo al final.
    // Nota: Si en algun momento el resultado parcial se hace negativo, es necesario sumar
    // el modulo (m).                                Ejemplo
    //                                                 |
    //                                                 ↓              
    // Regla general: (a - b) % m = ((a % m - b % m) + m) % m;
    d = ((a % m - b % m) + m) % m;
    if (c % m == d) {
        cout << "La aritmetica modular funciona en restas!\n";
    }
    // 5 - 8 = (-3+7) % 7 = 4
    // 5 % 7 = 5
    // -8 % 7 = 1
    // 5 - 1 = 4
    // 4 % 7 = 4

    // Multiplicacion
    c = a * b;
    // Multiplicacion modular
    d = (a % m * b % m) % m;
    if (c % m == d) {
        cout << "La aritmetica modular funciona en multiplicaciones!\n";
    }

    // Division
    // NO SE PUEDE! Nota: En realidad si se puede, pero haciendo cosas muy raras. :(





    return 0;
}