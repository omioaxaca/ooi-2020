// Busqueda en profundidad
// Depth First Search - DFS

// Ejemplo: Encontrar todas las sumas posibles **diferentes** mayores o iguales a `x` en un vector.
// Entrada:
// {1, 4, 5}
// x = 5
// Salida:
// 5, 6, 9, 10

#include <iostream>
#include <vector>
#include <set>

using namespace std;

// Set para guardar las respuestas unicas
set<int> respuestas;

// Funcion para realizar la DFS
void calcula_sumas(int pos, int sum, vector<int>& valores, int objetivo) {
    // Revisar si el estado actual es una respuesta
    if (sum >= objetivo) {
        // Insertar respuesta en el set
        respuestas.insert(sum);
    }
    // Revisar estado invalido
    if (pos >= valores.size()) {
        return;
    }
    // Probar con todas las opciones disponibles
    // a) NO incluir el elemento actual en la suma
    calcula_sumas(pos + 1, sum, valores, objetivo);
    // b) SI incluir el elemento actual en la suma
    calcula_sumas(pos + 1, sum + valores[pos], valores, objetivo);
}

int main() {
    int n;
    int x;
    cin >> n >> x;
    vector<int> valores(n);
    for (int i = 0; i < valores.size(); i++) {
        cin >> valores[i];
    }
    calcula_sumas(0, 0, valores, x);

    // Imprimir las respuestas guardadas en el set.
    for (int valor : respuestas) {
        cout << valor << "\n";
    }


    return 0;
}


