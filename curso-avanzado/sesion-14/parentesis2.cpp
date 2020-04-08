// {[(4+6)*(5-5)]*(3)}
#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool es_simbolo_que_abre(char k) {
    switch(k) {
        case '(':
        case '[':
        case '{':
            return true;
            break;
        default:
            return false;
            break;
    }
    return false;
}

bool es_simbolo_que_cierra(char k) {
    switch(k) {
        case ')':
        case ']':
        case '}':
            return true;
            break;
        default:
            return false;
            break;
    }
    return false;
}

bool es_pareja(char a, char b) {
    switch(a) {
        case '(':
            if (b == ')')
                return true;
            break;
        case '[':
            if (b == ']')
                return true;
            break;
        case '{':
            if (b == '}')
                return true;
            break;
        default:
            return false;
            break;
    }
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
    if (parentesis_balanceados(s)) {
        cout << "SI\n";
    }
    else {
        cout << "NO\n";
    }

    return 0;
}