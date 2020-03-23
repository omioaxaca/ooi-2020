// https://omegaup.com/arena/ooi-2020-examen-1/#problems/N-Impares
// Para este problema la solucion es simplemente iterar a traves
// de los primeros N numeros impares y acumular suma.
// Nota: Dado que el valor mas grande de N es 1000000, debemos
//       utilizar una variable de tipo long long int para almacenar
//       la suma. Esto es debido a que la respuesta a 1000000 es
//       1000000000000. Dicho numero no cabe en un int.
#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    long long int suma = 0;
    int impar = 1;
    for (int contador = 0; contador < N; contador++) {
        suma += impar;
        impar += 2;
    }
    cout << suma << "\n";
}