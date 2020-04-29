// Ejercicio para identificar si es posible salir de un laberinto.
#include <iostream>
#include <vector>
#define TAM 1003

using namespace std;

// Matriz para contener el mapa
char laberinto[TAM][TAM];
// Dimensiones del laberinto
int n, m;
// Variables que indican la salida del laberinto
int f_x, f_y; // Final
// Variable para indicar si se encontro o no salida.
bool encontrado = false;

void busca_salida(int x, int y) {
    // Verificar si la solucion ya fue encontrada
    if (encontrado) {
        return;
    }

    // Comprobar si ya encontre la salida
    if (x == f_x && y == f_y) {
        // Salida encontrada
        encontrado = true;
    }
    // Vericar que la posicion actual sea valida
    if (x < 0 || x >= n || y < 0 || y >= m) {
        // La posicion actual esta fuera de la matriz.
        return;
    }
    if (laberinto[x][y] == 'X') {
        // Esta posicion es invalida porque existe una pared.
        return;
    }
    if (laberinto[x][y] == '*') {
        // Esta posicion ya fue visitada
        return;
    }

    // Marcar la casilla actual como visitada
    laberinto[x][y] = '*';


    // Explorar todas las posibilidades
    // Simular los 4 movimientos posibles.
    vector<int> mov_x = {-1, 0, 1,  0};
    vector<int> mov_y = { 0, 1, 0, -1};
    for (int i = 0; i < 4; i++) {
        int x_sig = x + mov_x[i];
        int y_sig = y + mov_y[i];
        busca_salida(x_sig, y_sig);
    }
}

int main() {
    // Variables para guardar el inicio
    int i_x, i_y; // Inicio

    // Leer los datos
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> laberinto[i][j];
            if (laberinto[i][j] == 'I') {
                i_x = i;
                i_y = j;
            }
            if (laberinto[i][j] == 'F') {
                f_x = i;
                f_y = j;
            }
        }
    }
    
    // Llamar a la funcion
    busca_salida(i_x, i_y);

    // Imprimir el resultado
    if (encontrado) {
        cout << "SI\n";
    }
    else {
        cout << "NO\n";
    }

    return 0;
}