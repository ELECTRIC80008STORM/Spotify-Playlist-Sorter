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
        // TODO: Add sort functions for the rest of the attributes

    public:
        Playlist();
        enum Options{
            Title = 1,
            Artist = 2
        };
        enum OrderType{
            Descending = 1,
            Ascending = 2
        };
        void enqueueTrackData(string);
        void sortSongs(Options, OrderType);
        void displaySongs();
        void storeTrackData();
};


#endif