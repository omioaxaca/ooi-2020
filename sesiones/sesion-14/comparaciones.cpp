// Programa para resolver el problema https://omegaup.com/course/Curso-OMI/assignment/COMI-PractA#problems/comparaciones
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Declarar un vector de enteros de 5 elementos
    vector<int> numeros(5); // {0, 0, 0, 0, 0}
    // Leer los datos
    for (int i = 0; i < 5; i++) {
        cin >> numeros[i];
    }
    // Ejemplo de como quedaria el vector despues de leer los datos:
    // numeros => {5, 87, 4, 4, 2}

    // Ordenar los numeros
    sort(numeros.begin(), numeros.end());
    // Ejemplo del vector despues de ordenar:
    // indices =>  0   1   2   3   4
    // numeros => {2,  4,  4,  5,  87}

    // Esta variable nos permite guardar la cantidad mas grande de
    // numeros iguales que encontremos.
    int cantidadMayorDeIguales = 0;
    // Revisar cuantos elementos son iguales a cada uno de los valores.
    for (int i = 0; i < 5; i++) {
        int elementoActual = numeros[i];
        // Contador para guardar cuantos elementos son iguales al valor de elementoActual
        int contadorDeIguales = 0;
        // Incrementar el contador mientras el elemento actual sea igual al valor apuntado
        // por el indice i
        while(i < 5 && elementoActual == numeros[i]) {
            contadorDeIguales++;
            i++;
        }
        // Retroceder una posicion para no perder la comparacion de ese elemento
        // debido a que el ciclo for incrementa en 1 el valor de i.
        i--;
        // Comparar si el contador del elemento actual es mas grande que la cantidad
        // de valores iguales encontrados hasta este momento.
        if (contadorDeIguales > cantidadMayorDeIguales) {
            cantidadMayorDeIguales = contadorDeIguales;
        }
    }
    if (cantidadMayorDeIguales == 5) {
        cout << "Identicamente iguales\n";
    }
    else if(cantidadMayorDeIguales == 4) {
        cout << "Muy iguales\n";
    }
    else if(cantidadMayorDeIguales == 3) {
        cout << "Iguales\n";
    }
    else if(cantidadMayorDeIguales == 2) {
        cout << "Diferentes\n";
    }
    else {
        cout << "Muy diferentes\n";
    }


    return 0;
}
