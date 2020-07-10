// Uso de una cola de prioridad (heap, monticulo)
// Operacion        Instruccion     Complejidad
// Insertar         push            O(1)
// Consultar        top             O(log2n)
// Eliminar         pop             O(log2n)

#include <iostream>
#include <queue>

using namespace std;

struct Nodo {
    int x;
    int y;
    int pasos;
};

// Es necesario definir el operador < para que el Nodo
// pueda ser utilizado con una cola de prioridad.
bool operator<(Nodo a, Nodo b) {
    return a.pasos > b.pasos;
}

int main() {
    priority_queue<int> PQ;
    // Por defecto la prioridad siempre es para el elemento mayor.
    PQ.push(3);
    PQ.push(1);
    PQ.push(5);
    while (!PQ.empty()) {
        int actual = PQ.top();
        PQ.pop();
        cout << actual << "\n";
    }
    cout << "\n";


    // Cola de prioridad para una estructura personalizada
    priority_queue<Nodo> nodos;
    nodos.push({0,0,2});
    nodos.push({1,0,5});
    nodos.push({0,0,5});
    while (!nodos.empty()) {
        Nodo actual = nodos.top();
        nodos.pop();
        cout << actual.x << " " << actual.y << " " << actual.pasos << "\n";
    }
}