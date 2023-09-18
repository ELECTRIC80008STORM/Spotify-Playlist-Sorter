#ifndef SONG
#define SONG

#include <string>

using namespace std;

class Song{
    private:
        string title;
        string artist;

    public:
        Song(string title, string artist) : title(title), artist(artist){}
        string getTitle(){ return title; }
        string getArtist(){ return artist; }
};

#endif