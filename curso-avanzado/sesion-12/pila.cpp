// Estructura de datos: Pila (Stack)
// Estructura LIFO (Last In - First Out) -> Ultimo en entrar - Primero en salir
// Complejidad de las operaciones:
// push  O(1)
// top   O(1)
// pop   O(1)
// empty O(1)
#include <iostream>
#include <stack> // Libreria que implementa una pila

using namespace std;

int main() {
    // Crear una pila de enteros.
    stack<int> pila;
    // Insertar los valores 1, 2 y 3 en una pila
    pila.push(1);
    pila.push(2);
    pila.push(3);

    // Revisar si la pila contiene datos
    // el metodo empty() regresa verdadero si la pila esta vacia
    if (pila.empty() == true) {
        cout << "La pila esta vacia\n";
    }
    else {
        cout << "La pila NO esta vacia\n";
    }

    // Acceder al elemento de hasta arriba
    cout << "El elemento de hasta arriba de la pila es: " << pila.top() << "\n"; // 3
    
    // Extraer (sacar, eliminar) el elemento de hasta arriba
    pila.pop(); // 3

    // Insertar otro elemento
    pila.push(4); // 1, 2, 4

    // Vaciar la pila
    cout << "Contenido de la pila:\n";
    while (pila.empty() == false) {
        cout << pila.top() << "\n";
        pila.pop();
    }

    // Verificar si la pila esta vacia
    if (pila.empty() == true) {
        cout << "La pila esta vacia\n";
    }
    else {
        cout << "La pila NO esta vacia\n";
    }

    return 0;
}