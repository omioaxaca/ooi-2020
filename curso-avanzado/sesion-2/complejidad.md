# Complejidad de un algoritmo

Notación O: La complejidad del algoritmo en el peor de los casos.

Necesitamos entender lo siguiente:
- ¿Cuántas operaciones realiza nuestro algoritmo?
- ¿En cuanto tiempo se traducen esas operaciones?

IMPORTANTE: Una computadora "promedio" puede realizar 10<sup>6</sup> (1,000,000) operaciones en 1 segundo. 

* Complejidad constante O(1)

```int x = 5;```

```x = 5 + 8;```

```x = 5 * 1000;```
* Complejidad lineal O(n)
```
for(int i = 0; i < n; i++) {
     x = 5 + 8;
}
```
* Complejidad cuadratica O(n<sup>2</sup>)

```
for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
        x = 5 + 8;
    }
}
```

* Complejidad exponencial O(x<sup>n</sup>)

* Complejidad factorial O(n!)

