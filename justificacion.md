# Justificación de órdenes — Obligatorio 1

## Ejercicio 1

- La letra exige ALTA y BUSCAR de orden O(log K) en peor caso, siendo K la cantidad de piezas registradas en esa colección al momento de ejecutar la operación. / Justificación: de la operación ALTA, se encarga la función add en avl.cpp. Esta función recursiva, va evitando recorrer ramas según si el dato del nodo donde estoy es mayor o menor al que quiero agregar. Como en cada llamada me evito de recorrer una de las dos ramas, el orden de tiempo de ejecución promedio es O(log K), siendo K la cantidad de nodos, o sea la cantidad de colecciones. Como un AVL es un ABB que además se mantiene siempre balanceado, el orden en peor caso sigue siendo O(log K), porque nunca degenera, manteniendose para cada nodo una diferencia de altura de sus hijos<=1. Las funciones que llama add, como height y balance son de O(1). En el caso de la operación BUSCAR, se llama a la función search de avl.cpp, la cual utiliza el mismo mecanismo de recorrida que la anterior y por tanto también es de O(log K) peor caso. 
- El RANGO tiene O(log(K)+R), siendo R la cantidad de piezas que esa consulta reporta y K la cantidad de piezas registradas en esa colección. /Justificación: cuando el dato (código) es mayor que hasta, menor que desde o igual a alguno de ellos, se deja de recorrer una de las ramas hijas, por eso O(log K). Pero como hay un caso en que se recorren ambas ramas, porque me encuentro dentro del intervalo, es O(R). Si sumo ambos, obtengo el orden requerido por la consigna: O(log(K)+R)

## Ejercicio 2

- La letra exige O(L) promedio. Siendo L el largo de la palabra involucrada/ Justificación: el cálculo del hash se realiza en O(L) ya que se recorre la palabra. Luego, en hash_abierto.cpp, para ordenar la palabra se la reocorre denuevo (O(L)) y se recorre el arreglo generado O(26), lo cual es O(1). En getFrecuencia y setFrecuencia se recorre la lista en esa posición del arreglo (O(n)), siendo n la cantidad de elementos de la lista. Entonces queda O(L)+O(L)+O(n) => O(L). Asumo que O(max(L,n))=O(L).

## Ejercicio 3

- La letra exige O(Nlog(n)) temporal siendo N la cantidad archivos. / Justificación: El leer y agregar los elementos al heap (insertar) tiene O(Nlog(N)) ya que insertar en el heap (flotar) tiene O(logN) peor caso y lo hacemos n veces, osea O(N). En la funcion de consolidar eliminamos e insertamos elementos al heap lo cual tiene O(log(N)) peor caso por cada modulo, esto se debe a que se inserta la consolidacion (flotar) y se eliminan (hundir) los archivos independientes. Esto lo realizamos n-1 veces ya que solo debe quedar 1, esto es O(N). Por la regla de la producto queda O(Nlog(N)).
-  La letra exige O(n) espacial. / Justificación: El heap lo implementamos con un array de largo n+1, que es O(n).

## Ejercicio 4

- La letra exige O((V+A)logV), siendo V la cantidad de modulos y A la cantidad de dependencias / Justificación: En el heap se van insertando los vertices con grado de entrada cero, un vertice nunca se insertará dos veces. Insertar en un heap tiene O(logV) en peor caso y esto lo hacemos (V+A) veces ya que eventualmente procesamos todos los vertices y para cada unos nos fijamos en sus adyacentes (cuales dependen de él). Por ende tiene O((V+A)logV).
La letra exige O(V+A) espacial, siendo V la cantidad de modulos. / Justificación: como implementamos el grafo con una lista de adyacencia solo se guardan las aristas que efectivamente tiene cada vertice.

## Ejercicio 5

- La letra exige O(Elog(E)) temporal, siendo E la cantidad de senderos. / Justificación: el kruskal utiliza mfset con dos optimizaciones: union by rank y path compression. Sin utilizar ninguna optimización, puede degenerar en una lista, cuando todos se encuentran en el mismo conjunto. Al utilizar union by rank se garantiza que los árboles permanezcan relativamente planos, porque se le asigna al de menor altura estimada el representante del conjunto con mayor altura estimada. Entonces, queda el merge de O(log n). Para tener las aristas ordenadas utilizamos un heap, que despues se lo pasamos a kurskal. El peor caso de insertar en un heap es cuando tenemos que flotar que es O(log(E)), y al estar dentro de un for lo hacemos E veces. Por ende insertar las aristas tiene O(Elog(E)). EL orden del DFS para saber si el grafo es conexo es O(V+E) por que a la larga se van a evaluar todos los adyacentes para cada vertice, esto pasa porque en la pila solo se va a insertar si no esta visitado. Por la regla de la suma, el orden temporal del ejercicio es O(Elog(E)).
- La letra exige O(V+E) espacial, siendo V la cantidad de refugios. / Justificación: como implementamos el grafo con una lista de adyacencia solo se guardan las aristas que efectivamente tiene cada vertice.

