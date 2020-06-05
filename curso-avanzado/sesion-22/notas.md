# Curso final de la OOI 2020

## Sesión 22
Fecha: 4 de junio de 2020

# Temas
- Continuación BFS

# Ejercicios

## Quién llega primero

### Descripción
Arturo y Damian están en distintos lugares de un laberinto. ¿Quién de los 2 llegará primero a la salida?

### Entrada
El laberinto donde `A` es la posición de Arturo, `D` la de Damian y `S` la salida.
Ambos se pueden mover solo en 4 direcciones y solo pueden avanzar una casilla a la vez.
Solo pueden moverse por casillas libres, indicadas por `.`, pero no pueden pasar por paredes `X`.

### Salida
Imprime el nombre de quién llega primero y la cantidad de pasos que tiene que dar.

### Ejemplo
```
XXXXXXXXXX
X.....A..X
X...XXXXXX
X.X......X
X.XXXXX..X
X.X...X..X
X.X.F.XX.X
X..X.....X
X.D.X....X
XXXXXXXXXX

Arturo 19
```

```
XXXXXXXXXX
X.....A..X
X...XXXXXX
X.X......X
X.XXXXX..X
X.X...X..X
X.X.F.XX.X
X..X.....X
X...X..D.X
XXXXXXXXXX

Damian 5
```

## Quien llega primero parte 2
Basado en el problema anterior, imagina que ahora Damian puede moverse a las 8 casillas adyacentes.

```
XXXXXXXXXX
X.....A..X
X...XXXXXX
X.X......X
X.XXXXX..X
X.X...X..X
X.X.F.XX.X
X..X.....X
X.D.X....X
XXXXXXXXXX

Damian 3
```