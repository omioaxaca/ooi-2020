# Exponenciación rápida

Objetivo: a<sup>n</sup>

## Método lineal O(n)
```c++
long long int potencia(int a, int n) {
    long long int resultado = 1;
    for (int i = 0; i < n; i++) {
        resultado *= a;
    }
    return resultado;
}
```

## Método recursivo
```c++
long long int potencia_recursiva(int a, int n) {
    // Casos bases
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return a;
    }
    // Paso recursivo
    return a * potencia(a, n - 1);
}
```


## Método recursivo usando optimización matemática O(log<sub>2</sub>n)

x<sup>n</sup> * x<sup>m</sup> = x<sup>(n + m)</sup>

x<sup>5</sup> = x<sup>2</sup> * x<sup>3</sup>

a<sup>n</sup> = a<sup>n/2</sup> * a<sup>n/2</sup> NOTA: Solo funciona si `n` es par.

Si `n` es impar podemos hacer la siguiente iteracion par, restando `1` al exponente:
a<sup>n</sup> = a<sup>n - 1</sup> * a<sup>1</sup> = a<sup>n - 1</sup> * a

Funcion recursiva:

Si `n` es par: a<sup>n</sup> = a<sup>n/2</sup> * a<sup>n/2</sup>

Si `n` es impar: a<sup>n</sup> = a<sup>n-1</sup> * a

```c++
long long int potencia_rapida(int a, int n) {
    // Casos bases
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return a;
    }
    // Pasos recursivos
    if (n % 2 == 0) {
        long long int memo = potencia(a, n/2);
        return memo * memo;
    }
    else {
        return potencia(a, n - 1) * a;
    }
}
```
