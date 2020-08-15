#include <iostream>
#include <vector>
#define MAX 1000003

using namespace std;

vector<bool> esPrimo(MAX, true);
vector<int> primos;

void criba() {
    // El 0 y el 1 no son primos.
    esPrimo[0] = esPrimo[1] = false;
    for (int i = 2; i < MAX; i++) {
        // Si i es primo, entonces marcar todos sus multiplos como no primos.
        if (esPrimo[i]) {
            primos.push_back(i);
            for (int j = i + i; j < MAX; j += i) {
                esPrimo[j] = false;
            }
        }
    }
}

int main() {
    // Calcular la criba antes de todo.
    criba();

    int n;
    cin >> n; 

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (esPrimo[x]) {
            cout << "Es primo";
        }
        else {
            cout << "No es primo";
        }
    }

    return 0;
}