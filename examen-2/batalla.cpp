//Batalla
// Nosotros: 5 15 100 1 5  = 0
// Dr Lira:  5 15 100 1 5


// Nosotros: 15 100  1    5   5  = 120
// Dr Lira:  5  15  100   1   5

// 1  5   5  15  100
// Nosotros: 5    15  100 1   5
// Dr Lira:  1    5   5   15  100

// 1 2 26
// Nosotros: 2   26  1
// Dr Lira:  1   20  25


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int busca_ultimo_mayor(int x, vector<int>& valores) {
    for (int i = valores.size() - 1; i >= 0; i--) {
        if (valores[i] > x) return i;
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> soldadosA(n); // Soldados mios
    vector<int> soldadosB(n); // Soldados Dr Lira

    for (int i = 0; i < n; i++) {
        cin >> soldadosA[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> soldadosB[i];
    }

    sort(soldadosA.begin(), soldadosA.end());
    sort(soldadosB.begin(), soldadosB.end());

    // Iterar sobre los soldado del Dr Lira, y buscar cual es primer soldado de los nuestros
    // que tiene mayor fuerza.
    // Nota: Es necesario recorrer los soldados de Dr Lira de mayor a menor, de esta forma
    // garantizamos que siempre elegimos a el mas fuerte de los nuestros que le gane y asi
    // garantizar salvar los soldados mas fuertes.
    int total = 0;
    for (int i = soldadosB.size() - 1; i >= 0; i--) {
        // Si existe un soldado de nosotros con fuerza mayor a el soldado de Dr Lira i,
        // entonces el nuestro debe luchar contra ese. Sumamos la fuerza a nuestro
        // resultado y retiramos a ese soldado de nuestra lista
        int soldadoElegido = busca_ultimo_mayor(soldadosB[i], soldadosA);
        if (soldadoElegido >= 0) {
            total += soldadosA[soldadoElegido];
            soldadosA.erase(soldadosA.begin() + soldadoElegido); // Complejidad de eliminar un elemento es O(n), n=tamanio vector
        }
    }
    cout << total << "\n";

    return 0;
}
