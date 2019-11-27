/*
    Problema: https://omegaup.com/course/Curso-OMI/assignment/COMI-programacion#problems/COMI-Traductor
*/
#include <iostream>
#include <vector>

using namespace std;


int main() {

    int ncamiones, npreguntas;

    // Leemos numero de camiones y numero de preguntas
    cin >> ncamiones >> npreguntas;

    // Declaramos un variable auxiliar para leer el número de alumnos
    // por camión
    int nalumnos;
    // Declaramos un vector de enteros para guardar el número
    // de alumnos por camión
    vector<int> camiones;

    // Por cada camion
    for (int i = 0; i < ncamiones; i++) {
        // Leemos el número de alumnos en el camión i
        cin >> nalumnos;
        // Guardamos en el vector el número de alumnos
        // del camión i
        camiones.push_back(nalumnos);
    }

    // Variable auxiliar para leer el camión de la pregunta
    int camion;
    // Por cada pregunta
    for (int i = 0; i < npreguntas; i++) {
        // Leemos el camión que se nos pide
        cin >> camion;
        // Imprimimos la cantidad de alumnos en el camion
        // que se nos preguntó
        // Como en el vector se indexa desde cero
        // restar 1 al número de camión que se nos pide
        cout << camiones[camion - 1] << endl;
    }

    return 0;
}
