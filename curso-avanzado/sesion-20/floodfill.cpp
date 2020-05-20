// Implementacion de algoritmo Flood fill (Relleno por difusion)
// Una celda se considera adyacente a otra si comparte un lado o una esquina dentro del mapa.
// Ejemplo: Las celdas con los numeros del 1 al 8 son adyacentes al asterisco.
// 1 2 3
// 4 * 5
// 6 7 8
#include <iostream>
#include <vector>
#include <string>
#define TAM 1003

using namespace std;

// Matriz para contener el mapa
char mapa[TAM][TAM];
// Dimensiones del mapa
int n, m;
// Movimientos posibles
vector<int> mov_x = {-1, -1, -1,  0, 0,  1, 1, 1};
vector<int> mov_y = {-1,  0,  1, -1, 1, -1, 0, 1};

// DFS
void floodfill(int x, int y) {
    // Verificar que aun este dentro del mapa
    if (x < 0 || x >= n || y < 0 || y >= m) {
        return;
    }
    // Verificar si la casilla ya esta pintada o es una pared.
    if (mapa[x][y] == '*' || mapa[x][y] == 'X') {
        return;
    }

    // Pintar la casilla
    if (mapa[x][y] == '.') {
        mapa[x][y] = '*';
    }
    // Ir a las celdas adyacentes
    for (int i = 0; i < 8; i++) {
        int x_sig = x + mov_x[i];
        int y_sig = y + mov_y[i];
        floodfill(x_sig, y_sig);
    }
}

void imprimir_mapa() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mapa[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    string fila;
    int x_ini = 0;
    int y_ini = 0;
    // Leer toda la linea y guardarla en fila, mientras existan datos
    int fila_idx = 0;
    while (getline(cin, fila)) {
        // Obtener el numero de columnas, que es igual a la longitud de la fila
        int columnas = fila.length();
        for (int i = 0; i < columnas; i++) {
            mapa[fila_idx][i] = fila[i];
            if (mapa[fila_idx][i] == '*') {
                x_ini = fila_idx;
                y_ini = i;
            }
        }
        fila_idx++;
        // Asignar cantidad de columnas
        m = columnas;
    }
    // Asignar cantidad de filas
    n = fila_idx;

    // Mostrar mapa
    imprimir_mapa();

    // Llamar a flood fill
    mapa[x_ini][y_ini] = '.'; // Al entrar a la funcion floodfill, la casilla sera pintada.
    floodfill(x_ini, y_ini);

    // Mostrar el resultado despues de rellenar el mapa
    imprimir_mapa();

    return 0;
}