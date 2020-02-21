#include <iostream>

using namespace std;

void complejidad_constante(int n) {
    int contador = 1;
    cout << contador << "\n";
}

void complejidad_lineal(int n) {
    int contador = 0;
    for (int i = 0; i < n; i++) {
        contador++;
    }
    cout << contador << "\n";
}

void complejidad_cuadratica(int n) {
    int contador = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            contador++;
        }
    }
    cout << contador << "\n";
}


int main() {
    int n = 5;
    complejidad_constante(n);
    complejidad_lineal(n);
    complejidad_cuadratica(n);

    return 0;
}