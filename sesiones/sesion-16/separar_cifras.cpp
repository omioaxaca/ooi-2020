// Programa para separar un numero entero en sus digitos
// Por ejemplo el numero 378 -> 8 7 3
// Entrada: Un numero entero
// Salida: Los digitos del numero separados por un espacio
#include <iostream>

using namespace std;

// Ejemplo: 378
// Division             Modulo
// 378 / 10 = 37        378 % 10 = 8
//  37 / 10 = 3         37  % 10 = 7
//   3 / 10 = 0         3   % 10 = 3

// Ejemplo: 8652
//  Division            Modulo
//  8652 / 10 = 865     8652 % 10 = 2
//  865  / 10 = 86      865  % 10 = 5
//  86   / 10 = 8       86   % 10 = 6
//  8    / 10 = 0       8    % 10 = 8

// Tenemos el numero n.
// Mientras n sea mayor que 0
//    Hacer n % 10 y guardar ese numero
//    n = n / 10
void separar_digitos(int n) {
    while(n > 0) {
        int digito = n % 10;
        cout << digito << " ";
        n = n / 10;
    }
}

int main() {
    int n = 0;
    cin >> n;
    separar_digitos(n);

    return 0;
}