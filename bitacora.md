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

## AAAA-MM-DD — En conjunto
- Ejemplo: Implementamos ... Bug: ... Lo corregimos ...
- Pasan los casos de prueba 1 a 4 del ejercicio 1.
