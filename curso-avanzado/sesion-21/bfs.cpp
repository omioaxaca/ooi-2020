// Ejercicio.
// Encontrar la cantidad minima de pasos para ir de un punto de inicio a uno de final.
// Los movimientos posibles son arriba, abajo, izquierda, derecha.
#include <iostream>
#include <vector>
#include <queue>
#define TAM 1003

using namespace std;

// Crear una estructura que nos permita representar el estado de la busqueda.
struct Nodo {
    int x;      // Posicion en el eje x
    int y;      // Posicion en el eje y
    int pasos;  // Cantidad de pasos para ir desde el inicio hasta este estado.
};

// Matriz para contener el mapa
char laberinto[TAM][TAM];
// Declarar una copia de la matriz para indicar si la casilla ya se visito o no.
bool visitado[TAM][TAM] = {}; // Inicializar todo a falso.
// Dimensiones del laberinto
int n, m;
// Variables que indican la salida del laberinto
Nodo final = {0, 0, 0}; // Final
// Movimientos posibles (Arriba, Derecha, Abajo, Izquierda)
vector<int> mov_x = {-1, 0, 1,  0};
vector<int> mov_y = { 0, 1, 0, -1};

// Implementacion de una BFS (Busqueda en amplitud)
int busca_salida(Nodo inicio) {
    // Declarar la cola para guardar los estados.
    queue<Nodo> Q;
    // Insertar el primer elemento a la cola.
    Q.push(inicio);
    
    // Mientras haya nodos pendientes por visitar
    while(!Q.empty()) {
        // Sacar el nodo del frente de la cola.
        Nodo actual = Q.front();
        Q.pop(); // Importante. Eliminar el elemento de la cola.

        // Verificar si este es el resultado.
        if (actual.x == final.x && actual.y == final.y) {
            // Acabar la busqueda y regresar el resultado.
            return actual.pasos;
        }
        // Marcar este nodo como vistiado.
        visitado[actual.x][actual.y] = true;

        // Para todos los hijos (conexiones) de este nodo, agregarlos a la cola.
        for (int i = 0; i < 4; i++) {
            Nodo sig; // Nodo siguiente a visitar
            sig.x = actual.x + mov_x[i];
            sig.y = actual.y + mov_y[i];
            sig.pasos = actual.pasos + 1;
            // Verificar si el siguiente estado es valido
            if (sig.x < 0 || sig.x >= n || sig.y < 0 || sig.y >= m) {
                continue; // Saltar todo el codigo debajo e ir a la siguiente iteracion del for.
            }
            // Verificar si es una posicion invalida.
            if (laberinto[sig.x][sig.y] == 'X') {
                continue;
            }
            // Verificar si el siguiente estado no ha sido visitado
            if (visitado[sig.x][sig.y] == true) {
                continue;
            }
            // Si el estado siguiente es valido y no ha sido visitado, lo agrego a la cola.
            Q.push(sig);
        }
    }
    // No se encontro la respuesta.
    return -1;
}

int main() {
    // Variables para guardar el inicio
    Nodo inicio = {0, 0, 0}; // Iniciar en 0 todos los valores de la estructura.

    // Leer los datos
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> laberinto[i][j];
            if (laberinto[i][j] == 'I') {
                inicio.x = i;
                inicio.y = j;
            }
            if (laberinto[i][j] == 'F') {
                final.x = i;
                final.y = j;
            }
        }
    }
    
    // Llamar a la funcion
    int pasos_minimos = 0;
    pasos_minimos = busca_salida(inicio);

    // Imprimir el resultado
    if (pasos_minimos >= 0) {
        cout << pasos_minimos;
    }
    else {
        cout << "NO\n";
    }

    return 0;
}