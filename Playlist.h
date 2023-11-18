/* Spotify Playlist Sorter */

#ifndef PLAYLIST
#define PLAYLIST

#include "Song.h"
#include <deque>
#include <string>

using namespace std;

/*
* Clase "Playlist"
* Permite guardar las canciones en un deque nombrado "Playlist" y tiene los
* métodos para ordenar las canciones, leer los archivos que contienen la 
* información de las playlists y sobreescribir la información de esos
* archivos cuando se requiera.
*/
class Playlist{
    private:
        deque<Song*> playlist;
        static string lowercase(string);
        static bool titleComparisonAscending(Song*, Song*);
        static bool titleComparisonDescending(Song*, Song*);
        static bool artistComparisonAscending(Song*, Song*);
        static bool artistComparisonDescending(Song*, Song*);
        static bool albumComparisonAscending(Song*, Song*);
        static bool albumComparisonDescending(Song*, Song*);
        static bool durationComparisonAscending(Song*, Song*);
        static bool durationComparisonDescending(Song*, Song*);
        static bool popularityComparisonAscending(Song*, Song*);
        static bool popularityComparisonDescending(Song*, Song*);

    public:
        Playlist();
        enum Options{
            Title = 1,
            Artist = 2,
            Album = 3,
            Duration = 4,
            Popularity = 5
        };
        enum OrderType{
            Ascending = 1,
            Descending = 2,
        };
        void enqueueTrackData(string);
        void sortSongs(Options, OrderType);
        void displaySongs();
        void storeTrackData(string);
};


#endif