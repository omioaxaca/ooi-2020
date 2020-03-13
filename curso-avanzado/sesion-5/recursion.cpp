// Fibonnaci: f(n) = f(n-1) + f(n-2)
//            f(0) = 1
//            f(1) = 1
// 1 1 2 3 5 8 13 21 34 ...
#include <iostream>

using namespace std;

int fib(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    int izq = fib(n - 2);
    int der = fib(n - 1);
    return izq + der;
    // return f(n - 2) + f(n - 1);
}

// Factorial = n! = n * (n - 1)!
int f(int n) {
    if (n == 1) return 1;
    return n * f(n - 1);
}

// Todos los numeros posibles de n digitos del 1 al 9
// g(n) = numeros posibles de 1 digitos concatenados a los posibles de n -1 digitos
void g(int n) {
    if (n == 0) return;
    for (int i = 1; i <= 9; i++) {
        cout << i;
        g(n - 1);
        cout << "\n";
    }
}

int main() {
    g(3);

    return 0;
}