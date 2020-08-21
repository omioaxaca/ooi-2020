#include <vector>
#include <iostream>
#include <cmath>
#define MAX 1000003

typedef long long int lli;

using namespace std;

vector<bool> esPrimo(MAX + 1, true);
vector<lli> primos;

void criba() {
    esPrimo[0] = esPrimo[1] = false;
    for (int i = 2; i <= MAX; i++) {
        if (esPrimo[i]) {
            primos.push_back(i);
            for (int j = i + i; j <= MAX; j += i) {
                esPrimo[j] = false;
            }
        }
    }
}

void factorizar(lli x) {
    int limite = sqrt(x);
    for (int i = 0; i < primos.size() && primos[i] <= limite; i++) {
        while (x % primos[i] == 0) {
            cout << primos[i] << " ";
            x = x / primos[i];
        }
        limite = sqrt(x);
    }
    if (x > 1) {
        // x es primo, entonces es factor
        cout << x;
    }
}

int main() {
    criba();

    lli x;
    cin >> x;
    factorizar(x);
    cout << "\n";

    return 0;
}