// Programa para convertir numeros ASCII
// en enteros, y viceversa.
#include <iostream>

using namespace std;

// Funcion para convertir numeros ASCII a numeros enteros
// Del '0' al '9'
// Ejemplo:
// '5' regresa 5
// '9' regresa 9
int num_ascii_a_entero(char k) {
    // Para convertir un numero ascii en entero, es necesario
    // restarle el valor ascii del '0'
    int numero;
    numero = k - '0';
    return numero;
}

// Convertir un entero del 0 al 9
// en su representacion ASCII.
// Ejemplo:
// 5 regresa '5'
// 9 regresa '9'
char entero_a_num_ascii(int n) {
    // Para convertir un numero ascii en entero, es necesario
    // sumarle el valor ascii del '0'
    char num_ascii;
    num_ascii = n + '0';
    return num_ascii;
}

int main() {
    char num_ascii  = '5';
    char num_ascii2 = '6';
    int suma = num_ascii_a_entero(num_ascii) + num_ascii_a_entero(num_ascii2);
    cout << "La suma debe ser 11 y actualmente es: " << suma;


    return 0;
}