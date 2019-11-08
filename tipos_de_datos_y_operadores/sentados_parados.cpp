// Programa para resolver el problema de Sentados o parados
// Link: https://omegaup.com/course/Curso-OMI/assignment/COMI-programacion#problems/COMI-Sentados-o-parados
#include <iostream>

using namespace std;

int main() {
    // Declarar las variables enteras
    int filas;
    int asientos;
    int boletos;

    // Leer el valor de las variables
    cin >> filas;
    cin >> asientos;
    cin >> boletos;

    // Hacer las operaciones
    int total_de_asientos = filas * asientos;
    int parados = boletos - total_de_asientos;
    int sentados = boletos - parados;

    // Imprimir el resultado
    cout << sentados << " " << parados;

    return 0;
}