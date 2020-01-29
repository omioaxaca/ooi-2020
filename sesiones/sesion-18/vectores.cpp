#include <iostream>
#include <vector>

using namespace std;

void imprime_vector(vector<int> v) {
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
}

int main() {
    // Un vector es una estructura de datos que guardar informacion como una lista
    // Ejemplo: {1, 2, 3, 4, 5}
    //          {"daniel", "gato", "manzana", "ooi"}
    // Declarar un vector vacio
    vector<int> mi_vector;          // {}
    // Declarar un vector de 5 elementos e iniciar todos a su valor por defecto, para numeros es 0
    vector<int> mi_vector2(5);      // {0, 0, 0, 0, 0}
    // Declarar un vector de 5 elementos e iniciar cada elemento al valor especificado
    vector<int> mi_vector3(5, 1);   // {1, 1, 1, 1, 1}
    // Declarar un vector y especificar su contenido
    vector<int> mi_vector4 = {1, 2, 3, 4, 5}; // {1, 2, 3, 4, 5}
    cout << "Contenido del vector 1: ";
    imprime_vector(mi_vector);
    cout << "Contenido del vector 2: ";
    imprime_vector(mi_vector2);
    cout << "Contenido del vector 3: ";
    imprime_vector(mi_vector3);
    cout << "Contenido del vector 4: ";
    imprime_vector(mi_vector4);

    // Insertar datos a un vector se utiliza el metodo push_back()
    mi_vector.push_back(8);
    mi_vector.push_back(10);
    cout << "Contenido del vector 1: ";
    imprime_vector(mi_vector);
    
    // Para acceder a una posicion del vector debemos utilizar un indice, que empieza en 0
    cout << "El vector 4 en la posicion 2 tiene el valor: " << mi_vector4[1];

    return 0;
}