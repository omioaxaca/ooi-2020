Solucion matematica al problema de sumas contiguas:

Asume que la respuesta optima es el resultado de sumar los numeros en el rango desde *i* a *j*.

Suma mayor = SUMA<sub>ij</sub>

        i   k            j
    [1, 4, -7, 9, -1, 3, 5]


Asume que

 SUMA<sub>i j</sub> = SUMA<sub>i  k</sub> + SUMA<sub>(k+1) j</sub>

Entonces

SUMA<sub>i j</sub> - SUMA<sub>(k+1) j </sub>= SUMA<sub>i  k</sub>

Si supones que la SUMA<sub>i  k</sub> es negativa (< 0 ) entonces podemos afirmar lo siguiente:

SUMA<sub>i j</sub> < SUMA<sub>(k+1) j </sub>

Esto rompe nuestra primera suposicion, es decir la suma mas grande no es de de *i* hasta *j*, sino desde *k+1* hasta *j*

Ejemplo: 

        i   k            j
    [1, 4, -7, 9, -1, 3, 5]

SUMA<sub>i j</sub> = 13


SUMA<sub>i  k</sub> = -3

SUMA<sub>(k+1) j </sub> = 16

SUMA<sub>i j</sub> - SUMA<sub>(k+1) j </sub>= SUMA<sub>i  k</sub>

13 - 16 = -3