// Busqueda en profundidad
// Depth First Search - DFS

// Concepto: Buscar en cada una de las posibilidades hasta explorar la mas profunda y verificar si es una respuesta,
// de lo contrario probar con otra posibilidad.

// Ejemplo: Encontrar todas las sumas posibles mayores o iguales a x en un vector.
// Entrada:
// {1, 4, 5}
// x = 5
// Salida:
// 5, 6, 9, 10

// Pseudo-codigo
// INICIO
//  Si el estado actual es una respuesta:
//      Hacer algo
//  Si el estado es invalido
//      Retornar
//  De lo contrario
//      Probar con todas las opciones disponibles y volver a llamar la funcion.
// FIN

#include <iostream>
#include <vector>

using namespace std;

// Funcion para realizar la DFS
void calcula_sumas(int pos, int sum, vector<int>& valores, int objetivo) {
    // Revisar si el estado actual es una respuesta
    if (sum >= objetivo) {
        cout << sum << " ";
    }
    // Revisar estado invalido
    if (pos >= valores.size()) {
        return;
    }
    // Probar con todas las opciones disponibles
    // a) NO incluir el elemento actual en la suma
    calcula_sumas(pos + 1, sum, valores, objetivo);
    // b) SI incluir el elemento actual en la suma
    calcula_sumas(pos + 1, sum + valores[pos], valores, objetivo);
    // NOTA: cuando se tienen varias opciones, se puede hacer los siguiente
    // for (int opcion = 0; opcion < opciones.size(); opcion++) {
    //      hacer algo con los valores de opciones[opcion]
    //      calcula_sumas(...)   
    // }
}

int main() {
    int n;
    int x;
    cin >> n >> x;
    vector<int> valores(n);
    for (int i = 0; i < valores.size(); i++) {
        cin >> valores[i];
    }
    calcula_sumas(0, 0, valores, x);


    return 0;
}


