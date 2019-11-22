#include <iostream>

using namespace std;

int suma(int num1, int num2) {
    int resultado = num1 + num2;
    return resultado;
}

double calcular_promedio(int cantidad) {
    double acumulador = 0;
    int numero;
    // El for hace 3 cosas:
    //  iniciar una variable (i = 0)
    //  ejecutar el cuerpo del for mientras la condicion sea verdadera (i < cantidad)
    //  incrementar la variable (i++)
    for (int i = 0; i < cantidad; i++) {
        cin >> numero;
        acumulador += numero; // acumulador = acumulador + numero
    }
    double promedio = acumulador / cantidad;
    return promedio;
}


int main() {

    // Funcion para sumar
    int a = 5;
    int b = 3;
    int c = suma(a, b);
    
    suma(5, 10); // el resultado se pierde, porque no se guardo en ningun lugar

    cout << c << "\n";
    cout << suma(2, 9) << "\n";
    cout << suma(5, 1) << "\n";
    // Funcion para sacar el promedio
    double promedio_1 = calcular_promedio(5);
    cout << promedio_1 << "\n";


    return 0;
}