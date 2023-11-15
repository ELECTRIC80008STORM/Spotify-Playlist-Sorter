# Spotify Playlist Sorter

Organiza tus playlist por títulos, artistas y de muchas formas más.

Este proyecto busca emular el sistema de ordenamiento de las canciones en Spotify, permitiéndote ordenar las canciones de una forma más sencilla y rápida, todo esto para que puedas personalizar tus playlists como tu desees.


## Formas de Organizarlas

Spotify te limita a solo ciertas opciones para organizar tus playlists, sin embargo, a veces estas no son suficientes para que tus playlists queden como tú quieres, por eso, a continuación están las maneras en que te ayudamos a organizar tus playlists.

- **Título**

- **Artista**

## Análisis de Complejidad / Análisis Asintótico

### Introsort

El algoritmo usado para ordenar en este programa es el algoritmo “sort” incluido en una STL (Standard Template Library), este algoritmo usa internamente un algoritmo de ordenamiento híbrido llamado “Introsort” o “Introspective Sort” que se compone de _Quicksort_, _Heapsort_ e _Insertionsort_, el objetivo de esta combinación es evitar la peor complejidad temporal de Quicksort a la vez que se mejora el desempeño en el resto de casos.
- Quicksort: La parte fundamental de _quicksort_ es escoger el pivote correcto, en este caso se usa una técnica llamada _mediana de 3_, que busca reducir el efecto al encontrarse con ciertos casos específicos, una vez se escogió un pivote, lo que se hace es poner todos los elementos más pequeños a su izquierda y todos los más grandes a la derecha, esto de manera recursiva, sin embargo, entre más iteraciones ocurren, mayor es la probabilidad de que se esté lidiando con el peor caso de complejidad **O(n^2)**, razón por la que tras cierta cantidad de saltos recursivos, se empieza a utilizar _Heapsort_.
- Heapsort: Este algoritmo se suele dividir en dos fases, la primera en donde se forman los montículos “heaps”, y la segunda en donde se suele extraer el elemento más grande de manera sucesiva. La ventaja es que Heapsort siempre posee una complejidad de **O(n log n)**.
- Insertionsort: Por último, después de que se alcanzaron cierta cantidad de iteraciones, se utiliza _insertionsort_, esto debido a que su mejor caso de complejidad es lineal **Ω(n)**, cosa de la cual es posible aprovecharse gracias a que previamente ya se dejó mayormente ordenado por _Quicksort_ y _Heapsort_.

La ventaja de Introsort es que garantiza una **complejidad temporal** de **O(n log n)** gracias al uso de _Heapsort_, y suele comportarse de incluso mejor manera al usar _Quicksort_ y _Insertionsort_, su **complejidad espacial** es de **O(log n)** debido a las llamadas recursivas que realiza quicksort.

### Double-Ended Queue

La estructura de datos utilizada en este programa es una “double-ended queue” incluida en una STL (Standard Template Library), este tipo de estructura de datos ofrece una complejidad temporal constante para siempre y cuando se trate de los elementos en los extremos, su **complejidad temporal** al **acceder**, **insertar** o **eliminar** algún elemento del frente o el final es de **O(1)**. En **casos especiales** en que se requiera realizar alguna **operación a la mitad**, su **complejidad temporal** puede ascender a **O(n)** pues se vería obligado a navegar a través de los elementos previos para acceder al que necesita. Como en la mayoría de estructuras lineales, posee una **complejidad espacial** de **O(n)**, es decir, proporcional al número de elementos que se almacenen en ella. 

La ventaja de usar esta estructura en este proyecto concreto se da debido a que ofrece un rendimiento similar al de un vector mientras ofrece una mayor rapidez para la inserción o eliminación de elementos. Si bien actualmente no se requieren ninguna de estas dos una vez se llena la estructura, estás operaciones si serán necesarias una vez se logré conectar la aplicación a los servidores de Spotify, pues cada cierto tiempo se actualizarán los datos guardados para añadir o eliminar cualquier canción en caso de que el usuario pudiera haber modificado su playlist. Dado que no se requerirá un acceso aleatorio a los datos en ningún proceso de la app, esto nos asegura que siempre nos mantendremos en el mejor de los casos, es decir, en una complejidad de O(1).


## Nota

- En un futuro se permitirá la extracción de tus propias playlists una vez ingreses con tu cuenta de Spotify.
- También se añadirán nuevas maneras de organizar las canciones de tus playlists e incluso, quizás la opción de crear una nueva playlist con las canciones ordenadas en la nueva forma que elegiste.

## Agradecimientos

Esta aplicación está inspirada en [Spotify Playlist Sorter](https://www.chosic.com/spotify-playlist-sorter/) por Chosic.
