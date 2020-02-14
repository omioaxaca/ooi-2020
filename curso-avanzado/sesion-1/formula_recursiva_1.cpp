// https://omegaup.com/arena/problem/Formula-Recursiva-Uno/#problems
#include <iostream>

using namespace std;

long long int f(long long int n) {
    if (n <= 5) {
        return 1;
    }
    else {
        long long int resultado = f(n-2) * 5;
        return resultado;
    }
}

int main() {
    int x;
    cin >> x;
    cout << f(x) << "\n";

    return 0;
}