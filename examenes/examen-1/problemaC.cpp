// https://omegaup.com/arena/ooi-2020-examen-1/#problems/CALC_DIVISORES
// La solucion es simplemente calcular todos los divisores,
// para hacerlo probamos con todos los numeros desde 1 hasta N,
// aquellos que dividan exactamente a N son considerados divisores.
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    // Probar con todos los numeros entre 1 y n
    for (int i = n; i >= 1; i--) {
        // Si i divide exactamente a n, es decir, no hay residuo de la division,
        //  entonces i es un divisor de n.
        if(n % i == 0) {
            cout << i << "\n";
        }
    }

    return 0;
}