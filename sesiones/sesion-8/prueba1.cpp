#include <iostream>

using namespace std;


/*
    Dados dos números a y b donde a es menor o igual a b
    Obtener la suma de todos los números en el intervalo [a, b]
    incluyendolos
*/


int main() {
    int a, b;

    cout << "Ingresa dos números: ";
    cin >> a >> b;

    int result = 0;
    // while (a <= b) {
    //     result = result + a;
    //     a = a + 1;
    // }

    // Si ingresamos a=3 y b=4
    // result =  0, a = 3, b = 5, 3 <= 5 -> Verdadero
    // result =  3, a = 4, b = 5, 4 <= 5 -> Verdadero
    // result =  7, a = 5, b = 5, 5 <= 5 -> Verdadero
    // result = 12, a = 6, b = 5, 6 <= 5 -> Falso


    for (; a <= b; a = a + 1) {
        result = result + a;
    }

    cout << result << endl;

    return 0;
}
