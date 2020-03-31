#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Calcular todas las sumas posibles y regresar la menor que sea mayor
// que el objetivo.
int f(int pos, int suma, vector<int>& valores, int& objetivo) {
    // Casos bases
    // Caso donde la suma ya alcanzo el objetivo
    if (suma >= objetivo) {
        int exceso = suma - objetivo;
        return exceso;
    }
    // Caso donde pos esta fuera de los limites
    // del vector, asi que terminar la recursion.
    if (pos >= valores.size()) {
        // Caso invalido, por lo tanto debe regresar un valor invalido.
        return INT32_MAX;
    }

    // Pasos recursivos
    // Incluir el elemento actual en la suma.
    int resultado1 = f(pos + 1, suma + valores[pos], valores, objetivo);
    // No incluir el elemento actual en la suma.
    int resultado2 = f(pos + 1, suma, valores, objetivo);
    if (resultado1 < resultado2) {
        return resultado1;
    }
    else {
        return resultado2;
    }
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
    int resultado = f(0, 0, valores, objetivo);

    cout << resultado << "\n";
    


    return 0;
}