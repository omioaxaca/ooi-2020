# Curso final de la OOI 2020

## Sesión 19
Fecha: 28/04/2020

# Temas
- DFS en 2 dimensiones

# Ejercicios

## DFS para encontrar la salida de un laberinto

Indica si existe algun camino que lleve desde el punto de inicio al punto final en una
matriz de `N` filas y `M` columnas. Solo se pueden hacer movimientos en 4 direcciones:
arriba, abajo, izquierda y derecha. Solo se puede caminar a traves de celdas libres.
Entrada:
Primera linea `N` y `M`
Siguientes `N` * `M` lineas, la descripcion del mapa basado en los siguientes simbolos.

`I` - Inicio

`F` - Final

`.` - Celda libre

`X` - Pared

Salida: `SI` o `NO` indicando si existe un camino.

Ejemplo:

```
6 6
XXXXXX
X..I..
X.X..X
X.XXXX
X...FX
XXXXXX

SI
```

```
6 6
XXXXXX
X..I.X
X.X..X
XXXXXX
X...FX
XXXXXX

NO
```

```
10 10
XXXXXXXXXX
X.....I..X
X...XXXXXX
X.X......X
X.XXXXX..X
X.X...X..X
X.X.F.XX.X
X..X.....X
X..X.....X
XXXXXXXXXX

SI
```

```
10 10
XXXXXXXXXX
X.....I..X
X...XXXXXX
X.X......X
X.XXXXX..X
X.X...X..X
X.X.F.XXXX
X..X.....X
X..X.....X
XXXXXXXXXX

NO
```

## Flood-fill (Relleno por difusión)
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


