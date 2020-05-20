# Curso final de la OOI 2020

## Sesión 20
Fecha: 19 de mayo de 2020

# Temas
- Continuación DFS en 2 dimensiones
- Imprimir cantidad de pasos para llegar a solución.

# Ejercicios

## Flood-fill (Relleno por difusión)
8 conexo (significa que las celdas de las esquinas tambien son adyacentes.)

```
XXXXXX
X..*.X
X.X..X
XXXXXX
X....X
XXXXXX


XXXXXX
X****X
X*X**X
XXXXXX
X....X
XXXXXX
```

```
XXXXXX
X....X
X.X..X
XXXXXX
X..*.X
XXXXXX


XXXXXX
X....X
X.X..X
XXXXXX
X****X
XXXXXX
```

```
XXXXXXXXXX
X.....*..X
X..XXXXXXX
X.X......X
XXXXXXXXXX
X.X...X..X
X.X...XX.X
X..X.....X
X..X.....X
XXXXXXXXXX

XXXXXXXXXX
X********X
X**XXXXXXX
X*X******X
XXXXXXXXXX
X.X...X..X
X.X...XX.X
X..X.....X
X..X.....X
XXXXXXXXXX
```
## Flood fill usando un contador
Ejercicio: Pintar las celdas adyacentes con un numero que indique la cantidad de pasos
necesarios para llegar a esa celda.

```
XXXXXX
X..*.X
X.X..X
XXXXXX
X....X
XXXXXX

XXXXXX
X21*1X
X3X11X
XXXXXX
X....X
XXXXXX
```

```
XXXXXXXXXX
X.....*..X
X..XXXXXXX
X.X......X
XXXXXXXXXX
X.X...X..X
X.X...XX.X
X..X.....X
X..X.....X
XXXXXXXXXX

XXXXXXXXXX
X54321*12X
X54XXXXXXX
X5X56789XX
XXXXXXXXXX
X.X...X..X
X.X...XX.X
X..X.....X
X..X.....X
XXXXXXXXXX

```
