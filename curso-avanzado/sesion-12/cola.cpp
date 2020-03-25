// Estructura de datos Cola (Queue)
// Estructura FIFO (First In - First Out) -> Primero en entrar - Primero en salir
// Complejidad de las operaciones:
// push  O(1)
// front O(1)
// pop   O(1)
// empty O(1)
#include <iostream>
#include <queue> // Libreria que implementa una cola
#include <string>

using namespace std;

int main() {
    // Crear una cola de strings
    queue<string> cola;

    // Insertar los elementos: "Pedro", "Jorge", "Sara"
    cola.push("Pedro");
    cola.push("Jorge");
    cola.push("Sara");

    // Revisar si la cola contiene elementos
    // El metodo empty() regresa verdadero si la cola esta vacia
    if (cola.empty() == true) {
        cout << "La cola esta vacia\n";
    }
    else {
        cout << "La cola NO esta vacia\n";
    }

    // Acceder al elemento al frente de la cola
    cout << "Elemento al frente: " << cola.front() << "\n";

    // Extraer (sacar, eliminar) el elemento del frente
    cola.pop();

    // Insertar otro elemento
    cola.push("Javier");

    // Vaciar la cola
    cout << "Contenido de la cola:\n";
    while (cola.empty() == false) {
        cout << cola.front() << " ";
        cola.pop();
    }
    cout << "\n";

    // Verificar si la cola esta vacia
    if (cola.empty() == true) {
        cout << "La cola esta vacia\n";
    }
    else {
        cout << "La cola NO esta vacia\n";
    }



    return 0;
}