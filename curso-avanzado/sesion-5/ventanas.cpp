#include <iostream>
#include <vector>

using namespace std;

int n;
// vector<vector<int> > ventanas(n, vector<int>(4)); // Matriz de n filas y 4 columnas
int ventanas[n][5] = {0};
// Para saber si esta cerrada:
// Idea 1: Hacer todas las coordenadas 0.
// Idea 2: Usar una columna adicional para saber si esta abierta o cerrada


bool ventana_libre(int indice_ventana) {
    // Implementar
}

// Regresar verdadero si la ventana b cubre a la ventana a
bool ventana_bloqueada(int ventana_a, int ventana_b) {

}

// Cierra la ventana que recibe como parametro
// y regresa la cantidad de clicks que se tuvieron que dar.
int cerrar_ventana( int indice_ventana ) {
    // Casos bases
    // Verificar si la ventana ya esta cerrada
    if (ventanas[indice_ventana][4] == 1) {
        // Si ya esta cerrada regresamos 0
        return 0;
    }
    // Esta ventana esta libre?
    if ( ventana_libre(indice_ventana) ) {
        ventanas[indice_ventana][4] = 1; // La ventana esta cerrada
        return 1;
    }
    // Paso recursivo
    // Iterar en todas las ventanas que se abrieron despues de la actual,
    // y cerrar aquellas que la bloqueen.
    int clicks = 0;
    for (int otra_ventana = indice_ventana + 1; otra_ventana < n; otra_ventana++) {
        if (ventana_bloqueada(indice_ventana, otra_ventana)) {
            clicks += cerrar_ventana(otra_ventana);
        }
    }
    clicks++; // 1 click para cerrar la ventana actual
    return clicks;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ventanas[i][0] >> ventanas[i][1] >> ventanas[i][2] >> ventanas[i][3];
        ventanas[i][4] = 0; // La ventana NO esta cerrada
    }

    // Primera llamada recursiva
    cout << cierra_ventana(0);
    


    return 0;
}