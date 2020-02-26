// Exponenciacion rapida
// Elevar a a la n

#include <iostream>

using namespace std;

typedef long long int lli;

lli potencia(int a, int n) {
    lli resultado = 1;
    for (int i = 0; i < n; i++) {
        resultado *= a;
    }
    return resultado;
}

// f(a, 64) = f(a, 32) * f(a, 32)
// f(a, 32) = f(a, 16) * f(a, 16)
// f(a, 16) = f(a, 8) * f(a, 8)
// f(a, 8)  = f(a, 4) * f(a, 4)
// f(a, 4)  = f(a, 2) * f(a, 2)
// f(a, 2)  = a * a

// f(a, 7) = f(a, 6) * a
// f(a, 6) = f(a, 3) * f(a, 3)
// f(a, 3) = f(a, 2) * a
// f(a, 2) = a * a
long long int potencia_rapida(long long int a, int n) {
    // Casos bases
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return a;
    }
    // Pasos recursivos
    if (n % 2 == 0) {
        long long int memo = potencia_rapida(a, n/2);
        return memo * memo;
    }
    else {
        return potencia_rapida(a, n - 1) * a;
    }
}

int main() {
    int a, n;

    cin >> a >> n;
    cout << potencia_rapida(a, n);

    return 0;
}