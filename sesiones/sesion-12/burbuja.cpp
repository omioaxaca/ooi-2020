#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Función alternativa para decir bajo que criterio vamos a ordenar
int compare(int a, int b) {
    return a > b;
}


int main() {
    vector<int> array = {5, 1, 4, 2, 8};

    // Algoritmo Burbuja no es tan eficiente

    // Hacemos las iteraciones necesarias para asegurar que
    // todo le vector esté ordena
    for (int j = 0; j < array.size() - 1; j++) {
        // Pivotear el número más grande sin ordenar
        // hasta su posición
        for (int i = 0; i < array.size() - 1 - j; i++) {
            // Intercambiar si el número siguiente es menor
            // al actual
            if (array[i] > array[i+1]) {
                int tmp = array[i];
                array[i] = array[i+1];
                array[i+1] = tmp;
            }
        }
    }

    // // Ordenando con algoritmo de la STL, muy eficiente
    sort(array.begin(), array.end(), compare);

    for (int i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }
    cout << endl;


    return 0;
}
