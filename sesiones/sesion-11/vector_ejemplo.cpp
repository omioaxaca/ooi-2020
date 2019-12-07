#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Se indexa los elementos desde cero
    //                     0  1  2  3  4
    vector<int> numeros = {1, 2, 3, 4, 5};
    // vector<int> numeros;

    for (int i = 0; i < 5; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    cout << "El elemento 5° elemento es: " << numeros[4] << endl;
    cout << "El tamaño del vector es: " << numeros.size() << endl;

    // Agregamos más números al final del vector
    int num = 122;
    numeros.push_back(6);
    numeros.push_back(32);
    numeros.push_back(12);
    numeros.push_back(num);

    // Imprimimos los elementos hasta el tamaño del vector
    for (int i = 0; i < numeros.size(); i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    return 0;
}
