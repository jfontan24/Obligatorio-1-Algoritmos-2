# Justificación de órdenes — Obligatorio 1

> **Instrucciones** (borrar esta sección antes de entregar): para cada ejercicio cuya
> letra plantea restricciones de órdenes (tiempo o espacio), justificar brevemente por
> qué la solución cumple, indicando qué estructuras de datos o algoritmos se utilizaron.
> Ejemplo: "La letra exige inserción en O(log n); usamos un min-heap sobre arreglo,
> donde flotar/hundir recorren a lo sumo la altura del árbol". Si un ejercicio no tiene
> restricciones de órdenes, indicarlo.

## Ejercicio 1

-La letra exige ALTA y BUSCAR de orden O(log K) en peor caso, siendo K la cantidad de piezas registradas en esa colección al momento de ejecutar la operación. / Justificación: de la operación ALTA, se encarga la función add en avl.cpp. Esta función recursiva, va evitando recorrer ramas según si el dato del nodo donde estoy es mayor o menor al que quiero agregar. Como en cada llamada me evito de recorrer una de las dos ramas, el orden de tiempo de ejecución promedio es O(log K), siendo K la cantidad de nodos, o sea la cantidad de colecciones. Como un AVL es un ABB que además se mantiene siempre balanceado, el orden en peor caso sigue siendo O(log K), porque nunca degenera, manteniendose para cada nodo una diferencia de altura de sus hijos<=1. Las funciones que llama add, como height y balance son de O(1). En el caso de la operación BUSCAR, se llama a la función search de avl.cpp, la cual utiliza el mismo mecanismo de recorrida que la anterior y por tanto también es de O(log K) peor caso. 
-El RANGO tiene O(log(K)+R), siendo R la cantidad de piezas que esa consulta reporta y K la cantidad de piezas registradas en esa colección. /Justificación: cuando el dato (código) es mayor que hasta, menor que desde o igual a alguno de ellos, se deja de recorrer una de las ramas hijas, por eso O(log K). Pero como hay un caso en que se recorren ambas ramas, porque me encuentro dentro del intervalo, es O(R). Si sumo ambos, obtengo el orden requerido por la consigna: O(log(K)+R)

## Ejercicio 2
- Sin restricciones de órdenes. / Justificación: ...

## Ejercicio 3
- Sin restricciones de órdenes. / Justificación: ...

## Ejercicio 4
- Sin restricciones de órdenes. / Justificación: ...

## Ejercicio 5
- Sin restricciones de órdenes. / Justificación: ...

