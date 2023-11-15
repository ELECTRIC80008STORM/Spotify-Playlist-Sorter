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
string playlistName;
int choice;

int main(){ // TODO: Reactivate the delays
    Playlist playlist;

    // Introducción al programa
    printf("\e[1;1H\e[2J");
    cout << "Spotify Playlist Sorter" << endl << endl;

    // sleep_for(seconds(2));

    cout << "Bienvenido/a\n" "Preparate para poder organizar tus playlist como llevas"
    " tiempo queriendo!!!" << endl << endl;

    // sleep_for(seconds(3));

    cout << "Por el momento la aplicación sigue en desarrollo, por lo que solo podrás"
    " ordenar" << endl << "playlists de ejemplo, esperamos que"
    " para la próxima vez que ingreses ya puedas" << endl << 
    "disfrutar de la aplicación como te mereces.";

    cout << endl << endl;

    // sleep_for(seconds(7));
    printf("\e[1;1H\e[2J");

    menu(100, playlist);

    return 0;
};

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
        sleep_for(seconds(8));
        
        menu(0, playlist);
        break;
    // TODO: Add the other sorting options
    // TODO: Add the option to change the playlist
    // TODO: Add the playlist method to store the previous data
    case 0:
        cout << "Organizar la playlist en base a: " << endl << endl;
        cout << "1. " << option1 << "\n" << "2. " << option2 << endl << endl;
        cout << "3. Salir de la aplicación" << endl << endl;
        cout << "Selecciona el número de la opción que desees escoger: ";
        choice = choiceValidation(1,3);
        if(option1 != "Título ↓" && choice == 1){
            choice = 101;
        } else if(option2 != "Artista ↓" && choice == 2){
            choice = 102;
        }
        option1 = "Título ↓";
        option2 = "Artista ↓";
        printf("\e[1;1H\e[2J");
        menu(choice,playlist);
        break;
    case 1:
        playlist.sortSongs(Playlist::Title,Playlist::Descending);
        cout << endl << playlistName << endl << endl;
        playlist.displaySongs();
        cout << endl << endl;
        sleep_for(seconds(3));
        option1 = "Título ↑";
        menu(0,playlist);
        break;
    case 2:
        playlist.sortSongs(Playlist::Artist,Playlist::Descending);
        cout << endl << playlistName << endl << endl;
        playlist.displaySongs();
        cout << endl << endl;
        sleep_for(seconds(3));
        option2 = "Artista ↑";
        menu(0,playlist);
        break;
    case 3:
        cout << "Ha salido exitosamente de la app.";
        break;
    case 101:
        playlist.sortSongs(Playlist::Title,Playlist::Ascending);
        cout << endl << playlistName << endl << endl;
        playlist.displaySongs();
        cout << endl << endl;
        sleep_for(seconds(3));
        menu(0,playlist);
        break;
    case 102:
        playlist.sortSongs(Playlist::Artist,Playlist::Ascending);
        cout << endl << playlistName << endl << endl;
        playlist.displaySongs();
        cout << endl << endl;
        sleep_for(seconds(3));
        menu(0,playlist);
        break;
    }
}

int choiceValidation(int lowerLimit, int upperLimit){
    int choice;
    choice = ReadType<int>("");

    while(choice < lowerLimit || choice > upperLimit){
        cout << "\nIngresá un número válido para la opción que seleccionaste: ";
        choice = ReadType<int>("");;
    }

    return choice;
}