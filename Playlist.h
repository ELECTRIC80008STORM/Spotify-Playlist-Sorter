#ifndef PLAYLIST
#define PLAYLIST

#include "Song.h"
#include <vector>
#include <string>

using namespace std;

class Playlist{
    private:
        vector<Song*>& playlist;
        static string lowercase(string);
        static bool titleComparisonAscending(Song*, Song*);
        static bool titleComparisonDescending(Song*, Song*);
        static bool artistComparisonAscending(Song*, Song*);
        static bool artistComparisonDescending(Song*, Song*);

    public:
        Playlist(vector<Song*>&);
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