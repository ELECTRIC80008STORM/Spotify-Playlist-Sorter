#ifndef PLAYLIST
#define PLAYLIST

#include "Song.h"
#include <deque>
#include <string>

using namespace std;

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