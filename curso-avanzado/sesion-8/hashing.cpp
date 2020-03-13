#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Crear un codigo unico (o con muy pocas colisiones)
// aplicando operaciones matematicas, que nos permita
// simplificar o representar de una manera mas practica
// un valor.
int mi_hash(string s) {
    int codigo = 0;
    for (int i = 0; i < s.length(); i++) {
        codigo += (int)s[i];
    }
    codigo -= (int)s[0];
    codigo = codigo % 537;
    return codigo;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // Contar la cantidad de veces que aparece cada numero entero positivo.
    // 0 1 4 6 2 9 67 34 12 10 2 3 4 1
    // vector<int> frec(n);
    // frec[num]++;
    // indices: 0   1   2   3   4 ...
    // valores: 1   2   2   1   2 ...

    // Contar la cantidad de veces que aparece cada numero entero (puede ser positivo o negativo).
    // 0 1 4 6 -2 9 67 -34 -12 10 -2 3 4 1
    // vector<int> frecPositivas(n);
    // vector<int> frecNegativas(n);
    // if (num >= 0)
    //    frecPositivas[num]++;
    // else
    //    frecNegativas[(num * -1)]++;

    // n es el numero absoluto mas grande que puede existir en el problema (-10 hasta 10)
    int n = 10;
    vector<int> valores = {0, -1, 2, 1, 3, -1, 2};
    vector<int> frecPos(n);
    vector<int> frecNeg(n);

    // Contar la frecuencia
    for (int i = 0; i < valores.size(); i++) {
        if (valores[i] >= 0) {
            frecPos[valores[i]]++;
        }
        else {
            // Guardar en un segundo arreglo la frecuencia
            // de los numeros negativos.
            frecNeg[valores[i] * -1]++;
        }
    }
    // Imprimir la frecuencia
    for (int i = 0; i < valores.size(); i++) {
        if (valores[i] >= 0) {
            cout << valores[i] << " : " << frecPos[valores[i]] << "\n";
        }
        else {
            cout << valores[i] << " : " << frecNeg[valores[i] * -1] << "\n";
        }
    }

    // Contar la cantidad de veces que aparece cada palabra.
    // Codigo   Valor
    // 0        "Daniel"
    // 1        "Nicolas"
    // 2        "Oaxaca"
    // 3        "a"

    // Daniel viene a Oaxaca a visitar a Nicolas la proxima semana, pero Nicolas no estara.

    // Arreglo
    // indice representa el codigo de la palabra
    // contenido reprenta la cantidad de veces que aparece
    // indices (codigos):    0    1   2   3
    // valores (frecuencia): 1    2   1   3
    

    vector<string> palabras = {"Daniel", "viene", "a", "Oaxaca", "a", "visitar", "a", "Nicolas", "la", "proxima", "semana", "pero", "Nicolas", "no", "estara"};
    vector<int> frecPalabras(1000);
    for (int i = 0; i < palabras.size(); i++) {
        int codigo = mi_hash(palabras[i]);
        frecPalabras[codigo]++;
    }

    for (int i = 0; i < palabras.size(); i++) {
        int codigo = mi_hash(palabras[i]);
        cout << palabras[i] << " : " << frecPalabras[codigo] << "\n";
    }

    cout << "Hashing de Daniel: " << mi_hash("Daniel") << "\n";
    cout << "Hashing de Oaxaca: " << mi_hash("Oaxaca") << "\n";



    return 0;
}