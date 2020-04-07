#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

int main() {
    vector<int> datos =  {1, 5, 9, 2, 4, 3, 6, 10, 8, 7, 1, 5, 6, 6, 7};
    set<int> mi_set;

    // Insertar los datos en el set.
    // Utilizar un for de C++11, conocido como foreach
    // Solo se puede utilizar el foreach con estructuras que tengan
    // un begin() y un end()
    for(int dato : datos) {
        mi_set.insert(dato);
    }

    // Utilizar un for de C++11 para recorrer el set
    for(int dato : mi_set) {
        cout << dato << " ";
    }
    cout << "\n";

    // Cambiar el valor de todos los datos en el vector por 1
    // int idx = 0;
    // while (idx < datos.size()) {
    //     int& x = datos[idx];
    //     x = 1; // datos[idx] = 1;
    //     idx++;
    // }
    for (int& x : datos) {
        x = 1;
    }

    // Imprimir los valores del vector
    for (auto x : datos) {
        cout << x << " ";
    }
    cout << "\n";

    string palabra = "Daniel";
    for (auto letra : palabra) {
        cout << letra << " ";
    }

    return 0;
}