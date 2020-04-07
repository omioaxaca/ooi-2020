# Área más grande de un rectángulo en un histograma

## Descripción
Uso de pilas para calcular el area mas grande de un rectángulo
dentro de un histograma.

## Problema
Calcular el área más grande de un rectángulo comprendido entre
las regiones contiguas de un histograma (gráfica de barras).
Asume que el ancho de cada barra es 1.

### Ejemplo:

**Entrada**

```
índices: 0   1   2   3   4   5   6
valores: 6   2   5   4   5   1   6
```

**Salida**

12
El área mas grande esta entre los indices 2 a 3 y se forma al multiplicar 4 * 3.

## Solucion

### Fuerza bruta O(n<sup>2</sup>)

La solución más simple sería calcular todas las áreas posibles y elegir la mayor. Para hacerlo, podriamos intentar calcular cual es el área más grade posible que se puede formar utilizando como altura la barra *b<sub>i</sub>*.
Nota que el área del rectangulo se calcula como *h \* l*. 
De tal forma que para *h = b<sub>i</sub>* tenemos que buscar el valor de *l*.

El valor de *l* será determinado por el rango de barras contiguas a *b<sub>i</sub>* que sean mayores o iguales a su valor, ya que si fueran menores no se podría formar el rectángulo.

Sabiendo esto, para encontrar el valor de *l* nuestro trabajo se reduce a buscar este rango contiguo. Para hacerlo tenemos que buscar dónde inicia y dónde termina el rango:

Para cada barra *b<sub>i</sub>*, buscar la primera barra a la izquierda que sea menor, llamemos a esta barra *b<sub>izq</sub>*. También, debemos buscar hacia la derecha la primer barra que sea menor, esta barra será *b<sub>der</sub>*.
Esto significa que los valores comprendidos desde *izq* hasta *der* (ambos exclusive), son mayores o iguales a *b<sub>i</sub>*, por lo que es posible formar un rectángulo de altura *b<sub>i</sub>*.

Dicho de otra forma, *l = der - izq - 1*. Nota que *l* representa el tamaño del rango. Es necesario restar 1 ya que solo nos interesa el tamaño del rango entre estos índices.

```c++
int h = bi;
int l = (der -  izq - 1);
int area = h * l;
```

La complejidad del algoritmo es O(n<sup>2</sup>) ya que para cada barra tenemos que buscar los indices *izq* y *der*, lo cual significa realizar *n* operaciones en el peor de los casos.

TODO: Agregar código de ejemplo.

### Uso de pilas O(n)
Fuente: https://www.geeksforgeeks.org/largest-rectangle-under-histogram/

El problema con la solución anterior es que es demasiado costoso buscar el tamaño del rango. Para optimizar esto, se puede abordar el problema desde una perspectiva diferente.

- Suponiendo que estamos ubicados en la posición *j* y que esta posición representa el final de un rango, es decir *der*. Necesitamos una forma de encontrar *b<sub>i</sub>* y *izq*.

    Si utilizamos una pila que contenga en el top el valor de *b<sub>i</sub>*, y que el primer elemento dentro de la pila menor que *b<sub>i</sub>* represente *b<sub>izq</sub>* entonces podriamos resolver facilmente el problema.

Ahora el problema se reduce a cómo insertar y remover los elementos de la pila para que se cumplan ciertas condiciones. Para esto debemos seguir estos pasos:

1. Crear una pila vacia. La cual servira para guardar los datos, nota que esta pila guardará los índices de cada barra en vez de su valor.
2. Recorrer todas las barras empezando por la primera y para cada barra *b<sub>i</sub>* hacer lo siguiente:
    
    a) Si la pila está vacia o si *b<sub>i</sub>* es mayor o igual que el top de la pila, entonces insertar *i*.

    b) Si *b<sub>i</sub>* es menor que el top de la pila, eso significa que *b<sub>i</sub>* representa el final de un rango, es decir *b<sub>der</sub>*. Por lo tanto, debemos calcular todas las áreas posibles que tengan un rango que termine en *der*. Para esto hacemos:
    
    Mientras la pila no este vacia y el top sea mayor que *b<sub>der</sub>*
      
      --> Asignar el valor del top de la pila a *b<sub>top</sub>*.
      
      --> Eliminar el top de la pila.

      --> El nuevo elemento en el top de la pila, representa *izq*. En caso de  que la pila este vacia en este punto, eso significa que no existe ningun elemento menor que *b<sub>top</sub>*, lo cual quiere decir que todos los elementos anteriores son mayores o iguales, por lo que es posible formar un rectangulo iniciando desde la primera barra. Asi que *izq = 0*.
      
      --> Entonces, se tiene que:
      ```c++
      der = i;
      top = pila.top();
      pila.pop();
      if (!pila.empty()) {
        // Restamos 1 para que al hacer la resta de der - izq
        // el valor resultante sea el tamaño del rango
        // comprendido entre izq y derecha, ambos exclusive.
        izq = pila.top() - 1;
      }
      else {
        izq = 0;
      }
      h = b[top];
      l = der - izq;
      area = h * l;
      ```
      --> En cada paso mantener en alguna variable el area mayor encontrada hasta el momento.

      --> Insertar *i* en la pila.
    

3. Después de recorrer todas las barras, si la pila no está vacía entonces repetir el inciso `b)` del paso `2` hasta que la pila se vacie.


### Código de ejemplo:

```c++
    int area_maxima = 0;
    vector<int> barras;
    // Paso 1.
    stack<int> pila;
    // Paso 2.
    for(int i = 0; i < barras.size(); i++) {
        // Paso 2 inciso a.
        if(pila.empty() || barras[pila.top()] <= barras[i]) {
            pila.push(i);
        }
        else {
            // Paso 2 inciso b.
            int der = i;
            while(!pila.empty() && barras[P.top()] > barras[i]) {
                int top = pila.top();
                pila.pop();

                int izq = 0;
                if(!pila.empty()) {
                    izq = pila.top() - 1;
                }
                int h = barras[top];
                int l = der - izq;
                int area = h * l;	
                area_maxima = max(area, area_maxima);
            }
            pila.push(i);
        }
    }
    // Paso 3.
    int der = barras.size();
    while (!pila.empty()) {
        int top = pila.top();
        pila.pop();

        int izq = 0;
        if(!pila.empty()) {
            izq = pila.top() - 1;
        }
        int h = barras[top];
        int l = der - izq;
        int area = h * l;	
        area_maxima = max(area, area_maxima);
    }


```
      
    








