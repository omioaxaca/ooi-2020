// Encontrar la suma de numeros contigua mas grande dentro del arreglo
// Entrada son numeros enteros positivos y negativos
// Ejemplo: [1, 2, 3, 4, -10]
// Salida: 10

// Ejemplo: 1, 4, -7, 9, -1, 3, 5
// Salida: 16

// Ejemplo: -2, 1, -3, 4, -1, 2, 1, -5, 4
// Salida:  6

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Declarar un vector global (es decir, puede ser accedido desde cualquier parte del codigo)
vector<int> numeros;

// Suma los elementos del vector del rango inicio a final
int suma(int inicio, int final) {
    int sum = 0;
    for(int i = inicio; i <= final; i++) {
        sum += numeros[i];
    }
    return sum;
}

int main() {
    // Leer la cantidad de numeros
    int cantidadNumeros;
    cin >> cantidadNumeros;
    // Leer los numeros
    for (int i = 0; i < cantidadNumeros; i++) {
        int n;
        cin >> n;
        numeros.push_back(n);
    }
    // Solucion 1: Probar todas las combinaciones de sumas posibles
    // Sumar todos los numeros entre inicio y final
    // donde inicio va a ser el inicio de mi rango
    // donde final va a ser el final de mi rango
    // Voy a mover a inicio y a final, de tal manera que abarque todo el arreglo

    int sumaMayor = INT_MIN; // Inicializar la suma mayor a un valor muy bajo
    for (int inicio = 0; inicio < cantidadNumeros; inicio++) {
        for (int final = inicio; final < cantidadNumeros; final++) {
            // Obtener el valor de suma del rango de inicio a final
            int sumaActual = suma(inicio, final);
            // Comprobar si la suma del rango actual es mayor que la variable sumaMayor
            if (sumaActual > sumaMayor) {
                sumaMayor = sumaActual;
            }
        }
    }

    cout << sumaMayor << "\n";


    return 0;
}