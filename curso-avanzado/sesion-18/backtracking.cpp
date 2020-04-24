#include <iostream>
#include <vector>

using namespace std;

// Variables globales para guardar el mejor resultado
int mejor_respuesta = 0;
vector<int> resultado;

void backtracking(int pos, int suma, int objetivo, vector<int>& posible_resultado, vector<int>& valores) {
    // Posible solucion encontrada
    // Si es mejor que la anterior encontrada, entonces
    // guardarla.
    if (suma <= objetivo && suma > mejor_respuesta) {
        mejor_respuesta = suma;
        resultado = posible_resultado;
    }

    // Continuar explorando con las siguientes opciones
    for (int i = pos; i < valores.size(); i++) {
        int opcion = valores[i];
        // Verificar si es una posible solucion
        if (suma + opcion <= objetivo) {
            // Construir posible solucion
            posible_resultado.push_back(opcion); // Insertar elemento al final del vector
            // Probar la posible solucion y continuar
            backtracking(i + 1, suma + opcion, objetivo, posible_resultado, valores);
            
            // Deshacer la solucion y explorar la siguiente posibilidad
            posible_resultado.pop_back(); // Eliminar el ultimo elemento del vector
        }
    }
}

int main() {
    vector<int> valores = {10, 5, 7, 4};
    int objetivo = 20;
    vector<int> posible_resultado;
    backtracking(0, 0, objetivo, posible_resultado, valores);

    for (auto& v : resultado) {
        cout << v << " ";
    }
    cout << mejor_respuesta << "\n";


    return 0;
}