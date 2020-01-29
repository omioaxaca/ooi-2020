#include <iostream>
#include <string>

using namespace std;

int main() {
    // Un string es un arreglo de caracteres, es decir un vector que contiene caracteres
    // Los strings se representan entre comillas dobles (" ")
    // Por ejemplo:
    // "perro"
    // "gato"
    // "manzana"
    // Se representan en la computadora de la siguiente forma:
    // "perro" --> {'p', 'e', 'r', 'r', 'o'}

    // Declarar un string vacio
    string mi_string;               // "" es decir {}
    // Declarar un string con contenido
    string mi_string2 = "perro";    // "perro" es decir {'p', 'e', 'r', 'r', 'o'}
    // NOTA: Lo de arriba, seria exactamente lo mismo que hacer
    // vector<char> mi_vector = {'p', 'e', 'r', 'r', 'o'};

    cout << "El contenido del string 1 es: " << mi_string << "\n";
    cout << "El contenido del string 2 es: " << mi_string2 << "\n";

    // Para acceder a un elemento especifico del string
    // se utilizan corchetes y un indice
    cout << "El valor del string en la segunda posicion es: ";
    cout << mi_string2[1] << "\n";

    // Concatenar strings, es decir unir sus valores
    string palabra1 = "hola";
    string palabra2 = "mundo";
    string palabras_juntas;
    palabras_juntas = palabra1 + " " + palabra2 + " :)";
    cout << "Palabras unidas: " << palabras_juntas;


    return 0;
}