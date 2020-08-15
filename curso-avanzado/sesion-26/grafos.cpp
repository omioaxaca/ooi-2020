// Implementacio de un grafo con matriz de adyacencia.
#include <iostream>
#include <vector>
#define TAM 103

using namespace std;

bool adyacencia[TAM][TAM] = {0};

void dfs(int u, int v, int nodos, bool& posible, vector<bool>& visitados) {
    // Si ya se encontro un camino, no hacer nada mas.
    if (posible) {
        return;
    }
    // La busqueda termina cuando llegamos a v.
    if (u == v) {
        posible = true;
        return;
    }
    // Explorar los nodos adyacentes para ver si hay un camino.
    for (int i = 1; i <= nodos; ++i) {
        // Si hay una conexion entre u e i. Buscamos por ese camino.
        if (adyacencia[u][i] && !visitados[i]) {
            visitados[i] =  true;
            dfs(i, v, nodos, posible, visitados);
        }
    }
}

int main() {
    int nodos;
    cin >> nodos;

    for (int nodo = 1; nodo <= nodos; ++nodo) {
        int conexiones;
        cin >> conexiones;
        for (int i = 0; i < conexiones; ++i) {
            int vecino;
            cin >> vecino;
            adyacencia[nodo][vecino] = true;
        }
    }

    int q; // preguntas
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int u;
        int v;
        cin >> u >> v;
        vector
        <bool> visitados(nodos, false);
        bool posible = false;
        // Revisar si es posible ir de u hasta v.
        dfs(u, v, nodos, posible, visitados);
        if (posible) {
            cout << "SI\n";
        }
        else {
            cout << "NO\n";
        }
    }


    return 0;
}