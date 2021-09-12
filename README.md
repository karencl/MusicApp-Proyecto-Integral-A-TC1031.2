# MusciApp - Proyecto-Integral-A-TC1031.2
El proyecto de "MusicApp", desarrollado para el proyecto integrador A, está basado en la lógica de una aplicación de música, en donde se puede recorrer una lista de canciones, buscar por nombre, autor o duración de la misma y ordenar la playlist de diferentes formas.

El objetivo que iene este proyecto, es poner en práctica algoritmos de ordenamiento, el uso de estructuras lineales y árboles, para resolver alguna problemática o eficientar el funcionamiento de algún programa.

En la parte de abajo, podremos encontrar la estructura con la que este programa fue hecho, el análisis de complejidad de los algoritmos usados, aclacariones sobre los casos de prueba y la explicación de algunos recursos extra usados en este trabajo, así como archivos *.csv* y un *menú* para facilitar la interacción del usuario con el programa.

## SICT0302B: Toma decisiones

#### Selecciona y usa una estructura lineal. 

#### Selecciona un algoritmo de ordenamiento. 

#### Usa un árbol adecuado para resolver un problema.

## SICT0301B: Evalúa los componentes

#### Presenta Casos de prueba para todas las funciones y procedimientos del programa.

#### Hace un análisis de complejidad correcto y completo para todo el programa y sus compenetes.

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

Se usan algunas funciones extras como *getData()*, *addSong()* y *deleteSong()*, con el fin de realizar más que lecturas, al agregar o eliminar líneas de datos en el archivo.
