// Problema: Insertar el numero x en la posicion k
// en un arreglo circular de tamano n.
// Nota: Para este problema, un arreglo circular se define
//       como un arreglo en el que la posicion despues del
//       ultimo elemento regresa al primero.
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; // Tamano del arreglo
    int x; // Valor a insertar en el arreglo
    int k; // Posicion donde se insertara el elemento

    // Leer valores
    cin >> n >> x >> k;
    // Crear el arreglo
    vector<int> arreglo(n);
    
    // Utilizamos el modulo para obtener el valor
    // correspondiente. Es decir, un valor entre 0 y n
    arreglo[k % n] = x;

    for(int i = 0; i < n; i++) {
        cout << arreglo[i] << " ";
    }
    cout << "\n";


    return 0;
}