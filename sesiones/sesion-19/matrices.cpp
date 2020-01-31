// Representar arreglos de una dimension y de dos
#include <iostream>

using namespace std;

int main() {
    // Declarar un arreglo utilizando la forma nativa
    // Importante: El arreglo no se inicia en ceros
    int tam_arreglo = 5;
    int arreglo[tam_arreglo]; // {?, ?, ?, ?, ?}
    // Para acceder al elemento i, se utiliza arreglo[i]

    // Declarar un arreglo de 2 dimensiones utlizando la forma nativa
    int filas    = 3;
    int columnas = 2;
    // Tamanio de la matriz sera de filas * columnas
    int matriz[filas][columnas]; 
    // La matriz se veria asi:
    // {
    // {?, ?},
    // {?, ?},
    // {?, ?}
    // }

    // NOTA: Las filas se indexan de arriba hacia abajo, empezando en 0.
    //       Las columnas se indexan de izquierda a derecha, empezando en 0.
    // Para acceder a un elemento, se hace lo siguiente:
    // Ejemplo: Acceder a la tercer fila en la segunda columna
    // matriz[2][1]

    int contador = 0;
    // Recorrer cada fila de la matriz
    for (int fila = 0; fila < filas; fila++) {
        // Recorrer cada espacio de las columnas dentro de esta fila
        for (int columna = 0; columna < columnas; columna++) {
            matriz[fila][columna] = contador;
            contador++;
        }
    }

    // Imprimir los valores de la matriz
    for (int fila = 0; fila < filas; fila++) {
        for (int columna = 0; columna < columnas; columna++) {
            cout << matriz[fila][columna] << " ";
        }
        cout << "\n";
    }

    // Imprimir el valor en tercera fila y segunda columna
    cout << "Valor de la casilla 2,1: " << matriz[2][1];

    return 0;
}