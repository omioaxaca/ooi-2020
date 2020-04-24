# Backtracking (Algoritmo de vuelta atrás)

Backtracking es una técnica algorítmica para resolver problemas de forma recursiva al tratar de construir una solución de forma incremental, una pieza a la vez, eliminando aquellas soluciones que no satisfacen las limitaciones del problema en cualquier momento (aquí se hace referencia al tiempo el tiempo transcurrido hasta llegar a cualquier nivel del árbol de búsqueda).

## Tipos de backtracking
- Problema de decisión: en esto, buscamos si existe una solución.
- Problema de optimización: en esto, buscamos la mejor solución.
- Problema de enumeración: en este, encontramos todas las soluciones posibles.

## Detalles de implementación
El backtracking es un algoritmo muy parecido a DFS, ya que explora el espacio de búsqueda de forma exhaustiva y en profundidad. Los elementos más representativos del backtracking son los siguientes:
1. Trata de construir una *posible* solucion hasta que se demuestra que sí es válida o no.
2. Cuando el backtracking encuentra una solución, la guarda en algún contenedor y continua su búsqueda.
3. Si se demuestra que el estado actual no es una solución válida, la función da un paso atrás (backtrack), destruye los cambios hechos y continua explorando la siguiente posible solución.

## Pseudocódigo

```c++
void buscaSolucion(n, otros parametros) {
    if (solucion encontrada) {
        contadorSoluciones = contadorSoluciones + 1;
        // Hacer algo con la solucion

        if (contadorSoluciones satisface objetivo) {
            // Acabar backtracking
            return
        }
    }

    // Explorar las posibilidades
    for (val = valores posibles) {
        // Si es una posible solucion
        if (esValido(val, n)) {
            // Construir una pieza mas de la solucion
            aplicarValor(val, n);
            // Continuar con el siguiente valor posible
            buscaSolucion(n+1, otros params);
            // Cuando la funcion retorna, debemos destruir la pieza construida
            // antes.
            removerValor(val, n);
        }
    }
}
```

## Problemas sugeridos
- CD en UVA
- Sudoku en UVA
- Ranking the languages en UVA
- 8 reinas en Omegaup
- Camelot en Omegaup


Fuente https://www.geeksforgeeks.org/backtracking-introduction/