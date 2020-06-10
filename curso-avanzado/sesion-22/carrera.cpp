#include <iostream>
#include <queue>
#include <string>
#include <vector>
#define TAM 1003

using namespace std;

char laberinto[TAM][TAM];
bool visitados[TAM][TAM];
// Cantidad de filas y columnas del laberinto.
int fil = 0;
int col = 0;

// Definir el estado de la busqueda
struct Nodo {
    int x;
    int y;
    int pasos;
};

// Arreglos de movimientos posibles.
vector<int> mov_x = {-1, 0, 1, 0};
vector<int> mov_y = {0, 1, 0, -1};

// Funcion para determinar si la busqueda ya esta completa, es decir
// que ya se alcanzo el destino.
// Si el estado actual es igual a la posicion de Damian o Arturo, entonces
// la busqueda esta completa.
bool busqueda_completa(Nodo actual) {
    if (laberinto[actual.x][actual.y] == 'A') {
        cout << "Arturo " << actual.pasos;
        return true;
    }
    if (laberinto[actual.x][actual.y] == 'D') {
        cout << "Damian " << actual.pasos;
        return true;
    }
    return false;
}

// Verificar si un estado es valido.
bool estado_valido(Nodo n) {
    if (n.x < 0 || n.x > fil || n.y < 0 || n.y > col)
        return false;
    if (laberinto[n.x][n.y] == 'X')
        return false;
    if (visitados[n.x][n.y])
        return false;
    return true;
}

// Implementacion de una busqueda en amplitud.
// Regresa true si se completa la busqueda, de lo contrario regresa false.
bool bfs(Nodo inicio) {
    queue<Nodo> Q;
    Q.push(inicio);
    while(!Q.empty()) {
        Nodo actual = Q.front();
        Q.pop();

        if (busqueda_completa(actual)) {
            return true;
        }

        for (int i = 0; i < 4;i++) {
            Nodo sig;
            sig.x = actual.x + mov_x[i];
            sig.y = actual.y + mov_y[i];
            sig.pasos = actual.pasos + 1;
            if (estado_valido(sig)) {
                visitados[sig.x][sig.y] = true; // Marcar como visitado desde aqui evita que un mismo nodo se inserte varias veces en la cola.
                Q.push(sig);
            }
        }
    }
    return false;
}

int main() {
    string linea; // Variable para guardar los datos leidos de una linea.
    Nodo salida;  // Representa la posicion donde esta la salida.
    while(getline(cin, linea)) {
        for (col = 0; col < linea.length(); col++) {
            laberinto[fil][col] = linea[col];
            if (laberinto[fil][col] == 'F') {
                salida.x = fil;
                salida.y = col;
                salida.pasos = 0;
            }
        }
        fil++;
    }

    bool busqCompleta;
    busqCompleta = bfs(salida);
    if (!busqCompleta) {
        cout << "Ni Damian, ni Arturo llegan a la salida.";
    }


    return 0;
}