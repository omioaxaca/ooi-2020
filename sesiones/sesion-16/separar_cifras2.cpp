// Programa para separar un numero entero en sus digitos
// Por ejemplo el numero 378 -> 3 7 8
// Entrada: Un numero entero
// Salida: Los digitos del numero separados por un espacio
#include <iostream>

using namespace std;

// Ejemplo: n = 378
// Division             Modulo
// 378 / 100 = 3        378 % 100 = 78
//  78 /  10 = 7         78 %  10 =  8
//   8 /   1 = 8          8 %   1 =  0

// Ejemplo: n = 8652
//  Division            Modulo
//  8652 / 1000 = 8     8652 % 1000 = 652
//   652 /  100 = 6      652 %  100 =  52
//    52 /   10 = 5       52 %   10 =   2
//     2 /    1 = 2        2 %    1 =   0

// Tenemos el numero n.
// Buscar el multiplo de 10 mas grande que no sea mayor que n
// Mientras el residuo de n / multiplo no sea 0
//    Dividir n / multiplo y guardar ese valor
//    n = n % multiplo (de esta forma eliminamos el digito de la derecha y nos quedamos con el restoo)
//    Disminuir el multiplo a uno mas bajo multiplo = multiplo / 10
void separar_digitos(int n) {
    // Encontrar el multiplo
    // Para eso dividimos n / 10 hasta que se haga cero y contamos los pasos
    int multiplo = 1;
    int num = n;
    while(num > 0) {
        multiplo = multiplo * 10;
        num = num / 10;
    }
    multiplo = multiplo / 10;
    cout << "multiplo de 10: " << multiplo << endl;
    // Separar en digitos
    int residuo = n % multiplo;
    while (residuo > 0) {
        int digito = n / multiplo;
        cout << digito << " ";
        residuo = n % multiplo;
        n = residuo;
        multiplo = multiplo / 10;
    }
}

int main() {
    int n = 0;
    cin >> n;
    separar_digitos(n);

    return 0;
}