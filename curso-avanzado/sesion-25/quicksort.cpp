#include <iostream>
#include <vector>
#include <random>

using namespace std;

void quicksort(vector<int>& numeros) {
    if (numeros.size() == 0 || numeros.size() == 1) {
        return;
    }
    int pivote_indice = 0;
    int pivote = numeros[pivote_indice];
    vector<int> menores;
    vector<int> mayores;
    for (int i = 0; i < numeros.size(); ++i) {
        if (i == pivote_indice) {
            continue;
        }
        if (numeros[i] < pivote) {
            menores.push_back(numeros[i]);
        }
        else {
            mayores.push_back(numeros[i]);
        }
    }
    quicksort(menores);
    quicksort(mayores);

    int indice = 0;
    for (int i = 0; i < menores.size(); ++i) {
        numeros[indice] = menores[i];
        indice++;
    }
    numeros[indice] = pivote;
    indice++;
    for (int i = 0; i < mayores.size(); ++i) {
        numeros[indice] = mayores[i];
        indice++;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> numeros(n);
    for (int i = 0; i < n; ++i) {
        cin >> numeros[i];
    }
    quicksort(numeros);

    for (int i = 0; i < n; ++i) {
        cout << numeros[i] << " ";
    }

    return 0;
}