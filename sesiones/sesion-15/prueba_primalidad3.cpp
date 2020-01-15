// Programa para saber si un numero es primo
#include <iostream>

using namespace std;

// Funcion para saber si un numero es primo.
// Regresa true si es primo.
// Regresa false si no es primo.
bool esPrimo(int n) {
    // Ciclo que va desde 2 hasta n-1 y busca un divisor
    // Si encuentra alguno, significa que n no es primo
    for(int i = 2; i < n; i++) {
        // Si encontramos un divisor, regresamos false porque
        // no es primo.
        if (n % i == 0) {
            return false;
        }
    }
    // Si llegamos hasta este punto, significa que no encontramos
    // ningun divisor en en rango de 2 a n-1, por lo que n es primo.
    return true;
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