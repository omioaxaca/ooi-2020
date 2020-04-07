#include <iostream>
#include <vector>
#include <algorithm>
#include <set> // Conjunto, guarda elementos unicos en forma ordenada.

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
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    int k;
    cin >> n >> k;

    set<Coordenada> proyectiles;
    // {x, y}
    // 3 2
    // 1 3
    // 2 2
    // 1 4
    // 5 5
    for (int i = 0; i < n; i++) {
        Coordenada proyectil;
        cin >> proyectil.x >> proyectil.y;
        // Guarda en el set este proyectil
        proyectiles.insert(proyectil);
    }

    for (int i = 0; i < k; i++) {
        Coordenada proyectil;
        cin >> proyectil.x >> proyectil.y;
        // Revisar si el proyectil ya existe en el set.
        // find(objetivo) regresa un iterador a la posicion donde esta el objetivo buscado,
        // pero si el objetivo no existe, entonces regresa un iterador apuntando al final
        // de la estructura.
        if (proyectiles.find(proyectil) != proyectiles.end()) {
            cout << "0\n";
        }
        else {
            cout << "1\n";
        }
    }


    return 0;
}