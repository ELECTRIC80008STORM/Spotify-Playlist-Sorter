# Spotify Playlist Sorter

Organiza tus playlist por título, artistas y de muchas formas más.

Este proyecto busca emular el sistema de ordenamiento de las canciones en Spotify, permitiéndote ordenar las canciones de una forma más sencilla y rápida, todo esto para que puedas personalizar tus playlists como tu desees.


## Formas de Organizarlas

Spotify te limita a solo ciertas opciones para organizar tus playlists, sin embargo, a veces estas no son suficientes para que tus playlists queden como tú quieres, por eso, a continuación están las maneras en que te ayudamos a organizar tus playlists.

- **Título**

- **Artista**

- **Álbum**

- **Duración**

- **Popularidad**

---

[Ir a la sección de correciones](#correcciones)

---

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

### Métodos Clave (o con mayor impacto) del Archivo Playlist.cpp

#### trim(const string& str)
Esta función recibe una string y elimina los espacios en blanco que posea. Utiliza las funciones públicas de los strings llamadas “find_first_not_of()” y “find_last_not_of()” las cuales recorren toda la string en busca del primer o último elemento que no sea igual al parámetro que se les dió. Por lo tanto su complejidad es la siguiente:

**Complejidad Temporal:**
- Ω(1) en el caso de que el primer y último carácter no sean un espacio en blanco.
- Θ(n) en el caso de que el carácter se encuentre en medio de la string.
- O(n) en caso de que no haya espacios en blanco o se encuentren en medio de la string.

**Complejidad Espacial:**
- O(n) por tratarse de una string.

#### parseLine(const string& line)
Esta función recibe una string con la línea a la que se le dará el formato correcto. Se van almacenando “tokens” que son los carácteres pertenecientes a los atributos, una vez se obtuvieron todos los carácteres de un token, el token se recorta mediante la función “trim()” para eliminar cualquier espacio blanco, está función recorre todo la string del token, después el token es almacenado en un vector “tokens”. Debemos tener en cuenta que se utiliza una función que incluye un ciclo dentro de nuestro ciclo principal y que está solo se utiliza una cantidad limitada de veces dentro del programa para poder comprender su complejidad temporal. Tomaremos **n** como la cantidad de caracteres a recorrer en el ciclo for principal, **k** como la cantidad total de tokens y **m** como la longitud del token. Nuestra complejidad la podemos analizar de la siguiente manera, (n + k*m), donde **m** siempre será menor a **n** debido a que los tokens son una substring de la línea. En términos de clasificación del análisis asintótico siguiendo la notación “Big O”, la complejidad será la siguiente:

**Complejidad Temporal:**
- Ω(n) este caso se daría en el mejor caso de trim (Ω(1)), dando una complejidad total de Ω(n + k).
- Θ(n)
- O(n)

**Complejidad Espacial:**
- O(n) por depender mayormente del tamaño de la string dada.

#### Playlist::enqueueTrackData(string file)
Esta función recibe una string con el nombre del archivo del cuál leerá los datos guardados de las canciones de esa playlist, estos incluyen los atributos título, artista, álbum, duración y popularidad de las canciones. Por cada línea llama a la función “parseLine()” con la cuál obtiene los datos y les da el formato correcto, está función tiene una complejidad lineal respecto al tamaño de la línea. Una vez lee los datos los guarda en un deque “playlist”. Dado que depende de la cantidad de canciones guardadas en la playlist, su complejidad es la siguiente:

**Complejidad Temporal:**
- Ω(n) por la naturaleza del programa el archivo jamás estará vacío.
- Θ(n)
- O(n)

**Complejidad Espacial:**
- O(n) dependiendo de la cantidad de canciones registradas.

#### Playlist::lowercase(string word)
Esta función recibe una string la cuál es recorrida mediante la función “transform” de la string. Al pasar por cada carácter en el que sea posible lo convierte en minúsculas. Dado que siempre recorrerá la string completa independientemente de la misma, su complejidad será la siguiente:

**Complejidad Temporal:**
- Ω(n)
- Θ(n)
- O(n)

**Complejidad Espacial:**
- O(n) por tratarse de una string.

#### Playlist::displaySongs()
Esta función recorrerá el deque “playlist” completo imprimiendo el título, artista/s y álbum de todas las canciones contenidas en la playlist. Por la naturaleza del programa el deque jamás estará vacío, por lo tanto su complejidad es la siguiente:

**Complejidad Temporal:**
- Ω(n)
- Θ(n)
- O(n)

**Complejidad Espacial:**
- O(1) dado que solo se están imprimiendo los datos, cosa que no consume memoria adicional.

#### Playlist::storeTrackData(string originalFile)
Esta función recibe una string con el nombre del archivo en el cuál guardará los datos contenidos en el deque “playlist”. Crea un archivo temporal en el cuál ingresa todos los datos guardados, una vez finaliza de ingresar los datos el archivo temporal reemplaza al archivo original manteniendo el nombre del original. Dado que depende de los datos guardados en el deque, su complejidad temporal será la siguiente.

**Complejidad Temporal:**
- Ω(n) por la naturaleza del programa el deque jamás estará vacío.
- Θ(n)
- O(n)

**Complejidad Espacial:**
- O(1) siempre y cuando solo consideremos el espacio utilizado en la memoria RAM.

### Métodos Clave (o con mayor impacto) del Archivo main.cpp

#### choiceValidation(int lowerLimit, int upperLimit)
Esta función recibe los límites que se le impondrán al usuario para su respuesta, y siempre que el usuario responda fuera de estos o con algún carácter no aceptable, se le mantendrá en un bucle hasta que responda correctamente.

**Complejidad Temporal:**
- Ω(1) en el caso de que el usuario ingrese a la primera un valor aceptable.
- Θ(1) en el mismo caso que arriba, dado que sería el caso más probable en el programa.
- O(n) en caso de que el usuario ingrese un valor no aceptable repetidamente.

**Complejidad Espacial:**
- O(1) debido a que la función ocupa una cantidad fija de variables.

### Complejidad Final del Programa

Dado que el programa es secuencial, es decir, ninguna función es llamada de manera recursiva, podemos obtener la complejidad final sumando las complejidades de sus componentes. Siempre que inicie el programa el usuario tendrá que elegir una playlist que desee ordenar, por lo que se llamará la función “enqueueTrackData()” la cuál posee una complejidad de **n** para todos los casos, después se le dará opciones de ordenar la playlist, escoger otra playlist o salirse de la aplicación, en el primer escenario en el que escoja ordenar una playlist se usará la función “sort()” de la librería estándar de C++, está función tiene una complejidad de (n log n) para todos los casos, una vez ordenada podrá elegir reordenarla, cambiar de playlist o salirse, independientemente de si ocurre el segundo o tercer escenario, la función “storeTrackData()” se llamará para guardar el último estado de la playlist (cualquier cambió en el orden de las canciones), el segundo escenario luego volverá a dar la opción de elegir una playlist por lo que se repite el flujo inicial, el único escenario que finaliza la aplicación es el tercero, y los dos primeros escenarios tarde o temprano conducen al tercer escenario. La complejidad total del programa será la siguiente:

**Complejidad Temporal:**
- Ω(n) en el caso de que el usuario decida salirse de la aplicación inmediatamente después de seleccionar una playlist.
- Θ(n log n) esté será el caso más común en donde el usuario decide ordenar la playlist y eventualmente se sale.
- O(n log n) esté será el caso en el que el usuario reordene las playlists disponibles varias veces antes de salirse.

**Complejidad Espacial:**
- O(n) dada por el uso del deque para almacenar las canciones.


## Correcciones

### SICT0301: Evalúa los componentes

#### Hace un análisis de complejidad correcto y completo todas las estructuras de datos y cada uno de sus usos en el programa.

Se añadió una sección en el README con el análisis asintótico de la estructura de datos Double-Ended Queue y su uso en el programa. [Ir a la sección.](#double-ended-queue)

#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.

Se añadió una sección en el README con el análisis asintótico de las funciones con mayor impacto en la complejidad al igual que el análisis asintótico final del programa. [Ir a la sección.](#métodos-clave-o-con-mayor-impacto-del-archivo-playlistcpp)

### SICT0302: Toma decisiones

#### Selecciona una estructura de datos adecuada al problema y lo usa correctamente.

Se sustituyó el uso del vector por la double-ended queue incluida en una STL (Standard Template Library). Es usada como un atributo de la clase Playlist para guardar las canciones que se extraen de los archivos. La explicación de su utilidad en el proyecto puede ser encontrada en el análisis asintótico.

**Usado en:**
- Archivo “Playlist.h”, línea 21.
- Archivo “Playlist.cpp”, líneas 104,  311, 352 y 375.

### SICT0303: Implementa acciones científicas

#### Implementa mecanismos para consultar información de las estructuras correctas.

El mecanismo implementado para poder consultar la información del double-ended queue es el método “displaySongs()” de la clase Playlist.

**Declaración del método:**
- Archivo “Playlist.h”, línea 49.

**Definición del método:**
- Archivo “Playlist.cpp”, línea 351.

**Usado en:**
- Archivo “main.cpp”, su uso se da a lo largo de las interacciones de usuario con el menú el cuál es definido en la línea 69.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.

El mecanismo implementado para poder realizar la lectura de archivos es el método “enqueueTrackData()” de la clase Playlist. Este método se apoya de las funciones “trim()” y “parseLine()” para poder darle el formato correcto a la información leída y que pueda ser de utilidad.

**Declaración del método:**
- Archivo “Playlist.h”, línea 47.

**Definición del método y de las funciones auxiliares:**
- Archivo “Playlist.cpp”, línea 25 (trim).
- Archivo “Playlist.cpp”, línea 42 (parseLine).
- Archivo “Playlist.cpp”, línea 82 (enqueueTrackData, en dónde se realiza la lectura de archivos).

**Usado en:**
- Archivo “main.cpp”, su uso se da a lo largo de las interacciones de usuario con el menú el cuál es definido en la línea 69.

#### Implementa mecanismos de escritura de archivos para guardar los datos de las estructuras de manera correcta.

El mecanismo implementado para poder realizar escritura de archivos es el método “storeTrackData()” de la clase Playlist.

**Declaración del método:**
- Archivo “Playlist.h”, línea 50.

**Definición del método:**
- Archivo “Playlist.cpp”, línea 366.

**Usado en:**
- Archivo “main.cpp”, su uso se da a lo largo de las interacciones de usuario con el menú el cuál es definido en la línea 69.


## Nota

- En un futuro se permitirá la extracción de tus propias playlists una vez ingreses con tu cuenta de Spotify.
- También se añadirán nuevas maneras de organizar las canciones de tus playlists e incluso, quizás la opción de crear una nueva playlist con las canciones ordenadas en la nueva forma que elegiste.


## Agradecimientos

Esta aplicación está inspirada en [Spotify Playlist Sorter](https://www.chosic.com/spotify-playlist-sorter/) por Chosic.
