
# Proyecto: Programa para la F1 que ordena los tiempos de los pilotos de la temporada 2023.
Este proyecto buscara filtrar los tiempos de los pilotos de formula 1:
> Paso 1: El programa preguntará al usuario que carrera desea ver
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
>>> 9.1.3: El programa imprime la nueva lista de pilotos con ayuda del un arbol binario en inorder para mostrar los datos ordenados
>
>>>9.1.4: Una vez ordenados los pilotos, con el nuevo piloto que entro a la carrera, se asignan los puntos correspondientes segun los nuevo tiempos con la función asignarPuntosInOrder() donde hacemos un recorrido inorder al mismo tiempo que vamos modificando el atributo puntos de cada uno de los nodos del arbol.
>
>> 9.2: Si el usuario no quiere agregar un nuevo piloto
>
>>> 9.2.1: El programa pregunta si se desa ver otra carrera, si sí, el programa se ejecuta desde el paso 1, si no, el programa termina.
>


## Descripción del avance 1
Pega aquí la descripción de tu primer avance.

## Descripción del avance 2
Pega aquí la descripción de tu segundo avance.

### Cambios sobre el primer avance
1. Escribe la lista de cambios realizados sobre el planteamiento original: Argumenta la razón por la que decidiste el cambio. Estos argumentos puedes retomarlos más adelante en tu argumentación de competencias.
2. Cambio 2: Razón del cambio
3. Cambio 3: Razón del cambio
4. etc...: etc...

## Descripción del avance 3
Escribe aquí la descripción de lo que contiene este avance. 

### Cambios sobre el segundo avance
1. Escribe la lista de cambios realizados sobre el planteamiento pasado: Argumenta la razón por la que decidiste el cambio. Estos argumentos puedes retomarlos más adelante en tu argumentación de competencias.
2. Cambio 2: Razón del cambio
3. Cambio 3: Razón del cambio
4. etc...: etc...


## Descripción de las entradas del avance de proyecto
Escribe aquí la descripción de las entradas del proyecto, por ejemplo, si de entrada se requieren varios archivos, hay que indicar el formato de cada uno de ellos, y proporcionar un ejemplo de los datos de cada archivo.

## Descripción de las salidas del avance de proyecto
Escribe aquí la descripción de los resultados de la ejecución de tu programa.

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.

1.Ordenar los tiempos de los pilotos (quicksort). 
>
Algoritmo utilizado:
>
Ordenamiento: Se podría utilizar un algoritmo de ordenamiento como QuickSort, MergeSort o incluso un método de ordenamiento más simple como BubbleSort. En este caso se decidió utlizar un quicksort() debido a que es el metodo de ordenamiento más eficiente para lo que necesitamos realizar (ordenar una lista de objetos segun su atributo tiempo).
>
Dado que el tiempo es un atributo numérico, Quicksort puede manejar listas de pilotos de tamaños significativos de manera eficiente, permitiendo un ordenamiento rápido incluso con cientos o miles de entradas.
>
Complejidad:
> Mejor caso: O(nlogn)
>
> Caso Promedio: O(nlogn)
>
> Peor caso: O(n2)

2.Insertar un nuevo piloto y ordenar la lista nuevamente (arbol binario) 

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.
Si lograste este criterio anteriormente, copia aquí tu argumentación. Si no, ésta es una nueva oportunidad para lograrlo. Escribe aquí tu aprendizaje y tus argumentos sobre por qué consideras que ahora ya has desarrrollado este criterio y dónde se puede observar el desarrollo que mencionas.

#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.
1. QuickSort
Tomando en cuenta lo anterior, Quicksort tiene una complejidad de espacio adicional de O(logn) debido a la recursión. Esto es más eficiente que otros algoritmos como Merge Sort, que requiere O(n) espacio adicional, lo que es ventajoso al ordenar estructuras más grandes como en este caso para la lista de pilotos. Es por eso que se decidió usar este algoritmo

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Si lograste este criterio anteriormente, copia aquí tu argumentación. Si no, ésta es una nueva oportunidad para lograrlo. Escribe aquí tu aprendizaje y tus argumentos sobre por qué consideras que ahora ya has desarrrollado este criterio y dónde se puede observar el desarrollo que mencionas.

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
Si lograste este criterio anteriormente, copia aquí tu argumentación. Si no, ésta es una nueva oportunidad para lograrlo. Escribe aquí tu aprendizaje y tus argumentos sobre por qué consideras que ahora ya has desarrrollado este criterio y dónde se puede observar el desarrollo que mencionas.

### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.
El programa permitira al usuario agregar un nuevo piloto a la carrera, de modo que al agregarse, el programa devuelva la nueva lista ordenada, tomando en cuenta el tiempo del nuevo piloto. Esto lo haremos haciendo uso de un  binary tree con su metodo inorder().

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
El programa leerá los archivos(carreras) que contienen los  nombres, escuderias, tiempos y puntos de cada uno de los pilotos, asignando cada uno de estos datos al atributo correspondiente del objeto Piloto, para posteriormente almacenar los objetos(Pilotos) en un vector y despues manipular la información

### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta
Al final el prorgrama crea un archivo por cada carrera que el usuario haya seleccionado con las posiciones finales de los pilotos segun sus tiempos y asignando los puntos correspondientes a cada piloto.