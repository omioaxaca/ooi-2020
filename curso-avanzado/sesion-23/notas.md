# Curso final de la OOI 2020

## Sesión 23
Fecha: 12 de junio de 2020

# Temas
- Barrido

# Ejercicios

## Suma entre rangos
Dado un arreglo de elementos enteros positivos y negativos, encuentra la suma en el rango de `A` hasta `B`.

**Limites:**

Cantidad de elementos `n`.

Cantidad de consultas: `q`.

`1 <= n <= 1,000,000`

`1 <= q <= 1,000,000`


Ejemplo:
```
indices:  0  1  2   3   4   5   6   7   8   9
valor:    6  4 -5   7   8   -5  3   2   1   2

Rango: 3 al 7
Suma:  15

Rango: 0 al 4
Suma:  20

Rango: 0 al 9
Suma:  23

Rango: 0 al 9
Suma:  23

Rango: 0 al 9
Suma:  23
```

## Solucion
Fuerza bruta:
Recorrer el arreglo desde la posicion requerida (`A`) hasta el final del rango (`B`) y sumamos los valores.
Complejidad: `O(n)`.
Si la cantidad consultas es `q`, entonces la complejidad del programa es `O(q * n)`

Optimización:
Observación: No tiene sentido volver a calcular la suma de los rangos ya calculados.
Entonces, ¿podemos calcular todos los valores posibles y guardarlos en algún lugar o hacer algo parecido?

Es evidente que por la cantidad de consultas, se busca que cada consulta se ejecute en tiempo constante `O(1)`. Entonces,
debe existir alguna manera de memorizar o pre-calcular algunos datos.

### Precalculo de sumas
Objetivo es guardar en un vector de sumas, la suma acumulada desde `0` hasta `i`.

```
indices:  0  1  2   3   4   5   6   7   8   9
valor:    6  4 -5   7   8  -5   3   2   1   2
sumas:    6 10  5  12  20  15  18  20  21  23
```

Tomando en cuenta lo siguiente:

`f(x) = sumatoria de valores desde 0 hasta x, inclusive.`

`f(2) = 5`

`f(6) = 18`

La suma entre el rango `i` y `j`, esta dada por la siguiente relacion:

`f(i,j) = f(j) - f(i - 1)`

`f(3,4) = f(4) - f(2)`

`f(4) = 20` `f(2) = 5`

`f(3,4) = 20 - 5 = 15`

## Cantidad de elementos cuya suma es igual a k
Dado un arreglo de elementos enteros positivos y negativos, encuentra todos los pares de numeros cuya suma sea igual a `k`

Ejemplo:
```
k = 8
indices:  0  1  2   3   4 
valor:    3  2  5   1   6

Respuesta:
Hay 2 parejas.

Explicacion.
3 + 5 = 8
2 + 6 = 8
```

### Solución

Fuerza bruta
Para cada elemento `i` en el arreglo, recorrer todo el vector para buscar si existe un `j` tal cual que A<sub>i</sub> + B<sub>j</sub> = `k`.
Complejidad `O(n*n)`