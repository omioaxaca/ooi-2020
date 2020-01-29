// Programa para contar la vocales dentro de un string
#include <iostream>
#include <string>

using namespace std;

int main() {
    string palabra = "olimpiada de informatica";
    cout << "La(s) palabra(s) dice: " << palabra << "\n";
    int contador_a = 0;
    int contador_e = 0;
    int contador_i = 0;
    int contador_o = 0;
    int contador_u = 0;
    // Tamanio del string
    int tam = palabra.length();
    cout << "Tamanio del string: " << tam << "\n";
    for(int i = 0; i < tam; i++) {
        if(palabra[i] == 'a') {
            contador_a++;
        }
        if(palabra[i] == 'e') {
            contador_e++;
        }
        if(palabra[i] == 'i') {
            contador_i++;
        }
        if(palabra[i] == 'o') {
            contador_o++;
        }
        if(palabra[i] == 'u') {
            contador_u++;
        }
    }
    cout << "La vocal a aparece " << contador_a << " veces.\n";
    cout << "La vocal e aparece " << contador_e << " veces.\n";
    cout << "La vocal i aparece " << contador_i << " veces.\n";
    cout << "La vocal o aparece " << contador_o << " veces.\n";
    cout << "La vocal u aparece " << contador_u << " veces.\n";

    return 0;
}