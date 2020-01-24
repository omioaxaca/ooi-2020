// Demostracion de manejo de caracteres usando el codigo ASCII
#include <iostream>

using namespace std;

int main() {
    // Declarar una variable de tipo char
    char letra = 'a';       // Guarda el valor de 97 de acuerdo al codigo ASCII
    char letra2 = letra;    // Crea una copia de letra, es decir guarda el valor 97
    int  numero = letra;    // Crea una copia de letra y lo guarda como un entero de valor 97
    // Dependiendo del tipo de variable, la representacion
    // impresa de las variables es distinta.
    // Por ejemplo:
    // - Las variables char se imprimen como simbolos (letras)
    // - Las variables int se imprimen como numeros enteros
    cout << "El valor de letra es: " << letra << "\n";
    cout << "El valor de letra 2 es: " << letra2 << "\n";
    cout << "El valor de numero es: " << numero << "\n";

    // Manejos de caracteres usando los valores del codigo ASCII
    char letra3 = 'd';
    char letra4 = 'a';
    int resultado = 0;
    // Restar el valor de las variables char y guardarlo en la variable entera resultado
    resultado = letra3 - letra4;
    cout << "Al restar la letra 'a' de 'd' queda: " << resultado << "\n";
    // Sumar el valor de caracteres
    char numero_letra  = '7'; // Simbolo ASCII del 7
    char numero_letra2 = '2'; // Simbolo ASCII del 2
    int resultado2 = numero_letra +  numero_letra2;
    cout << "El resultado de sumar '7' + '2' = : " << resultado2 << "\n";

    // Convertir de ASCII a decimal
    // Por ejemplo:
    // '5' => 5
    // '2' => 2
    char numero_ascii   = '5';
    int  numero_decimal = 0;
    // numero_decimal = numero_ascii; NO funciona para convertirlo a decimal
    // Para convertir un numero ascii en entero, es necesario
    // restarle es valor ascii del '0'
    numero_decimal = numero_ascii - '0';
    cout << "El valor de '5' al convertirlo a decimal es: " << numero_decimal << "\n"; 


    return 0;
}