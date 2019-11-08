// Demostrar la jerarquia de operaciones en C++
#include <iostream>

using namespace std;

int main() {
    // Todo entre parenteris se ejecuta primero
    // Prioridad:
    // 1. Multiplicacion, division, modulo
    // 2. Suma y resta
    int x = 4 + 2 * 3;              // 10
    int y = (4 + 2) * 3;            // 18 
    int z = ((1 + 2) * 4) / 6;      //  2

    cout << x << " " << y << " " << z;


    return 0;
}