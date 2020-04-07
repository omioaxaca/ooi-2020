#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    vector<int> datos =  {1, 5, 9, 2, 4, 3, 6, 10, 8, 7, 1, 5, 6, 6, 7};
    set<int> mi_set;
    // Insertar los datos en un set.
    // Esta estructura remueve duplicados y ordena los datos por defecto.
    for (int i = 0; i < datos.size(); i++) {
        mi_set.insert(datos[i]);
    }

    // Recorrer el set
    // Necesita un iterador para recorrer cada posicion del set.
    // Que es un iterador? Es un puntero que almacena la direccion de memoria a la que apunta.
    // <tipoDato>::iterator <nombreIterador>
    // set<int>::iterator it;  // <-- asi se declara un iterador a un set de enteros
    // Para recorrerlo, apuntamos al inicio (begin y luego aumentamos el iterador
    // hasta llegar al fin (end). Nota, cuando llegamos al fin es cuando it == end()
    for(set<int>::iterator it = mi_set.begin(); it != mi_set.end(); it++) {
        // Imprimir el valor al que apunta el iterador,
        // para esto necesitamos recuperar el valor al que apunta el iterador.
        // Esto se consigue utilizando el operador de desreferenciacion.
        cout << *it << " ";
    }

    return 0;
}