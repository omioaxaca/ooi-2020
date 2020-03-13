#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int filas = 2;
    int columnas = 3;
    int matA[filas][columnas] = {{4, 1, 2}, {5, 0, 3}}; // vector< vector<int> > matA(2, vector<int>(3));
    int matB[filas][columnas] = {1, 2, 3, 4, 5, 6};

    // int cont = 0;
    // int cont2 = 10;
    // for (int i = 0; i < filas; i++) {
    //     for (int j = 0; j < columnas; j++) {
    //         matA[i][j] = cont++;
    //         matB[i][j] = cont2++;
    //     }
    // }

    vector<int> v;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            v.push_back(matA[i][j]);
        }
    }
    sort(v.begin(), v.end());
    int idx = 0;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matA[i][j] = v[idx];
            idx++;
        }
    }
    // matA
    // 0 1 2
    // 3 4 5

    // matB
    // 10 11 12
    // 13 14 15
    

    return 0;
}