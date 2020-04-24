# Curso final de la OOI 2020

## Sesión 18
Fecha: 23/04/2020

# Temas
- Continuacion DFS
- Introducción a backtracking

# Ejercicios

## DFS
Ejemplo: Encontrar todas las sumas posibles **diferentes** mayores o iguales a `x` en un vector.
Entrada:
```
{1, 4, 5}
x = 5
```
Salida:
```
5, 6, 9, 10
```

## Backtracking
Ejemplo: Encontrar la suma mas grande **menor o igual** a `x` en un vector e imprimir la forma en que se llega al resultado.
Fuente: Problema del CD https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=565

Entrada:
Primera linea indica `x`
Segunda linea es la cantidad de elementos en el vector
Siguiente linea contiene los valores del vector

```
5
3
1  3  4

1 + 4 = 5
```
```
10
4
9  8  4  2

8 + 2 = 10
```
```
20
4
10  5  7  4

10 + 5 + 4 = 19
```
```
90
8
10  23  1  2  3  4  5  7

10 + 23 + 1 + 2 + 3 + 4 + 5 + 7 = 55
```
```
45
8
4  10  44  43  12  9  8  

4 + 10 + 12 + 9 + 8  = 45
```

### Solución
Usar backtracking para generar todas las sumas posibles y elegir la mejor.
