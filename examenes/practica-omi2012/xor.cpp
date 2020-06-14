// https://omegaup.com/arena/problem/XOR/#problems
// Solución:
// El problema se resume en encontrar todos los rangos, comprendidos entre i y j
// donde al aplicar XOR a los elementos se obtiene 0.
// La solución más simple es utilizar 2 ciclos anidados para probar con todos los rangos.
// Pero eso es cuadratico y no entra en tiempo.
// Una mejor solución se obtiene al utilizar un barrido.
// Dada la propiedad asociativa de la operacion XOR, podemos plantear la siguiente relación:
// xor(x) = A_0 ^ A_1 ^ ... ^ A_x
// lo cual significa que xor(x) representa el resultado de hacer XOR a todo el rango desde 0 hasta x.
// Esto nos ayuda a hacer un precalculo de todos los rangos que comienzan en 0 y terminan en x.
// Para obtener el valor de xor entre i y j, es necesario encontrar la operacion inversa del XOR
// y aplicarla a xor(j) y xor(i).
// Por ejemplo, si en vez de utilizar XOR se utilizara una suma. La operacion inversa es la resta,
// por lo que se puede afirmar lo siguiente:
// sumatoria(i, j) = sumatoria(j) - sumatoria(i - 1)
// Es claro que si a la sumatoria desde 0 hasta j, se le resta la sumatoria desde 0 hasta i-1, se obtiene
// la sumatoria entre i y j.
// 0     i     j
// 2  6  1  5  3
// sumatoria(j)   = 2 + 6 + 1 + 5 + 3 = 17
// sumatoria(i-1) = 2 + 6             =  8
// sumatoria(i,j) =         1 + 5 + 3 =  9
// Lo cual es lo mismo que 17 - 8 = 9
// Regresando al tema del XOR, se puede aplicar la misma propiedad. Lo unico diferente es
// la operacion inversa del XOR, el cual es el mismo XOR. Por lo que podemos crear la funcion
// xor_rango(i,j) = xor(j) ^ xor(i - 1)
// Dado que se buscan todos los rangos cuyo resultado al aplicar XOR a todos los rangos sea 0, se tiene:
// xor_rango(i,j) = 0
// 0 = xor(j) ^ xor(i - 1)
// Al despejar esta ecuacion se tiene:
// xor(j) ^ 0 = xor(i - 1)
// Dado que hacer XOR a cualquier numero con 0, resulta en el mismo numero, entonces:
// xor(j) = xor(i - 1)
// Por lo que el problema se reduce en lo siguiente:
// Para cada valor xor(j), la cantidad de valores xor(i-1) encontrados
// representa la cantidad de rangos diferentes posibles.
// La solucion es recorrer el arreglo de valores y aplicar xor a cada valor,
// y en casa paso utilizar una cubeta para memorizar el resultado actual. Luego revisar esa cubeta
// para saber la cantidad de rangos distintos.
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Dada la cantidad de datos, es necesario usar la optimizacion de cin y cout.
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int numeros;
    cin >> numeros;

    // Crear cubeta para guardar los datos. El numero mas grande posible es 1,000,000.
    // Pero al usar XOR con otros numeros, el resultado puede mas grande, pero no mayor que 2,000,000.
    vector<int> cubeta(2000003,0);
    unsigned int xor_acumulado = 0;
    int numero;
    int rangos = 0;

    for (int j = 0; j < numeros; j++) {
        // Leer el numero.
        cin >> numero;
        // Calcular el xor acumulado, desde la posicion 0 hasta i.
        xor_acumulado = xor_acumulado ^ numero;
        // Basado en la funcion xor_rango(i,j) = xor(j) ^ xor(i-1), es decir xor(j) = xor(i-1)
        // revisamos si en anteriormente ya encontramos un resultado con el valor actual.
        rangos += cubeta[xor_acumulado];
        // Si el rango actual, por si mismo, da 0. Entonces lo contamos por si solo.
        if (xor_acumulado == 0) {
            rangos++;
        }
        // Guardamos en la cubeta este resultado, asi podemos revisarlo en el futuro.
        cubeta[xor_acumulado]++;
    }

    cout << rangos << "\n";

    return 0;
}