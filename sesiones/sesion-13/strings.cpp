#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // Decaracion un string
    string palabra;
    // Declaración de un string con texto
    string palabra2 = "Este es un string :)";

    cout << palabra2 << endl;

    // Obteniendo el tamaño del string
    cout << "El tamaño de la string: " << palabra2 << " es: " << palabra2.size() << endl;

    // Imprimimos cada caracter del string
    for (int i = 0; i < palabra2.size(); i++) {
        cout << palabra2[i] << endl;
    }

    // Modificando un caracter del string
    palabra2[0] = 'I';
    cout << palabra2 << endl;

    // Si está estre comillas dobles es un string
    // palabra2[0] = "E"; // esto no es válido

    sort(palabra2.begin(), palabra2.end());
    cout << palabra2 << endl;

    return 0;
}
