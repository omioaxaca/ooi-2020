// Lectura y escritura de datos
#include <iostream>

using namespace std;

int main() {
    // Declarar variables de tipo entero
    int a;
    int b;
    int c;

    cin >> a;           // Leer valor y guardarlo en a
    cout << a << "\n";  // Imprimir valor de a
    cin >> b;           // Leer valor y guardarlo en b
    cout << b << "\n";  // Imprimir valor de b

    c = a + b;          // Asignar el valor de a + b a la variable c
    cout << c << "\n";  // Imprimir el valor de c

    return 0;
}