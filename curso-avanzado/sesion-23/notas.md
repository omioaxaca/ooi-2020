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

Barrido
Dada la relación `a` + `b` = `k`, si se conoce el valor de `k` entonces se tienen dos incognitas.
Pero, si recorremos el arreglo empezando desde `0` hasta el final y en cada paso asignamos su valor a `a`, entonces solo nos quedaría una incógnita: `a + b = k` es lo mismo que `b = k - a`.
Ahora el problema se reduce en contar todas ocurrencias de `b` en el arreglo, esto se puede resolver facilmente, si mantenemos una cubeta con la cantidad de veces que ha aparecido cada valor.

```c++
int n; // cantidad de elementos
int k; // suma
cin >> n;
cin >> k;

map<int, int> cubeta; // Guardar la frecuencia con que aparece cada numero. valor -> frecuencia


int parejas = 0;
for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    int b = k - a; // a + b = k, al despejar b se obtiene b = k - a
    parejas += cubeta[b];
    cubeta[a]++;
}
cout << parejas << "\n";
```

## Cantidad de subsecuencias contiguas cuya suma es igual a k
Ejercicio: Encuentra la cantidad de subsecuencias (rangos) contiguos cuya suma es igual a `k`.
Ejemplo:
```
1 2 2 3 5
5
```
La cantidad de rangos contiguos cuya suma es igual a 5 es 3.
```
1 + 2 + 2
2 + 3
5
```

Tomando en cuenta las 2 secciones anteriores, esto se puede resolver como una combinacion de ambas.

Dada la funcion:
`sumatoria(i, j) = sumatoria(j) - sumatoria(i - 1)`
Es claro que si a la sumatoria desde `0` hasta `j`, se le resta la sumatoria desde `0` hasta `i-1`, se obtiene
la sumatoria entre `i` y `j`.

```
0     i     j
2  6  1  5  3

sumatoria(j)   = 2 + 6 + 1 + 5 + 3 = 17
sumatoria(i-1) = 2 + 6             =  8
sumatoria(i,j) =         1 + 5 + 3 =  9
Lo cual es lo mismo que 17 - 8 = 9
```

Dado que se conoce el valor buscado, es decir `sumatoria(i, j) = k`
Entonces podemos despejar la ecuacion de tal modo que tenemos:

```
k = sumatoria(j) - sumatoria(i - 1)
sumatoria(i - 1) = sumatoria(j) - k
```

Si calculamos todas los valores para `sumatoria(j)` desde `0` hasta `n`.
Entonces solo tendriamos una incógnita. Utilizando la misma lógica del ejercicio anterior,
podemos guardar todos los valores encontrados en una cubeta y así facilmente consultarlos en cada
iteración del algoritmo.

```c++
    vector<int> numeros(n); // Aqui se guardan los numeros
    vector<int> sumatoria(n); // Representa la sumatoria desde el 0

    sumatoria[0] = numeros[0];
    for (int i = 1; i < n; i++) {
        sumatoria[i] = sumatoria[i - 1] + numeros[i];
    }

    int rangos = 0;
    for (int i = 0; i < n; i++) {
        // Dada la relacion k = sum_a - sum_b
        // Al despejar, se tiene sum_b = sum_a - k
        int sum_a = sumatoria[i];
        int sum_b = sum_a - k;
        // Verificar cuantas veces ha aparecido sum_b
        rangos += cubeta[sum_b];
        // si el rango por si solo es igual a k, contarlo por si mismo.
        if (sum_a == k) {
            rangos++;
        }
        cubeta[sum_a]++;
    }
    cout << rangos << "\n";
```
