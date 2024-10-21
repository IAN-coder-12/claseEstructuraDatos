# Programa para la formula 1 que ordena los tiempos de los corredores de cada carrera de la temporada 2023, de modo que el piloto con menor tiempo es el el que obtiene el primer puesto y así sucesivamente
Este proyecto buscara filtrar los tiempos de los pilotos de formula 1:
> Paso 1: El programa preguntara al usuario que carrera desea ver
>
> Paso 2: El programa seleccionara el archivo segun la carrera elegida
>
> Paso 3: El programa lee el archivo .csv correspondiente que tiene una lista de 20 pilotos cada uno con su nombre, escuderia, tiempo y puntos asginados. El orden que se encuentra en los archivos es el orden con el cual empezó la carrera (segun la Qualy del dia anterior), o sea una lista en des-orden.
>
> Paso 4: Una vez leido los archivos, se asignaran los datos del archivo a los atributos correspondientes del objeto, creando 20 objetos (20 pilotos).
>
> Paso 5: El programa mostrará la parrilla de salida al usuario
>
> Paso 6: Se almacenaran todos pilotos en un vector para la posterior manipulación de datos.
>
> Paso 7:El programa hará uso del quickSort() para ordenar la lista de objetos segun su atributo tiempo.
>
> Paso 8: El programa mostrara al usuario el marcador final con las mejores posiciones en primer lugar.
>
> Paso 9: El progrma preguntara al usuario si desea agregar un piloto a la carrera
>
>> 9.1: Si el usuario quiere agregar un nuevo piloto
>
>>> 9.1.1: El programa pide los datos necesarios para crear un nuevo objeto piloto
>
>>> 9.1.2: Una vez se haya creado el nuevo objeto el programa hace uso de un arbol binario para insertarlo dentro del mismo con su funcion add()
>
>>> 9.1.3: El programa imprime la nueva lista de pilotos con ayuda del un arbol binario en inorder para mostrar loos datos ordenados
>
>> 9.2: Si el usuario no quiere agregar un nuevo piloto
>
>>> 9.2.1: El programa pregunta si se desa ver otra carrera, si sí, el programa se ejecuta desde el paso 1, si no, el programa termina.
>




## SICT0301: Evalúa los componentes

### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.

1. Ordenar los tiempos de los pilotos.
Algoritmo utilizado:
Ordenamiento: Se podría utilizar un algoritmo de ordenamiento como QuickSort, MergeSort o incluso un método de ordenamiento más simple como BubbleSort. En este caso se decidió utlizar un quicksort() debido a que es el metodo de ordenamiento más eficiente para lo que necesitamos realizar (ordenar una lista de objetos segun su atributo tiempo).

Dado que el tiempo es un atributo numérico, Quicksort puede manejar listas de pilotos de tamaños significativos de manera eficiente, permitiendo un ordenamiento rápido incluso con cientos o miles de entradas.

Complejidad:
> Mejor caso: O(nlogn)
>
> Caso Promedio: O(nlogn)
>
> Peor caso: O(n2)

## SICT0302: Toma decisiones

### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.

Tomando en cuenta lo anterior, Quicksort tiene una complejidad de espacio adicional de O(logn) debido a la recursión. Esto es más eficiente que otros algoritmos como Merge Sort, que requiere O(n) espacio adicional, lo que es ventajoso al ordenar estructuras más grandes como en este caso para la lista de pilotos. Es por eso que se decidió usar este algoritmo

## SICT0303: Implementa acciones científicas

### Implementa mecanismos para consultar información de las estructras correctos.
El programa permitira al usuario agregar un nuevo piloto a la carrera, de modo que al agregarse, el programa devuelva la nueva lista ordenada, tomando en cuenta el tiempo del nuevo piloto. Esto lo haremos haciendo uso de un  binary tree con su metodo inorder().

### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
El programa leerá los archivos(carreras) que contienen los  nombres, escuderias, tiempos y puntos de cada uno de los pilotos, asignando cada uno de estos datos al atributo correspondiente del objeto Piloto, para posteriormente almacenar los objetos(Pilotos) en un vector y despues manipular la información