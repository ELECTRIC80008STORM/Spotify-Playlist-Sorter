/* Spotify Playlist Sorter */

#include "Playlist.cpp"
#include "Song.h"
#include "readtype.h"

#include <iostream>
#include <deque>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

// Declaración de funciones
void menu(int, Playlist);
int choiceValidation(int, int);

// Declaración de variables globales
string option1 = "Título ↓";
string option2 = "Artista ↓";
string option3 = "Álbum ↓";
string option4 = "Duración ↓";
string option5 = "Popularidad ↓";
string playlistName;
string fileName;
int choice;

int main(){
    Playlist playlist;

    // Introducción al programa
    printf("\e[1;1H\e[2J");
    cout << "Spotify Playlist Sorter" << endl << endl;

    sleep_for(seconds(2));

    cout << "Bienvenido/a\n" "Preparate para poder organizar tus playlist como llevas"
    " tiempo queriendo!!!" << endl << endl;

    sleep_for(seconds(3));

    cout << "Por el momento la aplicación sigue en desarrollo, por lo que solo podrás"
    " ordenar" << endl << "playlists de ejemplo, esperamos que"
    " para la próxima vez que ingreses ya puedas" << endl << 
    "disfrutar de la aplicación como te mereces.";

    cout << endl << endl;

    sleep_for(seconds(7));
    printf("\e[1;1H\e[2J");

    menu(100, playlist);

    return 0;
};

/**
 * Muestra un menú interactivo y maneja las opciones del usuario para organizar y mostrar las listas de reproducción.
 * Permite seleccionar y ordenar las listas de reproducción basadas en distintos criterios como título, artista, álbum,
 * duración y popularidad. También proporciona opciones para seleccionar diferentes listas de reproducción y salir
 * de la aplicación. Las operaciones de ordenamiento pueden ser ascendentes o descendentes.
 *
 * @param int option: El número de la opción seleccionada en el menú.
 * @param Playlist playlist: La lista de reproducción que se está manejando.
 * @return
 */
void menu(int option, Playlist playlist){
    switch (option){
    case 100:
        cout << "Selecciona la playlist que desees ordenar: " << endl << endl;
        cout << "1. Top 50 - Global\n" << "2. Top 50 - Mexico\n" << endl << endl;
        cout << "Selecciona el número de la opción que desees escoger: ";
        choice = choiceValidation(1,2);
        if(choice == 1){
            playlist.enqueueTrackData("Top 50 - Global Playlist.csv");
            playlistName = "Top 50 - Global";
        } else if(choice == 2){
            playlist.enqueueTrackData("Top 50 - Mexico Playlist.csv");
            playlistName = "Top 50 - Mexico";
        }
        cout << endl << endl;

        playlist.displaySongs();
        cout << endl << endl;
        sleep_for(seconds(7));
        
        menu(0, playlist);
        break;
    case 0:
        cout << "Organizar la playlist en base a: " << endl << endl;
        cout << "1. " << option1 << "\n2. " << option2 <<
        "\n3. " << option3 << "\n4. " << option4 << "\n5. " << option5
        << endl << endl;
        cout << "6. Seleccionar otra playlist" << endl;
        cout << "7. Salir de la aplicación" << endl << endl;
        cout << "Selecciona el número de la opción que desees escoger: ";
        choice = choiceValidation(1,7);
        if(choice == 1 && option1 != "Título ↓"){
            choice = 101;
        } else if(choice == 2 && option2 != "Artista ↓"){
            choice = 102;
        } else if(choice == 3 && option3 != "Álbum ↓"){
            choice = 103;
        } else if(choice == 4 && option4 != "Duración ↓"){
            choice = 104;
        } else if(choice == 5 && option5 != "Popularidad ↓"){
            choice = 105;
        }
        option1 = "Título ↓";
        option2 = "Artista ↓";
        option3 = "Álbum ↓";
        option4 = "Duración ↓";
        option5 = "Popularidad ↓";
        printf("\e[1;1H\e[2J");
        menu(choice,playlist);
        break;
    case 1:
        playlist.sortSongs(Playlist::Title,Playlist::Ascending);
        cout << endl << playlistName << endl << endl;
        playlist.displaySongs();
        cout << endl << endl;
        sleep_for(seconds(3));
        option1 = "Título ↑";
        menu(0,playlist);
        break;
    case 2:
        playlist.sortSongs(Playlist::Artist,Playlist::Ascending);
        cout << endl << playlistName << endl << endl;
        playlist.displaySongs();
        cout << endl << endl;
        sleep_for(seconds(3));
        option2 = "Artista ↑";
        menu(0,playlist);
        break;
    case 3:
        playlist.sortSongs(Playlist::Album,Playlist::Ascending);
        cout << endl << playlistName << endl << endl;
        playlist.displaySongs();
        cout << endl << endl;
        sleep_for(seconds(3));
        option3 = "Álbum ↑";
        menu(0,playlist);
        break;
    case 4:
        playlist.sortSongs(Playlist::Duration,Playlist::Ascending);
        cout << endl << playlistName << endl << endl;
        playlist.displaySongs();
        cout << endl << endl;
        sleep_for(seconds(3));
        option4 = "Duración ↑";
        menu(0,playlist);
        break;
    case 5:
        playlist.sortSongs(Playlist::Popularity,Playlist::Ascending);
        cout << endl << playlistName << endl << endl;
        playlist.displaySongs();
        cout << endl << endl;
        sleep_for(seconds(3));
        option5 = "Popularidad ↑";
        menu(0,playlist);
        break;
    case 6:
        fileName = playlistName + " Playlist.csv";
        playlist.storeTrackData(fileName);
        menu(100,playlist);
        break;
    case 7:
        fileName = playlistName + " Playlist.csv";
        playlist.storeTrackData(fileName);
        cout << "Ha salido exitosamente de la app.";
        break;
    case 101:
        playlist.sortSongs(Playlist::Title,Playlist::Descending);
        cout << endl << playlistName << endl << endl;
        playlist.displaySongs();
        cout << endl << endl;
        sleep_for(seconds(3));
        menu(0,playlist);
        break;
    case 102:
        playlist.sortSongs(Playlist::Artist,Playlist::Descending);
        cout << endl << playlistName << endl << endl;
        playlist.displaySongs();
        cout << endl << endl;
        sleep_for(seconds(3));
        menu(0,playlist);
        break;
    case 103:
        playlist.sortSongs(Playlist::Album,Playlist::Descending);
        cout << endl << playlistName << endl << endl;
        playlist.displaySongs();
        cout << endl << endl;
        sleep_for(seconds(3));
        menu(0,playlist);
        break;
    case 104:
        playlist.sortSongs(Playlist::Duration,Playlist::Descending);
        cout << endl << playlistName << endl << endl;
        playlist.displaySongs();
        cout << endl << endl;
        sleep_for(seconds(3));
        menu(0,playlist);
        break;
    case 105:
        playlist.sortSongs(Playlist::Popularity,Playlist::Descending);
        cout << endl << playlistName << endl << endl;
        playlist.displaySongs();
        cout << endl << endl;
        sleep_for(seconds(3));
        menu(0,playlist);
        break;
    }
}

/**
 * Valida que la elección del usuario esté dentro de un rango especificado y lo mantiene en un bucle
 * hasta que su respuesta cumple con lo solicitado.
 *
 * @param int lowerLimit: El límite inferior del rango de elección válido.
 * @param int upperLimit: El límite superior del rango de elección válido.
 * @return int: La elección validada del usuario dentro del rango especificado.
 */
int choiceValidation(int lowerLimit, int upperLimit){
    int choice;
    choice = ReadType<int>("");

    while(choice < lowerLimit || choice > upperLimit){
        cout << "\nIngresá un número válido para la opción que seleccionaste: ";
        choice = ReadType<int>("");;
    }

    return choice;
}