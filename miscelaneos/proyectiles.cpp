#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Coordenada {
    unsigned int x;
    unsigned int y;
};

// Ordenar por x y luego por y, de menor a mayor
bool cmp(Coordenada a, Coordenada b) {
    if (a.x == b.x) {
        return a.y < b.y;
    }
    return a.x < b.x;
}

bool busqBin(const vector<Coordenada>& proyectiles, Coordenada nuevo) {
    int ini = 0;
    int fin = proyectiles.size() - 1;
    while (ini <= fin) {
        int mit = ini + (fin - ini) / 2;
        if (proyectiles[mit].x == nuevo.x) {
            if (proyectiles[mit].y == nuevo.y) {
                return true;
            }
            else if(proyectiles[mit].y > nuevo.y) {
                fin = mit - 1; 
            }
            else {
                ini = mit + 1;
            }
        }
        else if(proyectiles[mit].x > nuevo.x) {
            fin = mit - 1;
        }
        else {
            ini = mit + 1;
        }
    }
    return false;
}

int main() {
    int n;
    int k;
    cin >> n >> k;

    vector<Coordenada> proyectiles(n);
    for (int i = 0; i < n; i++) {
        cin >> proyectiles[i].x >> proyectiles[i].y;
    }

    // Ordenar primero por x y luego por y
    sort(proyectiles.begin(), proyectiles.end(), cmp);
    
    for (int i = 0; i < k; i++) {
        Coordenada nuevo;
        cin >> nuevo.x >> nuevo.y;
        if (busqBin(proyectiles, nuevo) == true) {
            cout << "0\n";
        }
        else {
            cout << "1\n";
        }
    }


    return 0;
}