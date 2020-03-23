#include <iostream>

using namespace std;

int main() {
    int a;
    int b;
    cin >> a >> b;
    cout << a << " " << b << " ";
    int actual = (a + b) % 10;
    int previo = b;
    int cont = 1;
    while(actual != b || previo != a) {
        cout << actual << " ";
        int aux = actual;
        actual = (actual + previo) % 10;
        previo = aux;
        cont++;
    }
    cout << actual << "\n";
    cout << cont << "\n";


    return 0;
}