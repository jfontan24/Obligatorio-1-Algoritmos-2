# Bitácora — Obligatorio 1

**Integrantes:** Julieta Fontan (303648), Victoria Pou (283117)

> **Instrucciones** (borrar esta sección antes de entregar): agregar una entrada por
> cada día trabajado, indicando la fecha y quién trabajó (un integrante o "En conjunto").
> Registrar el proceso real: ideas exploradas, decisiones y su justificación, partes de
> implementaciones, bugs encontrados y cómo se corrigieron, resultados de pruebas y dudas
> abiertas. Si se usó IA ese día, indicar herramienta, consulta y qué se hizo con la
> respuesta. Una bitácora escrita íntegramente el día de la entrega implica pérdida de puntos.

## 2026-09-03 — En conjunto (Julieta y Victoria)
- Configuramos el repositorio de github con los archivos a usar y leimos la letra del ejercicio uno. Elegimos ultilizar la estructura de AVL vista en clase de referencia para resolver el problema, y discutimos como cambiar las distintas funciones para que se adapten a lo que necesitamos.
- Empezamos a armar las funciones add para dar de alta, search para buscar y range para rango dentro del avl.cpp. Consideramos al principio hacerlas en una clase template separada pero al empezar a discutir la implementacion en main lo descartamos ya que era más entreverado de lo que debia ser.
- Con estas funciones prontas, empezamos a hacer el main del ejercicio uno siguiendo la letra.
- Una vez q terminamos todo tratamos de compilar y surgieron varios problemas entre ellos problemas de comandos para compilar y ejecutar pero luego de varias pruebas y errores los logramos hacer funcionar. Tambien nos encontramos con problemas al olvidarnos de std:: antes de strings pero fue de facil solución.
- Al compilar nos encontramos con un error de substr al tratar de cortar las entradas por sus espacios diciendo que estabamos fuera de rango. Despues de analizar las funciones nos dimos cuenta que cin, lo que usabamos para leer las lineas de las pruebas, cortaba automaticamente por espacios haciendo que la entrada que estabamos tomando fuera mas corta de lo esperado. Lo resolvimos buscando distintas alternativas y decidimos usar cin.ignore() luego de leer el numero del comienzo y getline(), que detecta el enter para cambiar las líneas. 
- Cuando finalmente solucionamos el error, encontramos otro: segmentation fault. Despues de poner muchos couts en cada parte del código, descubrimos que el problema surgió en la funcion range. Al revisarla nos dimos cuenta que nos faltaba el caso base, la funcion nunca terminaba y hacia stack overflow, explicando el segfault. Rápidamente, lo solucionamos agregando un return en caso null.
- Realizamos la prueba ejemplo1 y dio el resultado correcto.
- Al realizar más pruebas nos dimos cuenta que nos habiamos olvidado del tamaño que podian tomar los numeros en el código de la moneda, usamos int y al ser números mas grandes todo se rompe (error out_of_range). Intentamos cambiar los ints por long long pero el error persiste. Queda pendiente resolver. Sospechamos que debe ser por ints que quedaron en el camino en otras funciones.

## 2026-09-08 — En conjunto (Julieta y Victoria)
- Arreglamos error que teníamos en la prueba 10.in: nos habían quedado funciones con tipo int que le pasabamos un long, entonces cambiamos todo a long y se arregló.
- Luego, al correr la prueba 200000.in, nos dimos cuenta que en la función RANGO, imprimía el mismo número dos veces porque era al mismo tiempo el desde y el hasta. 
- Andan pruebas 10, 100, 1000, 10000, 100000, 200000, duplicados, ejemplo2, ejemplo3, ejemplo4, montonoCreciente, monotonoDecreciente, minimo, pocasLetras, monotonoPinturas, rangosAngostos, rangosVacios (todas).

## 2026-09-10 — En conjunto (Julieta y Victoria) — En conjunto
- Comenzamos con ejercicio2. Se nos ocurre que todos los anagramas vayan a parar al mismo bucket. Investigamos distintas funciones de hash y utilizamos una. Tomamos la implementación de tabla de la clase y la modificamos.
## 2026-09-16 — En conjunto (Julieta y Victoria) — En conjunto
- Solucionamos que en la salida de las pruebas aparecía todo en 0, esto era porque a la posición correspondiente del arreglo no le estabamos asignando la lista. 
- Pensamos que el problema por el cual no nos funcionan las pruebas es por la función de hash, entonces probamos con otra.
# 2026-09-18 — En conjunto (Julieta y Victoria) 
- Terminamos el ejercicio 2 y comenzamos el ejercicio 3
- Resolvimos mantener la misma función de hash que usabamos antes, pero cambiando como almacenabamos las palabras en el hash. Pasamos de que cada bucket guardara todas las palabras a que cada bucket guarde la palabra ordenada y su frecuencia. Ejemplo: en lugar de guardar amor->roma->mora guardamos (amor,3). Esto permitió que palabras que aunque tienen distinto hash se guardan en el mismo bucket por cuestiones de dispersión no cambiaran el resultado (por ejemplo, perro se guardaba con amor y nos daba 3 en lugar de 0)
- Pasamos de listas q guardaban un valor a listas q guardan un par valor-frecuencia
- Pasamos de ordenar las palabras al hacer el hash, a ordenarlas al hacer set o get para poder usar ese string en la comparación dentro de la lista (para saber si ese anagrama ya estaba o no). 
- Empezamos el ejercicio 3 planteando un min heap binario implementado con un array y comenzamos a definir las funciones de swap, flotar, hundir y pop

# 2026-09-21 — Julieta 
- Pasan pruebas de ejemplo 1 al 4, cajon gigante, cajon gigante repetidas, consultas ausentes, maximo, minimo, mismo largo, pocas letras, prefijo comun, suma igual, todas distintas

# 2026-09-21 — Victoria
- Pasan pruebas 10,100,1000,10000,100000

# 2026-09-22 — En conjunto (Julieta y Victoria) 
- Hicimos las funciones del minHeap consolidar, size y getCosto, además del main (ejercicio3.cpp)

# 2026-09-24 — En conjunto (Julieta y Victoria) 
- Ejemplo 1 pasa la prueba
- Nos daba distinto el 10.out de nuestra salida, nos dimos cuenta que era porque no hundía el resultado de la consolidación y le hacía swap directo a la raíz. Como el arbol no quedaba consistente, no daba bien la prueba.
- Andan pruebas 10,100,1000,10000,100000,1000000,crecientes,crecientesgrande,1000000. Cambiamos la función consolidar de recursiva a iterativa porque nos daba segmentation fault en la prueba 1000000, faltaría chequear más adelante denuevo las otras pruebas anteriores al 1000000, que anduvieron con la versión recursiva de consolidar.

# 2026-10-08 - En conjunto (Julieta y Victoria)
- Hicimos la parte de tomar los datos del input del ejercicio4.cpp
- Discutimos sobre diferentes implementaciones, queda pendiente determinar como utilizaremos el heap. Definimos la clase abstracta del grafo. Decidimos que el grafo va a ser implementado conlista de adyacencia por el orden espacial que se exige

# 2026-10-09 - En conjunto (Julieta y Victoria)
- Implementamos el grafo. Decidimos que vamos a usar orden topológico y que el heap se utilizará en el algoritmo del orden topológico. Tendremos un arreglo auxiliar que vincule el nro del grafo(pos del arreglo) con la proridad. Tendremos un tipo modulo, que va a guardar el nro de vertice y su prioridad correspondiente. El heap va a ser de tipo modulo. Como ya tenemos un heap binario genérico de otro ejercicio, vamos a utilizarlo. Nos damos cuenta que tiene función consolidar como propia de un heap binario y esto no es correcto, entonces dejamos planteado para la próxima sacar esta función para que deje de ser propia del heap. Vamos a pensar la función consolidar fuera de la implementación del TAD del heap binario y utilizando sus funciones, ya que esto es lo que corresponde.
- El grafo lo implementamos con lista de adyacencia y utilizamos la ListImp que se nos dio. La modificamos a esta y su clase abstracta para que tengan un iterador.
- Escribimos el código para tomar los datos del input.

# 2026-10-12 - En conjunto (Julieta y Victoria)
- corregimos que consolidar este en el main del ejercicio3.cpp, anda prueba 10.in
- escribimos el algoritmo de orden topológico, creamos el tipo módulo
- compila pero nos da segmentation fault, resolvemos la próxima

# 2026-10-16 - Victoria
- andan pruebas 100, 1000, 10000, 100000, 1000000, crecientes, decrecientes, dos_valores, ejemplo1, ejemplo2, ejemplo3 del ejercicio3

# 2026-10-16 -En conjunto (Julieta y Victoria)
- realizamos ejercicio 5. La idea es primero fijarnos si el grafo es conexo, o sea, si de caulquier refugio se pueden llegar a los demás. Esto lo realizamos con DFS y si nos da que no es conexo entonces es imposible y si no utilizamos kruskal. Kruskal utiliza un minHeap que tiene las aristas ordenadas por menor peso y MFset implementado con las dos optimizaciones. Si el origen y el destino de una arista estaban en distintos conjuntos, hacemos merge y vamos sumando el costo. No nos interesa en este caso el árbol de cubrimiento mínimo si no que el costo mínimo, es eso lo que retornamos.
- para DFS utilizamos una pila porque el recursivo nos trajo problemas

# 2026-10-18 - Julieta
- andan pruebas 10, 100, 1000, 10000, 100000, cadena, ciclo mínimo, ciclo parcial, ejemplo1, ejemplo2, ejemplo3, ejemplo4, ejemplo5, fifo_distinto, máximo, mínimo, minimo_lineal, prioridades iguales del ejercicio 4

# 2026-10-21 - Victoria
- andan pruebas 10, 100, 1000, 10000, 100000, arbol, ciclos_baratos, desconexo_grande, dos_componentes, dos_refugios, dsu_cadena, ejemplo1, ejemplo2, ejemplo3, ejemplo4, ejemplo5, maximo, paralelas, sin_senderos, todos_iguales, un_refugio de ejercicio5
- dsu_inverso dio imposible y tendría que haber dado un número !!!
- andan ejemplo4, ejemplo5, maximo, minimo, todos_iguales del ejercicio3.