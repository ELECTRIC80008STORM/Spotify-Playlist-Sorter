/*
* Spotify Playlist Sorter
* Rommel T.
*/

/*
Solución al problema en el cual "cin" deja de aceptar el input del usuario.
Copiado de: https://latedev.wordpress.com/2011/09/13/simple-input-bullet-proofing-in-c/
La función fue editada ligeramente para ser de utilidad en el programa.
*/

#ifndef INC_READTYPE_H
#define INC_READTYPE_H

#include <iostream>
#include <string>
#include <limits>

/**
 * Lee la entrada de tipo T (tipo de dato genérico)
 * del usuario con un mensaje de aviso.
 * Si detecta una entrada errónea, introduce al usuario en un 
 * bucle hasta que introduzca una entrada válida.
 * @param const std::string& prompt: el mensaje que se muestra al usuario.
 * @return T: regresa el valor de la entrada de tipo T
*/
template <typename T>
T ReadType( const std::string & prompt  ) {
    T n;
    while( (std::cout << prompt) && ! (std::cin>> n) ) {
        std::cout << "El valor que ingresaste no representa una opción!\n";
        std::cin.clear();
        std::cin.ignore( std::numeric_limits<int>::max(), '\n' );
    }
    return n;
}

#endif