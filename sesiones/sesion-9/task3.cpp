/*
    fact(5) = 5 * 4 * 3 * 2 * 1 = 120

    Escribir una función que nos calcule
    el factorial de un número de manera recursiva
*/

#include <iostream>

using namespace std;

int fact(int num) {
    if (num == 1) {
        return 1;
    }

    return num * fact(num-1);
}


int main() {

    int num;

    cin >> num;

    cout << "Factorial de " << num << " es: " << fact(num) << endl;

    return 0;
}
