#include <iostream>
#include <vector>

using namespace std;

struct Dato {
    int x;
    int y;
};

int main() {
    int k;
    cin >> k;

    vector<Dato> resultados;

    for (int y = k + 1; y <= k * 2; y++) {
        if (k*y % (y-k) == 0) {
            int x = k*y / (y - k);
            if (x*y - k*x == k * y) {
                resultados.push_back({x, y});
            }
        }
    }

    // Imprimir los valores de los vectores
    cout << resultados.size() << "\n";
    for (int i = 0; i < resultados.size();i++) {
        int x = resultados[i].x;
        int y = resultados[i].y;
        cout << x << " " << y << "\n";
    }

    return 0;
}

