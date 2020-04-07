#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Coordenada {
    unsigned int x;
    unsigned int y;
};

bool operator<(Coordenada a, Coordenada b) {
    if (a.x == b.x) {
        return a.y < b.y;
    }
    return a.x < b.x;
}

int main() {
    int n;
    int k;
    cin >> n >> k;

    map<Coordenada, bool> proyectiles;
    // {x, y} -> bool
    // 3 2 -> true
    // 1 3 -> true
    // 2 2 -> true
    // 1 4 -> true
    // 5 5 -> true
    for (int i = 0; i < n; i++) {
        Coordenada proyectil;
        cin >> proyectil.x >> proyectil.y;
        proyectiles[proyectil] = true;
    }

    for (int i = 0; i < k; i++) {
        Coordenada proyectil;
        cin >> proyectil.x >> proyectil.y;
        if (proyectiles[proyectil] == true) {
            cout << "0\n";
        }
        else {
            cout << "1\n";
        }
    }


    return 0;
}