// Uso de matrices
// Problema: Dada una matriz de tamano n * m (n filas y m columnas)
// Inserta el valor x en la posicion k
// Nota: La celda de arriba a la izquierda es la posicion 0,
//       y aumenta de izquiera a derecha y de arriba hacia abajo.
//
#include <iostream>

using namespace std;

int main() {
    int n; // Cantidad de filas de la matriz
    int m; // Cantidad de columnas de la matriz
    int x; // Elemento a insertar
    int k; // La posicion en la que se insertara el elemento
    // Leer los datos
    cin >> n >> m >> x >> k;
    // Crear una matriz de tamano n * m
    int matriz[n][m];
    // Iniciar la matriz en ceros
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matriz[i][j] = 0;
        }
    }
    // Insertar x en la posicion k
    // Para saber el indice de la fila en que esta la posicion k,
    // dividimos k entre la cantidad de columnas.
    int fila    = k / m;
    // Para saber el indice de la columna en que esta la posicion k,
    // obtenemos el modulo de k entre la cantidad de columnas.
    int columna = k % m; 
    matriz[fila][columna] = x;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";


    return 0;
}
