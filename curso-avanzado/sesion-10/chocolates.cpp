// Chocolates CIIC 2015
// https://omegaup.com/arena/ooi-2020-marzo/admin/#problems/Chocolates-CIIC-2015
// Busqueda binaria avanzada.

// Entrada:
// 6
// 4
// 1
// 3
// 5

// Simulacion:

// Chocolate que se come por dia: 1
// Dia  ChocolateNuevo  TotalChocolate  ChocolateRestante
// 1    6               6               5              
// 2    4               9               8
// 3    1               9               8
// 4    3               11              10
// 5    5               15              14
// Chocolate comido: 5


// Chocolate que se come por dia: 2
// Dia  ChocolateNuevo  TotalChocolate  ChocolateRestante
// 1    6               6               4               
// 2    4               8               6
// 3    1               7               5
// 4    3               8               6
// 5    5               11              9
// Chocolate comido: 10

// Chocolate que se come por dia: 3
// Dia  ChocolateNuevo  TotalChocolate  ChocolateRestante
// 1    6               6                3
// 2    4               7                4
// 3    1               5                2
// 4    3               5                2
// 5    5               7                4
// Chocolate comido: 15

// Chocolate que se come por dia: 4
// Dia  ChocolateNuevo  TotalChocolate  ChocolateRestante
// 1    6               6               2
// 2    4               6               2
// 3    1               3               -1 NO hay chocolate suficiente
// 4    3                               
// 5    5                               
// Chocolate comido: NO ES POSIBLE

// Chocolate que se come por dia: 5
// Dia  ChocolateNuevo  TotalChocolate  ChocolateRestante
// 1    6               6               1
// 2    4               5               0
// 3    1               1               -4 NO hay chocolate suficiente
// 4    3                               
// 5    5                               
// Chocolate comido: NO ES POSIBLE

// Conclusion:
// Es posible comer diariamente una cantidad de chocolates que ente en el rango [1, 3].
// Es decir, si se intenta comer una cantidad de chocolates mayor a 3, no es posible comer
// diariamente esa cantidad.

// Solucion 1: Busqueda lineal
// Probar con cada una de las cantidades diarias POSIBLES y elegir la mayor.
// Complejidad: O(cantidad_diaria_maxima * dias)
//              total_chocolates = 10e9 * 10e5 = 10e14
//              cantidad_diaria_maxima = total_chocolates / dias = 10e14 / 10e5 = 10e9
//              O(10e9 * 10e5) = O(10e14)
// No entra en tiempo.
#include <iostream>
#include <vector>

using namespace std;

typedef long long int lli;

// Valida si es posible comer esta cantidad de chocolate diariamente.
bool es_posible(vector<int>& chocolates, lli cantidad) {
    int chocolate_total = 0;
    for (int i = 0; i < chocolates.size(); i++) {
        chocolate_total += chocolates[i];
        chocolate_total = chocolate_total - cantidad;
        // Si no hay chocolate suficiente, regresamos falso
        // ya que no es posible comer diariamente esta
        // cantidad de chocolate.
        if (chocolate_total < 0) return false;
    }
    return true;
}

int main() {
    int dias;
    cin >> dias;
    vector<int> chocolates(dias);
    lli chocolate_total = 0;
    for (int i = 0; i < chocolates.size(); i++) {
        cin >> chocolates[i];
        chocolate_total += chocolates[i];
    }

    // La cantidad maxima posible (ideal) seria la suma de todo el chocolate
    // entre la cantidad de dias.
    lli cantidad_diaria_maxima = chocolate_total / dias + 1;
    // Variable para guardar la respuesta.
    lli cantidad_diaria_posible = 0;
    for (lli cantidad = 0; cantidad <= cantidad_diaria_maxima; cantidad++) {
        if (es_posible(chocolates, cantidad)) {
            if (cantidad > cantidad_diaria_posible) {
                cantidad_diaria_posible = cantidad;
            }
        }
    }

    cout << cantidad_diaria_posible << "\n";

    return 0;
}

