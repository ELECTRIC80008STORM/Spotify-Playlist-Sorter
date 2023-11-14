#ifndef PLAYLIST
#define PLAYLIST

#include "Song.h"
#include <deque>
#include <string>

using namespace std;

class Playlist{
    private:
        deque<Song*>& playlist;
        static string lowercase(string);
        static bool titleComparisonAscending(Song*, Song*);
        static bool titleComparisonDescending(Song*, Song*);
        static bool artistComparisonAscending(Song*, Song*);
        static bool artistComparisonDescending(Song*, Song*);

    public:
        Playlist(deque<Song*>&);
        // void addSongs(vector<Song*>&);
        enum Options{
            Title = 1,
            Artist = 2
        };
        enum OrderType{
            Descending = 1,
            Ascending = 2
        };
        void sortSongs(Options, OrderType);
        void displaySongs();
        
};


#endif