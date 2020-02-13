// Utilizar el material de https://ooi.gitbook.io/courses/ooi-2020/cursos-online/clase-17
// para crear un programa que haga lo siguiente:
// Imprimir la letra que aparece más veces en un string. Por ejemplo:
// Entrada: oso
// Salida: o

// Entrada: aaaaaaabcd
// Salida: a
// Solucion:
// Crear un arreglo que usaremos para guardar la ocurrencia de cada
// elemento del codigo ascii.
// Es decir, los indices del arreglo representaran el valor decimal
// de cada elemento ASCII.
// Lo que haremos sera contar la ocurrencia de cada letra y al final
// buscar cual es la que aparecio mas veces.
// Por ejemplo, para la letra A, el valor ASCII es 65. Por lo tanto,
// usaremos la posicion del arreglo en el indice 65 para guardar
// la cantidad de veces que aparece la letra A.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Crear un vector con espacio suficiente
    // para almacenar los primeros 256 caracteres ascii.
    // Al principio todo inicia en ceros, lo que significa que la ocurrencia
    // de cada letra es nula.
    vector<int> ascii(256);
    // Leer la palabra
    string palabra;
    cin >> palabra;
    // Iterar sobre cada letra de la palabra e incrementar
    // un contador en el arreglo ascii para contar la ocurrencia de cada letra.
    for (int i = 0; i < palabra.length(); i++) {
        ascii[palabra[i]]++;
    }
    // Al final, recorreremos el arreglo para encontrar cual es la letra
    // con mas ocurrencias.
    int mayor = 0;
    char letraMasRepetida;
    for (int i = 0; i < ascii.size(); i++) {
        if (ascii[i] > mayor) {
            mayor = ascii[i];
            letraMasRepetida = i;
        }
    }
    cout << letraMasRepetida << "\n";
    return 0;
}