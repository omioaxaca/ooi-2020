// Programa para resolver el problema: https://omegaup.com/course/Curso-OMI/assignment/COMI-PractA#problems/Normal
#include <iostream>

using namespace std;

// Funcion para imprimir los numeros desde el 1 hasta n
// Ejemplo: si n = 5, la funcion imprime 1 2 3 4
void imprime_numeros_crecientes(int n) {
    // Ciclo que va desde 1 hasta n (no inclusive)
    for (int i = 1; i < n; i++) {
        cout << i << " ";
    }
}

// Funcion para imprimir los numeros desde n hasta 1
// Ejemplo: si n = 5, la funcion imprime 5 4 3 2 1
void imprime_numeros_decrecientes(int n) {
    // Ciclo que va desde n (si inclusive) hasta 1
    for (int i = n; i >= 1; i--) {
        cout << i << " ";
    }
}

int main() {

    int n;
    cin >> n;
    imprime_numeros_crecientes(n);
    imprime_numeros_decrecientes(n);

    return 0;
}