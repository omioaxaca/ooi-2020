// https://omegaup.com/arena/ooi-2020-examen-1/#problems/El-Caracol
// Una posible solucion es simular cada dia el progreso del caracol,
// de tal forma que acumulemos la cantidad de metros avanzados y asi
// identificar cuando alcancemos el total del pozo. Al final, contar
// la cantidad de dias necesarios.
// Una mejor solucion es analizar el problema de forma matematica:
// Si consideramos que el ultimo dia el caracol no necesita regresar,
// dado que ya se encuentra fuera del pozo, eso significa que el ultimo
// dia se pueden avanzar s metros. Por lo tanto, los dias anteriores
// el caracol solo tiene que avanzar a lo mucho p - s metros.
// Tomando en cuenta que cada dia se avanzan s metros y se retroceden r,
// eso significa que en total al dia se avanzan s - r metros.
// Finalmente, para saber cuantos dias son necesarios hacemos una division
// dias = (p - s) / (s - r)
// Si la division tiene residuo, redondeamos el resultado hacia arriba.
// Esto significa por ejemplo, que el caracol saldria del pozo en 2.4 dias,
// pero eso se redondea a decir que el caracol sale en 3 dias.
// Finalmente, al resultado de la division le sumamos el ultimo dia.
// Ejemplo: 
// p = 10, s = 5, r = 2
// (p - s) = (10 - 5) = 5
// (s - r) = (5  - 2) = 3
// (p - s)/(s - r) = 1.66, esto lo redondeamos a 2
// La respuesta es 2 + el ultimo dia, es decir 3
#include <iostream>

using namespace std;

int main() {
    int p = 0;
    int s = 0;
    int r = 0;
    cin >> p >> s >> r;
    // Al menos necesitamos un dia para salir
    // asi que empezamos la cuenta en 1, correspondiente
    // al ultimo dia.
    int diasParaSalir = 1;
    int distanciaAntesDelUltimoDia = (p - s);
    int distanciaTotalDiaria       = (s - r);
    // Si la distancia antes del ultimo dia es menor o igual que 0,
    // eso significa que desde el primer dia se puede salir. Asi que
    // la respuesta es 1 y no necesitamos hacer mas calculos.
    if (distanciaAntesDelUltimoDia > 0) {
        diasParaSalir += distanciaAntesDelUltimoDia / distanciaTotalDiaria;
        // Si la division no es exacta, eso significa que
        // tiene parte decimal, por lo tanto sumamos 1 dia.
        if (distanciaAntesDelUltimoDia % distanciaTotalDiaria != 0) {
            diasParaSalir++;
        }
    }
    cout << diasParaSalir << "\n";

    return 0;
}