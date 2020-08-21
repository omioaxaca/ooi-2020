// Representacion de un grafo con lista de adyacencia
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Verificar si existe un camino para ir desde u a v
void dfs(int u, int v, const vector<vector<int>>& adyacencia, bool& posible, vector<bool>& visitados) {
    if (posible) {
        return;
    }
    if (u == v) {
        posible = true;
        return;
    }
    // Revisar las conexiones
    for (int i = 0; i < adyacencia[u].size(); i++) {
        int vecino = adyacencia[u][i];
        if (!visitados[vecino]) {
            visitados[vecino] =  true;
            dfs(vecino, v, adyacencia, posible, visitados);
        }
    }
}

struct  Nodo
{
    int pos;
    int pasos;
};


int bfs(int u, int v, vector<vector<int>>& adyacencia) {
    int num_nodos =  adyacencia.size();
    vector<bool> visitados(num_nodos);
    queue<Nodo> nodos;
    Nodo inicial = {u, 0};
    nodos.push(inicial);
    visitados[u] = true;

    while (!nodos.empty()) {
        Nodo actual = nodos.front();
        nodos.pop();

        if (actual.pos == v) {
            return actual.pasos;
        }

        for (int i = 0; i < adyacencia[actual.pos].size(); ++i) {
            Nodo vecino;
            vecino.pos = adyacencia[actual.pos][i];
            vecino.pasos = actual.pasos + 1;
            if (!visitados[vecino.pos]) {
                visitados[vecino.pos] = true;
                nodos.push(vecino);
            }
        }
    }
    return -1;
}

int main() {
    int nodos;
    cin >> nodos;
    
    // Declarar la lista de adyacencia
    vector<vector<int>> adyacencia(nodos + 1);

    for (int nodo = 1; nodo <= nodos; ++nodo) {
        int conexiones;
        cin >> conexiones;
        for (int i = 0; i < conexiones; ++i) {
            int vecino;
            cin >> vecino;
            // Insertar la conexion del nodo con su vecino
            adyacencia[nodo].push_back(vecino);
        }
    }

    int q; // preguntas
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int u;
        int v;
        cin >> u >> v;
        vector<bool> visitados(nodos + 1, false);
        bool posible = false;
        // Revisar si es posible ir de u hasta v.
                cout << bfs(u, v, adyacencia);
        // dfs(u, v, nodos, posible, visitados);
        // if (posible) {
        //     cout << "SI\n";
        // }
        // else {
        //     cout << "NO\n";
        // }
    }


    return 0;
}