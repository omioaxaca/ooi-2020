// Implementacion de una cola
#include <iostream>
#include <vector>

// Directiva del preprocesador
// Durante compilacion sustituye MAX por 10000
// Definir el tamanio del vector que guardara a la cola
// con un valor suficiente para guardar todos los elementos
// que indique el problema.
#define MAX 10000

using namespace std;

int cola_inicio = 0;
int cola_fin    = 0;
vector<int> cola(MAX); // _ _ _ _ _ ... _ _ MAX
// Ejemplo:          1 2 3 4
// cola_inicio       ^
// cola final              ^

// indices           0 1 2 3 4 5 6 7 8 9
// valores           1 2 3 4 5 6 7 8 9 10
// cola_inicio      ^     
// cola final                          ^

// NOTA: Para optimizar el uso de la memoria se puede utilizar
// un arreglo circular, es decir una vez que se llega al final
// del arreglo regresar al inicio. cola_fin % MAX

// O(1)
bool empty() {
    if (cola_inicio == cola_fin)
        return true;
    return false;
}

// O(1)
void push(int a) {
    cola[cola_fin] = a;
    cola_fin++;
}

// O(1)
int top() {
    return cola[cola_inicio];
}

// O(1)
void pop() {
    cola_inicio++;
}


int main() {
    push(1);
    push(2);
    push(3);
    push(4);
    while(!empty()) {
        cout << top() << "\n";
        pop();
    }



    return 0;
}