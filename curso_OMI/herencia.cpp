//////////////////////////////////////////////////////////////////////////////////////////////
// https://omegaup.com/arena/problem/herencia
//
// Logica para resolver el problema:
// Enunciado clave: Si las monedas no pueden ser divididas en N partes idénticas, entonces
// las partes fueron divididas en lo más cercano posible a que fueran idénticas: cada parte
// difiere de la otra por una moneda, a lo mucho. En ese caso, la hija indica que tomo una
// de las partes más pequeñas para ella.
//
// La cantidad de monedas que sobra es la herencia que se repartira entre las hijas restantes,
// es decir: herencia = residuo / (hijas - 1)  <---- división entera
// Solo existen 2 casos que considerar:
// 1) Si la division es exacta, entonces la herencia que tomo la hija pequeña pudo haber sido
//    la misma que las otras hijas o una unidad menos (en caso que el total de monedas hubiera
//    sido un numero no divisible entre el total de hijas)
// 2) Si la division es inexacta, entonces el total inicial de monedas tambien era inexacto,
//    por lo que la hija pequeña solo pudo haber tomado la cantidad resultante al efectuar la
//    division entera de residuo / (hijas - 1)
//////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

int main() {
   int herencia = 0;
   int hijas = 0;
   int residuo = 0;
   int tot_min = 0;
   int tot_max = 0;

   cin >> hijas >> residuo;

   herencia = residuo / (hijas - 1);
   if (residuo % (hijas - 1) == 0) {
     tot_min = residuo + herencia - 1;
     tot_max = residuo + herencia;
   }
   else{
     tot_min = residuo + herencia;
     tot_max = tot_min;
   }

   std::cout << tot_min << " " << tot_max << '\n';

   return 0;
}
