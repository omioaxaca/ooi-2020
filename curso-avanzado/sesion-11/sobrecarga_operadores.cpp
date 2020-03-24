// Sobrecarga de operadores
// Overload
#include <iostream>
#include <string>

using namespace std;

struct Persona {
    string nombre;
    int edad;
};

// Sobrecarga del operador > para "enseñarle" al compilador
// a diferenciar que variable es mayor para tipos de datos
// personalizados.
bool operator>(Persona a, Persona b) {
    if(a.edad < b.edad) {
        return true;
    }
    return false;
}

int main() {
    Persona a = {"Abigael", 15};
    Persona b = {"Daniel", 17};

    // Decidir que persona es mayor que la otra basado en la edad
    if (a > b) {
        cout << a.nombre << " es mayor.";
    }
    else {
        cout << b.nombre << " es mayor.";
    }


    return 0;
}