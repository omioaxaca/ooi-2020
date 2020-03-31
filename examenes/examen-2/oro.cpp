#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Calcular todas las sumas posibles
void f(int pos, int suma, vector<int>& valores, int& objetivo, int& resultado) {
    // Casos bases
    // Caso donde la suma ya alcanzo el objetivo
    if (suma >= objetivo) {
        int exceso = suma - objetivo;
        // si la suma que encontre, es menor que el resultado
        // que ya tenia guardado, entonces esta suma es mejor
        // asi que actualizamos el resultado
        if (exceso < resultado) {
            resultado = exceso;
        }
        return;
    }
    // Caso donde pos esta fuera de los limites
    // del vector, asi que terminar la recursion.
    if (pos >= valores.size()) {
        // terminar la recursion
        return;
    }

    // Pasos recursivos
    // Incluir el elemento actual en la suma.
    f(pos + 1, suma + valores[pos], valores, objetivo, resultado);
    // No incluir el elemento actual en la suma.
    f(pos + 1, suma, valores, objetivo, resultado);
}

int main() {
    int cantidad;
    int objetivo;
    // Leer la cantidad de valores y el objetivo
    cin >> cantidad >> objetivo;
    // Leer los valores (cantidades de oro)
    vector<int> valores(cantidad);
    for (int i = 0; i < cantidad; i++) {
        cin >> valores[i];
    }

    // Llamar a la funcion para calcular todas
    // las sumas posibles que sean mayores o iguales al objetivo.
    int resultado = INT32_MAX;
    f(0, 0, valores, objetivo, resultado);

    cout << resultado << "\n";
    


    return 0;
}