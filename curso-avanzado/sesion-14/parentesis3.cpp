// {[(4+6)*(5-5)]*(3)}
#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

// Este mapa guarda los simbolos que abren y los que cierran
// El primer valor es el que abre.
// El segundo es el que cierra.
map<char, char> simbolos;

bool es_simbolo_que_abre(char k) {
    for (auto valor : simbolos) {
        // first nos permite acceder a la llave.
        if (valor.first == k)
            return true;
    }
    return false;
}

bool es_simbolo_que_cierra(char k) {
    for (auto valor : simbolos) {
        // second nos permite acceder al valor.
        if (valor.second == k)
            return true;
    }
    return false;
}

bool es_pareja(char a, char b) {
    // char k = simbolos[a]; // Obtener el valor de cierre que corresponde al simbolo a
    // if (k == b)
    if (simbolos[a] == b)
        return true;
    return false;
}

// Funcion para verificar si la cadena de parentesis
// esta balaceada.
bool parentesis_balanceados(string s) {
    stack<char> pila;
    for (int i = 0; i < s.length(); i++) {
        // Si es un parentesis que abre, lo guardamos en la pila
        if (es_simbolo_que_abre(s[i])) {
            pila.push(s[i]);
        }
        // Si es un parentesis que cierra, buscamos en el tope de la pila
        // si existe un parentesis que abre.
        // ())
        else if (es_simbolo_que_cierra(s[i])) {
            // Si la pila esta vacia en este momento, entonces los
            // parentesis no estan balanceados. Es decir, existen mas
            // parentesis que cierran que los que abren. Ejemplo: ())
            if (pila.empty())
                return false;
            // Si existe un parentesis en la pila que abre, entonces
            // lo saco, ya que ya hemos encontrado su pareja.
            if (es_pareja(pila.top(), s[i])) {
                pila.pop();
            }
        }
    }
    // Si en este punto la pila no esta vacia significa que la cadena no
    // esta balanceada, porque existen mas parentesis que abren de los
    // que cierran. Ejemplo: (()
    if (!pila.empty())
        return false;
    return true;
}

int main() {
    string s;
    cin >> s;

    // Crear un mapa de simbolos
    // Tabla de simbolos
    // Llave    Valor
    // (         )
    // [         ]
    // {         }
    // map<llave, valor> nombreMapa;
    // Insertar o actualizar un elemento
    // nombreMapa[llave] = valor;
    simbolos['('] = ')';
    simbolos['['] = ']';
    simbolos['{'] = '}';

    if (parentesis_balanceados(s)) {
        cout << "SI\n";
    }
    else {
        cout << "NO\n";
    }

    return 0;
}