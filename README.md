# IMPORTANTE ---> correcciones:

- Se corrigió el error de no poder abrir el archivo *songs.csv*, por lo que ya se puede apreciar la lectura de archivos, su acomodo en la estructura lineal y el algoritmo de ordenamiento y búsqueda aplicado en esta.

# IMPORTANTE ---> especificaciones de los archivos:
- Se agregó un archivo llamado "originalSongs.txt" que contiene las canciones originales que se utilizaron para las prubebas del programa. En caso de el archivo "songs.csv" se quiera regresar a su estado original, solo se tienen que copiar los datos del nuevo archivo agregado que tontiene las originales.


# MusciApp - Proyecto-Integral-A-TC1031.2
El proyecto de "MusicApp", desarrollado para el proyecto integrador A, está basado en la lógica de una aplicación de música, en donde se puede recorrer una lista de canciones, buscar por nombre, autor o duración de la misma y ordenar la playlist de diferentes formas.

El objetivo que iene este proyecto, es poner en práctica algoritmos de ordenamiento, el uso de estructuras lineales y árboles, para resolver alguna problemática o eficientar el funcionamiento de algún programa.

En la parte de abajo, podremos encontrar la estructura con la que este programa fue hecho, el análisis de complejidad de los algoritmos usados, aclacariones sobre los casos de prueba y la explicación de algunos recursos extra usados en este trabajo, así como archivos *.csv* y un *menú* para facilitar la interacción del usuario con el programa.

## SICT0302B: Toma decisiones

#### Selecciona y usa una estructura lineal.
Para este proyecto decidí utilizar una lista doblemente enlazada como estructura lineal, debido a que estamos hablando de una playlist de canciones y la forma en la que normalmente estas se recorrer, es hacia adelante y hacia atrás constantemente. Es decir, esto sería al equivalente a los apuntadores que de un elemento en l estructura, que apuntan hacia el elemento anterior y posterior de este.

En esta lista se van encontrar las canciones del archivo *songs.csv*, que se agregan una vez que se inicia el programa.
Así mismo, se podrán hacer modificaciones en esta, al acomodar, agregar o eliminar sus elementos.

#### Selecciona un algoritmo de ordenamiento.
El algoritmo de ordenamiento que utilicé fue el de *Quick Sort*, ya que a pesar de que la complejidad de tiempo en el peor de los casos es *O(n^2)*, este cuenta con una complejidad de tiempo bastante aceptable para el mejor caso y el promedio de estos, o sea: *O(n log(n))* y así mismo, en cuanto a complejidad de espacio en el peor e los casos, se tiene que es *O(log(n))*, que resulta mejor a comparación del *Merge Sort* por decir un ejemplo.

#### Usa un árbol adecuado para resolver un problema.
El árbol que seleccioné para mi programa, fue un *Splay Tree*, debido a que sus complejidades en tiempo (O(log(n) en la mayoría de los casos en cuanto a manipulación del árbol), son bastante buenas para inserción, borrado, búsqueda y demás.
Con esta implementación, el recorrido y manipulación de la estructura resulta rápido y eficiente en cuanto a tiempo y memoria.

**NOTA: Se hace un manejo diferente para el contenido de la lista doblemente enlazada y el árbol. Pues en la lista se guardan el nombre, autor y duración de cada canción, mientras que en el árbol solo se guardan las duraciones, para jugar un poco con estas y lo que se le muestra al usuario. (La lista de canciones que siempre se muestra en el output, sale de las funciones de la lista doblemente enlazada y no del árbol.**

## SICT0301B: Evalúa los componentes

#### Presenta Casos de prueba para todas las funciones y procedimientos del programa (Esto se entregó en la Integral B)

#### Hace un análisis de complejidad correcto y completo para todo el programa y sus componentes.
- **Busca elemento en lista:**
Al usar una búsqueda secuencial, tenemos que en el peor de los casos tenemos O(n), debido a que se puede llegar a recorrer la lista por completo para encontrar o no un elemento.
Se usó este método y no el binario, debido a que no siempre la lista va a estar ordenada.

- **Ordena lista:**
Se utilizó el método de *Quick Sort*, que tiene una complejidad de O(n^2) para el peor de los casos y O(n log(n)) para el promedio, debido a que con cada vuelta, *n* se parte en 2.
Para la parte del *Swap* para los datos de los elementos, tenemos que la complejidad es O(1). Es constante por el simple hecho de que en este caso, solo se a hacer la operación de cambiar los datos de una canción por otra.

- **Muestra lista:**
Tanto para el caso de mostrarla de principio a fin, como de fin a principio, tenemos que la complejidad es de O(n) debido a que la lista se recorre por completo para ir imprimiendo los datos de cada elemento.

- **Llena lista:**
Depende de la cantidad de líneas de información que hayan en el archivo *songs.csv*, por lo que el tiempo de complejidad va a ser de O(n).

- **Vaciar lista:**
La complejidad de tiempo va a ser de O(n), debido a que se tiene que recorrer por completo la lista, para ir eliminando cada uno de sus elementos.

- **Agregar un elemento a la lista:**
Es O(1), o sea constante, debido a que siempre se van a insertar al final, usando *tail*.

- **Eliminar un elemento a la lista:**
En el peor de los casos vamos a tener una complejidad de O(n), ya que se busca el elemento a eliminar primero (por su index); por lo que puede estar al inicio, en medio, al final o simplemente no existir y devolver un mensaje de falla, cuando se llegue a dicha conclusión (o sea al final de ésta).

- **Llena árbol:**
Al igual que con la lista doblemente enlazada, depende de la cantidad de líneas de información que hayan en el archivo *songs.csv*, por lo que el tiempo de complejidad va a ser de O(n).

- **Agregar un elemento al árbol:**
En el peor de los casos se tiene una complejidad de O(log(n)), debido no se recorre el árbol por completo, sino que más bien, solo se va pasando de nivel en nivel, según la posición que el elemento a agregar deba tener y haciendo las rotaciones necesarias para ello. (O sea no se recorre todo el árbol en si).

- **Eliminar un elemento del árbol:**
En el método de "remove()" se tiene una complejidad de tiempo de O(log(n)), ya que se va haciendo un tipo de búsqueda, hasta encontrar el elemento a eliminar (sin necesidad de pasar por cada nodo del árbol), para al final borrarlo y acomodar el árbol nuevamente.

- **Vaciar árbol:**
En este caso si se va a requerir recorrer todo el árbol, por lo que la complejidad de tiempo de esta función es de O(n).

- **Obtener el tamaño de la playlist (mediante el árbol):**
En mi programa este método tiene una complejidad de tiempo constante O(1), debido a que decidí hacer un atributo que fuera guardando el tamaño del árbol conforme se iban agregando o eliminando nodos.
Sin embargo, si se hubiera sacado el tamaño a través de un recorrido del árbol, este método hubiera tenido una comlejidad de tiempo (para el peor de los casos) de O(n), debido a que se hubiera tenido que pasar por cada nodo para irlos contando hasta terminar.

- **Obtener la duración total de la playlist (mediante el árbol):**
Esto también tiene una complejidad de tiempo de O(n), ya que se requiere obtener el valor de cada nodo, e irlos sumando en una variable que guarda el tiempo total en segundos (luego ya se pasa a minutos y segundos).

- **Extras:**
Mostrar el menú tiene una complejidad O(n), debido al *n* número de opciones que se muestran.
Imprimir una sola canción es de complejidad contante, o sea: O(1)
Modificar el archivo de las canciones tiene una complejidad de O(n), debido a que se recorre la lista entera para escribir los datos nuevamente.

## SICT0303B: Implementa acciones científicas

#### Implementa mecanismos para consultar información de las estructuras correctos y útiles.
Como se mencionó en la parte de arriba, además del archivo *.cpp* que contiene los casos de prueba, tenemos el archivo *main.cpp*, que contiene un menú con una serie de opciones, que nos van a permitir:

- Visualizar la playlist
- Editar la playlist
  - Agregar canciones
  - Eliminar canciones 
- Ordenar la playlist 
  - Por nombre 
  - Por autor 
- Buscar una canción
  - Por nombre
  - Por autor
- Obtener el tamaño de la lista (cantidad de canciones)
- Obtener la duración (en minutos y segundos) total de la playlist
- Vaciar playlist (o sea la lista y el árbol)

#### Implementa mecanismos de lectura de archivos correctos y útiles.
En la parte de los archivos, podemos encontrar el de "songs.csv"; el cual contiene una lista de canciones con sus respetivas duraciones y autores.

Para obtener la información de este archivo se utilizan funciones *getData()*, con el fin de formar una estructura con ésta.

#### Implementa mecanismos de escritura de archivos correctos y útiles. 
El archivo y mencionado, se abre desde que inicia el programa y es usado para la extracción de datos, con el fin de usarlos en la estructura lineal, como almacén de estos.

Se usan algunas funciones extras como *addSong()*, *deleteSong()*, *quickSort()* y *sequentialSearch()* con el fin de ir modificando la estructura, para al final actualizar el archivo "songs.csv" (o sea: escribir los nuevos datos en éste).

IMPORTANTE: cuando se modifica el archivo, se utiliza uno nuevo temporalmente para tener los nuevos datos. Sin embargo, en caso de que se quisieran obtener los datos del archivo demo de las canciones, se pueden encontrar en el archivo "originalSongs.txt". 
