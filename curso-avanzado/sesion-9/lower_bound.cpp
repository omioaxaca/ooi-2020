// Dado un arreglo ordenado de forma ascendente de numeros enteros,
// encuentra el valor mas pequeño que sea mayor que x.
// Ejemplo:
// x = 9
// indices   : 0   1   2   3   4   5   6
// valores   : 2   6   7   11  19  24  31
// f(a, x)   : F   F   F   V   V   V   V
#include <iostream>
#include <vector>

using namespace std;

// Regresa verdadero si a es mayor que x.
bool f(int a, int x) {
    if (a > x) {
        return true;
    }
    return false;
}
// Regresar la posicion del primer elemento del arreglo
// que sea verdadero al evaluar la funcion f(ai, x).
// Donde, f(ai, x) regresa verdadero si ai es mayor que x.
// La funcion regresa -1 en caso de no encotrar ningun elemento
// que cumpla la condicion.
int lower_bound(vector<int> valores, int x) {
    int ini = 0;
    int fin = valores.size() - 1;
    while (ini < fin) {
        int mitad = ini + (fin - ini) / 2;
        if (f(valores[mitad], x) == true) {
            fin = mitad;
        }
        else {
            ini = mitad + 1;
        }
    }
    if (f(valores[ini], x) == true) {
        return ini;
    }
    return -1;
}

int main() {
    int x;
    vector<int> valores = {2, 6, 7, 11, 19, 24, 31};
    cin >> x;
    int res = lower_bound(valores, x);
    cout << res << "\n";

    return 0;
}