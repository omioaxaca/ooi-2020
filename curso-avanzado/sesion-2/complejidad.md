# Complejidad de un algoritmo

La complejidad de un algoritmo mide cuantas operaciones realiza nuestro algoritmo para procesar los datos y obtener una respuesta. Es útil para saber qué tan rápidos son nuestros algoritmos y poder predecir su comportamiento con base en los parámetros de entrada.

Notación `O`: La complejidad del algoritmo en el peor de los casos.

Necesitamos entender lo siguiente:
- ¿Cuántas operaciones realiza nuestro algoritmo?
- ¿En cuanto tiempo se traducen esas operaciones?

**IMPORTANTE**: Para fines de competencia de la olimpiada, asume que una computadora puede ejecutar 10<sup>8</sup> (100,000,000) operaciones en 1 segundo.

Nota: En la mayoria de los ejemplos se usa la variable `n` para representar el valor máximo sobre el cual se ejecutará el algoritmo, a esto se le conoce como *espacio de búsqueda*.

## Complejidad constante O(1)

La complejidad constante en notacion `O` se refiere a la ejecución de una instrucción. Por ejemplo, sumas, restas, multiplicaciones, etc.

```c++
int x = 5;

x = 5 + 8;

x = 5 * 1000;
```

## Complejidad lineal O(n)

Son programas que contienen ciclos que se ejecutan `n` veces.

```c++
for(int i = 0; i < n; i++) {
     x = 5 + 8;
}
```

## Complejidad cuadratica O(n<sup>2</sup>)

Son programas que contienen 2 ciclos anidadados. Dado que las operaciones dentro del ciclo interno se ejecutan `n` * `n` veces, la complejidad se denomina cuadrática.
Nota: Si el ciclo externo se ejecutara hasta `n` y el interno hasta `m`, entonces la complejidad sería `O(nm)`.

```c++
for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
        x = 5 + 8;
    }
}
```

## Complejidad exponencial O(x<sup>n</sup>)

Son programas con funciones que crecen exponencialmente, es decir en cada iteración la cantidad de operaciones se multiplica. Los algoritmos recursivos son un buen ejemplo de esta complejidad.

Ejemplo de complejidad 2<sup>n</sup> :
```c++
void f(int n, int val) {
    if (n == 0) return;
    // La funcion se llama a si misma 2 veces,
    // por lo que en cada iteración crece al doble.
    // Por lo tanto la complejidad es 2 a la n.
    // Si la funcion se llamara a si misma 3 veces,
    // entonces la complejidad seria 3 a la n.
    f(n - 1, x);
    f(n - 1, y)
}
```

## Complejidad factorial O(n!)

Esta es una de las peores complejidades que existen, ya que la cantidad de operaciones crece demasiado rápido. Es útil para algoritmos de fuerza bruta cuando `n` es pequeña.

Por ejemplo, si `n` vale `5` el total de operaciones es `120`, pero si `n` vale `10`, entonces la cantidad de operaciones es `3,628,800‬`. Ahora, si `n` valiera `20` entonces la cantidad de operaciones sería `2,432,902,008,176,640,000‬`, lo cual significa que tu algoritmo probablemente tardaría `771.4681` años en terminar su ejecución.

Un ejemplo de algoritmo con esta complejidad es aquel que busca todas las permutaciones de un conjunto de numeros.

```c++
void f(int n) {
    // Esta funcion se llama a si misma n veces.
    // En la siguiente iteracion se llamara a si misma
    // n - 1 veces, y luego n - 2, etc.
    // Esta es la definicion de factorial n! = n * (n - 1)!
    for (int i = 0; i < n; i++) {
        f(n - 1);
    }
}
```

## Complejidad logaritmica O(log<sub>2</sub>n)

Son algoritmos que reducen la cantidad de operaciones a la mitad en cada iteración. Los clásicos y conocidos como divide y vencerás.

Esta es una de las mejores complejidades que existen.

Ejemplos:
- Exponenciación rápida
- Búsqueda binaria

```c++
long long int potencia_rapida(long long int a, int n) {
    if (n == 0) return 1;
    if (n == 1) return a;
    if (n % 2 == 0) {
        // Al hacer esto, la cantidad de operaciones se
        // divide a la mitad.
        long long int memo = potencia_rapida(a, n/2);
        return memo * memo;
    }
    else {
        return potencia_rapida(a, n - 1) * a;
    }
}
```

## Complejidad total del algoritmo

Cuando un programa contiene varios algoritmos con diferentes complejidades, la complejidad total del algoritmo en notación `O` será la de la función con la mayor complejidad. Por ejemplo si se tiene el siguiente código:
```c++
int main() {
    int x = 5; // Constante

    // Lineal
    for (int i = 0; i < n; i++) {
        x += 2;
    }

    // Cuadratica
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            x += 5;
        }
    }

    return 0;
}
```
La complejidad de este programa es O(n<sup>2</sup>) ya que es la complejidad mayor.