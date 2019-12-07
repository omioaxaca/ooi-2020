#include <iostream>
#include <string>

using namespace std;

int main() {
    string palabra;

    // Lee una sola palabra
    cin >> palabra;
    cout << palabra << endl;

    // Lee la linea completa
    getline(cin, palabra);
    cout << palabra << endl;

    return 0;
}
