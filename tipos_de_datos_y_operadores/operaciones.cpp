// Demostrar los tipos de operaciones que se pueden realizar con
// los tipos de dato entero, double y char
#include <iostream>

using namespace std;

int main() {

    // Operaciones que podemos hacer con numeros enteros
    int numero1 = 5;
    int numero2 = 3;
    int resultado = 0;

    resultado = numero1 + numero2; // 8  -> Suma
    resultado = numero1 - numero2; // 2  -> Resta
    resultado = numero1 * numero2; // 15 -> Multiplicacion
    resultado = numero1 / numero2; // 1  -> Division
    resultado = numero1 % numero2; // 2  -> Modulo (Residuo de una division entera)
                                   //       Por ejemplo: 5  % 3 = 2 
                                   //                    10 % 4 = 2

    // Operaciones con numeros con punto decimal
    double numero_decimal1 = 5.0;
    double numero_decimal2 = 3.0;
    double resultado_decimal = 0;

    resultado_decimal = numero_decimal1 + numero_decimal2; // 8.0   -> Suma
    resultado_decimal = numero_decimal1 - numero_decimal2; // 2.0   -> Resta
    resultado_decimal = numero_decimal1 * numero_decimal2; // 15.0  -> Multiplicacion
    resultado_decimal = numero_decimal1 / numero_decimal2; // 1.666 -> Division
    // resultado_decimal = numero_decimal1 % numero_decimal2; // NO SE DEBE USAR

    // Operaciones que se pueden hacer con letras
    char letra1 = '1';
    char letra2 = '2';
    char letra3;

    letra3 = letra1 + letra2; // No se deben hacer sumar con caracteres (letras)
    cin >> letra3;            // Leer
    cout << letra3;           // Imprimir



    return 0;
}