// https://omegaup.com/arena/problem/L-OMI-Super-Agente/#problems
// Solucion:
// Utilizar BFS para simular el movimiento de todos los guardias al mismo tiempo.
// En una matriz auxiliar, guardar la cantidad de pasos que necesita un guardia
// para llegar alli. Dado que se utiliza BFS, se garantiza que la primera vez que se
// visita una celda representa la menor cantidad de pasos necesarios que necesita
// dar el guardia mas cercano.
// Al final, se puede recorrer la matriz auxiliar para verificar cual es la cantidad
// de pasos mayor.
// Nota: Es importante que la BFS se haga al mismo tiempo para cada uno de los guardias,
//       de esta forma el algoritmo es mas eficiente.
#include <iostream>
#include <queue>

#define TAM 2003 // 2000 es la cantidad mas grande de celdas y columnas

using namespace std;

struct Nodo {
    int x;     // Numero de fila,
    int y;     // Numero de columna.
    int pasos; // Cantidad de pasos que ha dado el guardia.
};

int filas, columnas;
char edificio[TAM][TAM];
int pasos[TAM][TAM];

void inicializar_pasos() {
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            pasos[i][j] = -1;
}

// Simular el movimiento de los guardias desde su posicion inicial
// hacia todos los lugares posibles por visitar.
void bfs(const vector<Nodo>& guardias) {
    // Al principio, todas las posiciones inician en -1, lo que significa que ningun
    // guardia ha visitado esa casilla.
    inicializar_pasos();

    // Insertar todos los guardias a la cola, para iniciar la BFS
    // al mismo tiempo para cada uno de ellos.
    queue<Nodo> nodos;
    for (int i = 0; i < guardias.size(); i++) {
        Nodo guardia = guardias[i];
        nodos.push(guardia);
        pasos[guardia.x][guardia.y] = 0; // 0 pasos, pues aqui ya hay un guardia.
    }

    // Iniciar BFS.
    while(!nodos.empty()) {
        Nodo actual = nodos.front();
        nodos.pop();

        // Simular todos los movimientos posibles.
        vector<int> mov_x = {-1, 0, 1, 0};
        vector<int> mov_y = { 0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            Nodo sig;
            sig.x = actual.x + mov_x[i];
            sig.y = actual.y + mov_y[i];
            sig.pasos = actual.pasos + 1;

            // Verificar que sig este dentro de los limites de la matriz.
            if (sig.x < 0 || sig.x >= filas || sig.y < 0 || sig.y >= columnas)
                continue;
            // Verificar que sig no haya sido visitado antes.
            if (pasos[sig.x][sig.y] >= 0)
                continue;
            // Si es una posicion libre, marcar la cantidad de pasos e insertar en la cola,
            if (edificio[sig.x][sig.y] == '.') {
                pasos[sig.x][sig.y] = sig.pasos;
                nodos.push(sig);
            }
        }
    }
}

int main() {
    cin >> filas >> columnas;
    vector<Nodo> guardias;

    // Leer la descripcion del edificio.
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cin >> edificio[i][j];
            // En caso de leer el salto de linea.
            if (edificio[i][j] == '\n') {
                cin >> edificio[i][j];
            }
            // Insertar el guardia en el vector de guardias.
            if (edificio[i][j] == 'G') {
                guardias.push_back({i, j, 0});
            }
        }
    }

    // Iniciar la BFS pasando el vector de guardias.
    bfs(guardias);

    // Al terminar la BFS, la matriz de pasos contiene toda la informacion
    // del movimiento de los guardias. Al recorrerla se encuentra la mejor
    // posicion para situar al agente.
    int distancia = 0;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (distancia < pasos[i][j])
                distancia = pasos[i][j];
        }
    }
    cout << distancia << "\n";

    return 0;
}