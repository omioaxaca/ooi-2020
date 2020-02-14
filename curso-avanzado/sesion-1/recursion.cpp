// Recursion: Es una funcion que ejecuta las mismas instrucciones
//            sobre estados diferentes.
//            Es una funcion que se llama a si misma para ejecutar
//            instrucciones.

// Partes de la recursion:
// Caso base (caso de paso):
// Una respuesta ya conocida para el problema
// y que permite que la recursin acabe.
//
// Caso general (paso recursivo):
// La condicion que hace que la funcion sea recursiva
// y permite el cambio de un estado a otro.
//
// Estado:
// Un conjunto de variables que describen
// la situacion del problema, funcion, objeto con
// el que se este trabajando.

#include <iostream>

using namespace std;

// Funcion que calcula la sumatoria
// de los numeros del 1 al n
// Ejemplo:
// f(5)  = 15
// f(10) = 55
int f(int n) {
    // Verificar si estamos en el caso base.
    // El caso base es cuando n = 1 y la respuesta es 1
    if (n == 1) {
        return 1;
    }
    // Hacer la llamada recursiva.
    else if(n > 1) {
        int resultado = n + f(n - 1);
        return resultado;
    }
}

int main() {
    int x;
    cin >> x;
    cout << f(x) << "\n";

    return 0;
}