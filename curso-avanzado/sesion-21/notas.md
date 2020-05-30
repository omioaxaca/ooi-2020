# Curso final de la OOI 2020

## Sesión 21
Fecha: 26 de mayo de 2020.

# Temas
BFS (Breadth First Search) (Búsqueda en amplitud)
- Explora los nodos en orden nivel por nivel.
- Utiliza una cola para saber el orden de los nodos a visitar.

## Algoritmo de la BFS
```c
Crear una cola vacia
Insertar el primer nodo a la cola
while la cola no este vacia
    Sacar el primer nodo de la cola
    Marcar este nodo como visitado
    if este nodo es la respuesta
        respuesta_encontrada = true
        break // terminar con la busqueda
    else
        for cada hijo del nodo
            if nodo no visitado
                agregar a la cola
if cola vacia and !respuesta_encontrada
    // no se encontro respuesta
```

```c++
Nodo bfs(Nodo inicio) {
    queue<Nodo> Q;
    Q.push(inicio);

    while(!Q.empty()) {
        Nodo actual = Q.front();
        Q.pop();
        if (es_respuesta(actual)) {
            return actual; // Regresar el estado donde se encontro la respuesta.
        }
        visitado[actual.x][actual.y] = true;

        // Probar con todos los hijos.
        for (int i = 0; i < numHijos; i++) {
            Nodo sig;
            sig = // asignar los valores correspondientes al nodo siguiente.
            if(es_valido(sig)) {
                Q.push(sig);
            }
        }
    }
    return -1;
}
```


# Ejercicios

## Búsqueda en amplitud (BFS)

Encuentra la cantidad mínima de pasos que se tienen que dar para ir del punto de inicio al final.

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