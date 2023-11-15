#ifndef SONG
#define SONG

#include <string>

using namespace std;

class Song{
    private:
        string title;
        string artist;
        string album;
        int duration;
        int popularity;

    public:
        Song(string title, string artist, string album, int duration, int popularity)
        : title(title), artist(artist), album(album), duration(duration), popularity(popularity) {}
        string getTitle(){ return title; }
        string getArtist(){ return artist; }
        string getAlbum(){ return album; }
        int getDuration(){ return duration; }
        int getPopularity(){ return popularity; }
};

#endif