// Dada una lista de equipos de futbol y su puntaje.
// Ordenalos de mayor a menor de acuerdo con la cantidad de puntos que tiene cada uno.
// Si hay empate, ordenar en orden alfabetico por nombre.
// Ejemplo:
// Chivas 1
// America 10
// Cruz azul 2
// Alebrijes 20
//
// Salida:
// Alebrijes 20
// America 10
// Cruz azul 2
// Chivas 1

// Solucion: Crear una estructura que me permita guardar el nombre y el puntaje.
// Crear un vector de mi nueva estructura y ordenarlo de mayor a menor basado en el puntaje.

// Crear nuevos tipos de dato usando struct:
// Sintaxis:
// struct NombreEstructura {
//    Declarar cada uno de los elementos en orden, utilizando la sintaxis normal
//    que se usa para declarar variables.
// };
// 
// Para usar la nueva estructura se utiliza la notacion normal como si fuera cualquier otro tipo de dato.
// NombreEstructura nombreVariable;
//
// Para acceder a cada uno de los elemento dentro de la estructura su usa el operador punto .
// Ejemplo:
// struct Coordenada {
//     int x;
//     int y;
// };
// Coordenada punto = {1, 5};
// cout << punto.x;
// cout << punto.y;


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Definir una estructura que nos permita guardar dos valores.
// Un string y un entero
struct Equipo {
    string nombre;
    int puntos;
};

// Funcion complemento para ordenar de mayor a menor utilizando sort.
bool cmp(Equipo a, Equipo b) {
    // Si los puntos son iguales, entonces regresa el menor
    // en orden alfabetico.
    if (a.puntos == b.puntos) {
        return a.nombre < b.nombre;
    }
    return a.puntos > b.puntos;
}

int main() {
    //==================================================================
    // Ejemplo uso de la estructura
    //
    // Inicializar la estructura usando lista de inicializacion
    Equipo mi_equipo = {"America", 10};
    // mi_equipo = {"Alebrijes", 8}; // No compila, porque la lista solo se puede utilizar cuando se inicializa.

    // Inicializar la estructura elemento por elemento
    Equipo otro_equipo;
    otro_equipo.nombre = "Chivas";
    otro_equipo.puntos = 20;
    //==================================================================
    // Resolucion del problema
    int puntuaciones = 0;
    cin >> puntuaciones;
    // Crear un vector que guarde Equipo
    vector<Equipo> equipos(puntuaciones);
    
    // Leer los datos
    for (int i = 0; i < puntuaciones;i++) {
        cin >> equipos[i].nombre >> equipos[i].puntos;
    }

    // Ordenar de mayor a menor basado en los puntos
    sort(equipos.begin(), equipos.end(), cmp);

    // Imprimir los datos en orden
    for (int i = 0; i < equipos.size(); i++) {
        cout << equipos[i].nombre << " " << equipos[i].puntos << "\n";
    }




    return 0;
}