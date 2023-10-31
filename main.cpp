#include "Playlist.cpp"
#include "Song.h"
#include "readtype.h"

#include <iostream>
#include <vector>
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
int choice;

int main(){
    // Playlist de Ejemplo
    vector<Song*> songs;
    songs.push_back(new Song("When I Was Your Man", "Bruno Mars"));
    songs.push_back(new Song("Seven (feat. Latto) (Explicit Ver.)", "Jung Kook"));
    songs.push_back(new Song("bad idea right?", "Olivia Rodrigo"));
    songs.push_back(new Song("Dance The Night - From Barbie The Album", "Dua Lipa"));
    songs.push_back(new Song("Used To Be Young", "Miley Cyrus"));
    songs.push_back(new Song("What Was I Made For? [From The Motion Picture \"Barbie\"]", "Billie Eilish"));
    songs.push_back(new Song("WHERE SHE GOES", "Bad Bunny"));
    songs.push_back(new Song("Daylight", "David Kushner"));
    songs.push_back(new Song("Flowers", "Miley Cyrus"));
    songs.push_back(new Song("Creepin' (with The Weeknd & 21 Savage)", "Metro Boomin"));
    songs.push_back(new Song("Columbia", "Quevedo"));

    Playlist playlist(songs);

    // Introducción al programa
    printf("\e[1;1H\e[2J");
    cout << "Spotify Playlist Sorter" << endl << endl;

    sleep_for(seconds(2));

    cout << "Bienvenido/a\n" "Preparate para poder organizar tus playlist como llevas"
    " tiempo queriendo!!!" << endl << endl;

    sleep_for(seconds(3));

    cout << "Por el momento la aplicación sigue en desarrollo, por lo que solo podrás"
    " ordenar" << endl << "una playlist de ejemplo, esperamos que"
    " para la próxima vez que ingreses ya puedas" << endl << 
    "disfrutar de la aplicación como te mereces.";

    cout << endl << endl;

    sleep_for(seconds(7));
    printf("\e[1;1H\e[2J");

    cout << "Playlist Ejemplo" << endl << endl;
    playlist.displaySongs();
    cout << endl;

    sleep_for(seconds(6));

    menu(0, playlist);

    return 0;
};

void menu(int option, Playlist playlist){
    switch (option){
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
        cout << endl << "Playlist Ejemplo" << endl << endl;
        playlist.displaySongs();
        cout << endl << endl;
        sleep_for(seconds(3));
        option1 = "Título ↑";
        menu(0,playlist);
        break;
    case 2:
        playlist.sortSongs(Playlist::Artist,Playlist::Descending);
        cout << endl << "Playlist Ejemplo" << endl << endl;
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
        cout << endl << "Playlist Ejemplo" << endl << endl;
        playlist.displaySongs();
        cout << endl << endl;
        sleep_for(seconds(3));
        menu(0,playlist);
        break;
    case 102:
        playlist.sortSongs(Playlist::Artist,Playlist::Ascending);
        cout << endl << "Playlist Ejemplo" << endl << endl;
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