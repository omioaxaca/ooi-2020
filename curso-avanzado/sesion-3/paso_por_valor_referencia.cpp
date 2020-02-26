// Parametros por valor y por referencia
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Funcion que recibe parametros por valor
void f(int x) {
    x++;
    cout << "x: " << x << "\n";
}

// Funcion que recibe parametros por referencia
void g(int& y) {
    y++;
    cout << "y: " << y << "\n";
}

// Funcion que recibe un arreglo por referencia
void ordenar(vector<int>& arr) {
    sort(arr.begin(), arr.end());
}

int main() {
    int a = 5;
    f(a);
    cout << "a: " <<  a << "\n";
    g(a);
    cout << "a: " <<  a << "\n";

    // Variable de tipo entero
    int b = 5;
    // Variable de tipo referencia a un entero (alias de un entero)
    int& c = b;
    cout << "c:" << c << "\n";
    c = 10;
    cout << "b:" << b << "\n";

    // Siempre una referencia se tiene que inicializar a un valor
    int d = 8;
    // int& e;  // No compila
    int &e = d; // Si compila

    // Demostracion de referencia a un vector
    // [Tipo de dato] [nombre de la variable] = [valor];
    // int             var                    =     5;
    // vector<int>     arr                    =   {1, 2, 3}
    // int&            var_ref                =     var;
    // vector<int>&    arr_ref                =     arr;
    vector<int> arr =  {1, 2, 3, 4};
    vector<int>& arr_ref = arr;
    for(int i = 0; i < arr_ref.size(); i++) {
        cout << arr_ref[i] << " ";
    }
    cout << "\n";

    // Ordenar un arreglo pasandolo como referencia
    vector<int> arr2 = {7, 5, 4, 2, 3, 1, 6};
    ordenar(arr2);
    for(int i = 0; i < arr2.size(); i++) {
        cout << arr2[i] << " ";
    }

    return 0;
}