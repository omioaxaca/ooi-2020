/*
    Dados 3 números a, b, y c
    imprimir en pantalla el más grande de los tres
    si todos son iguales imprmir el mensage "Todos son iguales"
*/

#include <iostream>

using namespace std;

int main() {

    double a, b, c;

    cout << "Ingresa 3 números: ";
    cin >> a >> b >> c;

    if ( a == b || b == c ) {
        cout << " todos son iguales ";
    } else if ( a >= b && a >= c ) {
        cout << a << endl;
    } else if (b >= a && b >= c) {
        cout << b << endl;
    } else {
        cout << c << endl;
    }

    return 0;
}
