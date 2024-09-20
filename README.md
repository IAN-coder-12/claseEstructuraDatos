# Programa para la formula 1 que ordena los tiempos de los corredores para determinar el piloto y escuderia ganadora de la temporada
Este proyecto buscara filtrar los tiempos de los pilotos de formula 1:
>Paso 1: Se meteran al programa los tiempos de cada piloto en deterimanda carrera para ordenarlos de acuerdo al mejor tiempo y asignar los puntos correspondientes
> 
>Paso 2: Aunado a esto se determinara el piloto con la vuelta más rápida a quién se le asignaran puntos adicionales y se preguntara si algun piloto tuvo alguna penalización para restar puntos
> 
>Paso 2: Se preguntará si se quieren registrar puntos de alguna otra carrera/ciudad, si no, el programa devolvera los tres mejores pilotos de esa carrera. 
> 
>Paso 3: En caso de que si, continuara registrando los tiempos de las demas carreras, se necesitan registrar al menos tres carreras para que pueda haber campeones de escuderias
> 
>Paso 4: Al final se sumaran todos los puntos de los pilotos y el piloto con el mejor tiempo de al menos tres carreras será el ganador de la temporada (son 20 pilotos)
> 
>Paso 5: Para determinar la escudería ganadora, se sumaran los puntos de ambos pilotos por carrera y despues los de todas las carreras para ordenar los puntos y determinar la escuderia ganadora (son 10 escuderias)



##SICT0301: Evalúa los componentes

### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.

1. Ordenar los tiempos de los pilotos
Algoritmo utilizado:
Ordenamiento: Se podría utilizar un algoritmo de ordenamiento como QuickSort, MergeSort o incluso un método de ordenamiento más simple como BubbleSort.
Complejidad:
Mejor caso: O(nlogn) (para QuickSort o MergeSort)
Peor caso: O(n2) (para BubbleSort o QuickSort en su forma menos eficiente)

2. Determinar la vuelta más rápida y penalizaciones
Búsqueda del mínimo: Se puede recorrer la lista de tiempos para encontrar la vuelta más rápida y también se puede comprobar si hay penalizaciones.
Complejidad:
Buscar el mínimo: O(n)

3. Complejidad de ordenar los puntos de las escuderías: O(k log k), donde k = 10 (el número de escuderías).
El programa puede manejarse con algoritmos de ordenamiento mas rápidos vistos en clase como Quicksort o Mergesort, lo que permite mantener la complejidad en O( n log n) en el peor de los casos, siendo manejable dado que n = 20 (número de pilotos) o k = 10 (número de escuderías) son valores pequeños.


## SICT0302: Toma decisiones

### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.

Para este programa utilizaremos el mergeSort ya que tiene mayor estabilidad, y es eficiente para listas grandes, ya que su rendimiento no se ve afectado por la disposición inicial de los elementos. En este caso para el problema de ordenamiento de tiempos en la Fórmula 1 garantiza que los tiempos de los pilotos se ordenen de manera eficiente y correcta.
En el mejor de los casos, MergeSort sigue dividiendo la lista en mitades y luego las combina, independientemente de la disposición inicial de los elementos.
Complejidad: O(nlogn)

En el peor de los casos, que también se presenta cuando la lista está en el orden inverso, MergeSort sigue teniendo el mismo comportamiento. Siempre divide la lista y mezcla, sin importar cómo estén ordenados los elementos y la complejidad sigue siendo O(nlogn)
