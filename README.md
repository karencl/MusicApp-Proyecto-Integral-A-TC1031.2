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
...

## SICT0301B: Evalúa los componentes

#### Presenta Casos de prueba para todas las funciones y procedimientos del programa.
...

#### Hace un análisis de complejidad correcto y completo para todo el programa y sus componentes.
...

## SICT0303B: Implementa acciones científicas

#### Implementa mecanismos para consultar información de las estructuras correctos y útiles.
Como se mencionó en la parte de arriba, además del archivo *.cpp* que contiene los casos de prueba, tenemos el archivo *main.cpp*, que contiene un menú con una serie de opciones, que nos van a permitir:

- Visualizar la playlist
- Editar la playlist
  - Agregar canciones
  - Eliminar canciones
- Ordenar la playlist 
  - Por nombre (ascendente/ descendente)
  - Por autor (ascendente/ descendente)
  - Por duración (en minutos)
- Buscar una canción
  - Por nombre
  - Por autor
  - Por tiempo de duración (en minutos)

#### Implementa mecanismos de lectura de archivos correctos y útiles.
En la parte de los archivos, podemos encontrar el de "songs.csv"; el cual contiene una lista de canciones con sus respetivas duraciones y autores.

#### Implementa mecanismos de escritura de archivos correctos y útiles. 
El archivo y mencionado, se abre desde que inicia el programa y es usado para la extracción de datos, con el fin de usarlos en la estructura lineal, como almacén de estos.

Se usan algunas funciones extras como *getData()*, *showListForward()*, *showListBackwards()*, *addSong()* y *deleteSong()*, con el fin de realizar más que lecturas, al agregar o eliminar líneas de datos en el archivo.
