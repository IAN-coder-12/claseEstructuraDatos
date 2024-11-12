
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
Este proyecto busca extraer datos oficiales de las carreras de F1 de la temporada de 2023, que se encuntran en un hoja de excel, para posteriormente agregarlos a una estructura de datos que nos permita utilizar un algoritmo de ordenamiento para determinar que piloto
tuvieron las mejores posiciones de acuerdo a sus tiempos, se planea utilizar un quicksort para esta parte. Una vez obtenido los datos de los tres primeros lugares, estos se agregaran a un nuevo conjuntos de campeonato de pilotos para determinar quien fue el ganador de toda la temporada.

## Descripción del avance 2
Para esta segunda entrega lo que buscamos es poder agregar un nuevo piloto a las carreras, tanto como el usuario desee, y ahora con el tiempo que haga este nuevo piloto en la carrera se re-ordenaran las posiciones, esta vez se utilizó un arbol binario de modo que se pudiera agregar un nuevo nodo a la estructura para despues hacer un recorrido inorder y ordenar a los pilotos.

### Cambios sobre el primer avance
1. Insertar nuevos pilotos: Aqui decidí que enfocaria el programa a que el usuario pudiera meter su propio piloto para que pudiera
"competir" con los demás pilotos y darle un poco de dinamismo e interacción al programa, en lugar de que solo leyera datos.
>
2. Uitlización de arbol binario: En esta segunda entrega hice uso de un arbol binario para poder agregar un nuevo piloto en forma de nodo con todos sus atributos, para despues poder recorrer el arbol con el metodo inorder y desplegar la nueva tabla de resultados.
>
3. Lectura de archivos: En esta parte decidí que lo mejor sería generar un archivo que contuviera todas carreras disponibles para que sin importar el numero de elementos en una lista fija, el progrma funcionara adecuadamente, de modo que lee todas las ciudades en el archivo para despues insertarlos en una lista y poder manipularlos


## Descripción del avance 3
En este tercer avance implementé la asignación de puntos a los pilotos en el escenario en el que el usuario desea ingresar un nuevo piloto, ya que al reordenarse toda la tabla los puntos asignados tambien deberian cambiar dependiendo de las nuevas posiciones de los pilotos, ademas se implentó la funcion de escritura de archivos para generar un nuevo archivo de ganadores por cada carrera con los tres primeros lugares, finalemente se mejoró un poco la experiencia del usuario, mostrando leyendas en la consola cada que se exogia una carrera para simular qué es lo que pasaba en ese momento.

### Cambios sobre el segundo avance
1. Cambio de como se muestran los ganadores: Aqui decidi que sería mejor implementar una escritura de archivos por cada carrera para mostrar al usuario los tres primeros lugares.
>
2. Experiencia de usuario: Este cambio fue simplemente para que el programa fuera un poco más dinamico y darle al usuario una mejor experiencia al ejecutarlo
>
3. Asignación de puntos: En este caso solo se implemento una nueva funcin que hacía un recorrido inorder que al mismo tiempo accedia al tributo puntos del objeto piloto y le asginaba los nuevo puntos correspondientes.



## Descripción de las entradas del avance de proyecto
Para este proyecto se necesita
1. Un archivo de ciudades (carreras) en formato .txt para mostrar al usuario las carreras disponibles
>
2. Los archivos de cada carrera en formato .csv con los datos correspondientes de cada piloto (string nombre, string escuderia, float tiempo, int puntos) cada uno de estos datos esta en formato texto, posteriormente se hace la asginación de dichos datos a los atributos del objeto piloto.
>
3. Los inputs del usuario en caso de que desea agregar un nuevo piloto a la carrera. 

## Descripción de las salidas del avance de proyecto
1. Resultados de carrera: Se despliega una tabla con los resultados de la carrera ordenado los pilotos segun su atributo tiempo. 
>
2. Se hace una escritura de archivos con los resultados de cada carrera con los tres primeros lugares.

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
>
2. Insertar un nuevo piloto y re-ordenar la lista (arbol binaro)
>
Algoritmo utilizado: Recorrido in-order  árbol binario
>
Utilice el recorrido inorder para recorrer el árbol binario y visitar sus nodos en orden ascendente, que  va de la sig manera:
>
Subárbol izquierdo
>
Nodo raíz
>
Subárbol derecho
>
Este recorrido nos ayuda a que los elementos del árbol se procesen en orden creciente. Para realizar este recorrido, se usa una función recursiva que primero visita el subárbol izquierdo, luego el nodo actual, y finalmente el subárbol derecho.
>   
Inserción de un nuevo nodo: 
>
Para insertar un nodo en un árbol binario de búsqueda, se sigue una estrategia de comparación. Comenzando en la raíz:

Si el valor del nuevo nodo(especificamente de su atributo tiempo) es menor que el valor del nodo actual, se avanza al subárbol izquierdo.
Si el valor es mayor, se avanza al subárbol derecho.
Si se llega a un lugar donde no hay nodo (un NULL), se inserta el nuevo nodo en esa posición.

Complejidad (recorrido inorder):
Mejor caso:O(n)
>
Caso promedio: O(n)
>
Peor caso: O(n)
>
Complejidad (insertar un nuevo nodo):
Mejor caso:O(logn)
>
Caso promedio: O(logn)
>
Peor caso: O(n)


#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.
>
1. Estructura de Datos: vector
>
Uso: Se utilizo para almacenar pilotos, escuderías, tiempos y puntos. Además, la función quickSort y algunos otros tipos de manipulación de datos operaran sobre un vector, es por eso que se utilizó para la primer entrega para ordenar la lista de pilotos.
>
Complejidad:
>
>Acceso aleatorio: O(1)
>
>Caso promedio: O(n)
>
>Peor de los casos: O(n)
>

2. Algoritmo de Ordenamiento: quickSort
>
Uso: Se utiliza para ordenar el vector de objetos Piloto basado en el atributo tiempo.
Complejidad:
>
>Mejor caso: O(n log n)
>
>Caso promedio: O(n log n)
>
>Peor caso: O(n²) (ocurre cuando el pivote es siempre el elemento mayor o menor)
>

 Se utilizo Quicksort porque es un algoritmo de ordenamiento eficiente para listas grandes debido a su complejidad promedio O(n log n). Se seleccionó por su rendimiento general en la mayoría de los casos.
>
3. Estructura de Datos: Árbol Binario de Búsqueda (ArbolBinario)
>
Se implementó para manejar la inserción y manipulación de objetos Piloto de manera ordenada. Se utiliza para insertar pilotos, imprimir en orden (in-order traversal) y actualizar puntos.
>
Complejidad:
>
>Inserción: O(h), donde h es la altura del árbol.
>
Recorrido in-order: O(n), donde n es el número de nodos.
>
>Mejor caso de inserción: O(log n) en un árbol balanceado.
>
>Peor caso de inserción y recorrido: O(n) (cuando el árbol está desbalanceado).
>
4. Operaciones de Asignación de Puntos:
>
Complejidad: O(n)
>
Descripción: La función asignarPuntosInOrder recorre el árbol in-order y asigna puntos a los nodos basados en un array de puntos. Esta operación se ejecuta en O(n) ya que recorre todos los nodos una vez.
>
Extracción de Elementos In-order:
>
Complejidad: O(n)
>
Descripción: La función extraerTresElementosInOrder extrae los nombres de los tres primeros elementos del árbol de forma in-order, operando en O(n) en el peor de los casos.
>
5. Lectura de Archivos
>
Se utiliza ifstream para leer archivos de texto y CSV, y ofstream para escribir resultados.
>
Complejidad: Lectura y escritura: Depende del tamaño del archivo, con una complejidad de O(n) donde n es el número de líneas o elementos a leer/escribir. La lectura de archivos es lineal respecto al número de elementos y es necesaria para cargar los datos iniciales de los pilotos y escribir los resultados de la carrera.
>
6. Simulación de Espera (this_thread::sleep_for)
>
Se utilizó para simular la espera durante la carrera.
>
Complejidad: No afecta la complejidad algorítmica del programa en términos de operaciones de datos, pero añade un retraso controlado en tiempo de ejecución.

#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.
>
Algunos componentes o funciones extras del programa son: 
>
1. La creación de objetos y asignación de atributos, que tiene un complejidad de O(n2) ya que se utiliza un doble bucle for para crear una tabla de 20x4 (Piloto *piloto[4][20]).
>
2. Mostar carreras por pantalla: se hace un recorrido a la lista que se crea a partir del archivo con un bucle for, por lo que tien complejidad O(n)
>
3. dentro del bucle while (que nos permite reguntar usuario si quiere ver otra carrera, agregar un piloto, o salir) tiene complejidad O(1) ya que no se utilizan estructuras de datos adicionales que crezcan con el número de iteraciones, solo se necesita espacio para las variables de control y la entrada del usuario.
>
4. al crear archivo de ganadores se utiliza un bucle for de complejidad O(n) para recorrer la lista de carreras y comprobar que es la carrera seleccionada para crear el archivo correspondiente a la carrera con dicho nombre.
>
Tomando en cuenta este análisis de complejidad y el análisis del punto anterior de las estructuras de datos utilizados, podemos ver que por más que tenemos una estructura de datos con complejidad O(logn) o O(1), al crear los objetos por medio de un doble bucle for la complejidad final es O(n2).
>
NOTA: La complejidad de ciertas funciones se  encuentra comentada en el codigo

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
QuickSort
>
Quicksort tiene una complejidad de espacio adicional de O(logn) debido a la recursión. Esto es más eficiente que otros algoritmos como Merge Sort, que requiere O(n) espacio adicional, lo que es ventajoso al ordenar estructuras más grandes como en este caso para la lista de pilotos. Es por eso que se decidió usar este algoritmo

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
Arbol binario
>
Tomando en cuenta los análisis de complejidad anteriores, un árbol binario, tiene una complejidad promedio de O(logn) al insertar un nodo si el árbol está balanceado. Esto es ideal nuestro programa ya que nos permite agregar pilotos de forma secuencial y mantener una estructura relativamente ordenada.

Para la parte del ordenamiento el recorrido inorder (izquierda-raíz-derecha) nos garantiza que los elementos se impriman de menor a mayor segun el atributo tiempo, el recorrido inorder nos permite mostrar automáticamente los pilotos de manera ordenada por ese atributo.
Otra buena razónde utilizar el arbol binario para el ordenamiento despues de insertar un piloto es que nos permite tener cierta escalabilidad, en escenarios con un número creciente de pilotos, el árbol binario sigue ofreciendo buenas prestaciones en inserción, búsqueda y recorrido en comparación con estructuras de datos como listas, donde el acceso y la ordenación son más tardados.
 
### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.
Si lograste este criterio anteriormente, copia aquí tu argumentación. Si no, ésta es una nueva oportunidad para lograrlo. Escribe aquí tu aprendizaje y tus argumentos sobre por qué consideras que ahora ya has desarrrollado este criterio y dónde se puede observar el desarrollo que mencionas.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
El programa leerá los archivos(carreras) que contienen los  nombres, escuderias, tiempos y puntos de cada uno de los pilotos, asignando cada uno de estos datos al atributo correspondiente del objeto Piloto, para posteriormente almacenar los objetos(Pilotos) en un vector y despues manipular la información

### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta
Al final el prorgrama crea un archivo por cada carrera que el usuario haya seleccionado con las 3 mejores posiciones finales de los pilotos segun sus tiempos y asignando los puntos correspondientes a cada piloto.