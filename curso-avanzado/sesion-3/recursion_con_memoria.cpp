// Funcion recursiva 4
#include <iostream>
#include <vector>

using namespace std;

vector<int> memo(41);

int f(int n) {
    // Caso base
    if (n <= 3) {
        return  1;
    }
    // Verificar si no lo hemos calculado antes
    if(memo[n] != 0) {
        return memo[n];
    }
    // Calcular el resultado y guardarlo en la memoria
    memo[n] = f(n-1) + f(n-2) + f(n-3);
    return memo[n];
}

int main() {
    int n;
    cin >> n;
    cout << f(n);

    return 0;
}