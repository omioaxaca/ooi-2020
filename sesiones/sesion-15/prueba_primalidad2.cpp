// Programa para saber si un numero es primo
#include <iostream>

using namespace std;

// Funcion para saber si un numero es primo.
// Regresa true si es primo.
// Regresa false si no es primo.
bool esPrimo(int n) {
    // Ciclo desde 1 hasta el valor del numero, que nos
    // sirve para contar cuantos divisores tiene el numero
    int divisores = 0;
    for(int i = 1; i <= n; i++) {
        // Si el residuo de la division de numero entre i es 0,
        // entonces i es un divisor de numero
        if (n % i == 0) {
            divisores++;
        }
    }
    // Si la cantidad de divisores es 2,
    // entonces numero es primo.
    if (divisores == 2) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    int numero = 0;
    // Leer 10 numeros
    for (int i = 0; i < 10; i++) {
        cin >> numero;
        
        bool resultado;
        resultado = esPrimo(numero);
        if(resultado == true) {
            cout << "Es primo" << "\n";
        }
        else {
            cout << "No es primo" << "\n";
        }
    }

    return 0;
}