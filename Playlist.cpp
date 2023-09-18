#include "Playlist.h"
#include <algorithm>
#include <iostream>

using namespace std;

Playlist::Playlist(vector<Song*>& songs) : playlist(songs){}

string Playlist::lowercase(string word){
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    return word;
}

bool Playlist::titleComparisonAscending(Song* element1, Song* element2){    
    string title1 = lowercase(element1->getTitle());
    string title2 = lowercase(element2->getTitle());
    if(title1.compare(title2) < 0){
        return 1;
    } else{
        return 0;
    }
}

bool Playlist::titleComparisonDescending(Song* element1, Song* element2){    
    string title1 = lowercase(element1->getTitle());
    string title2 = lowercase(element2->getTitle());
    if(title1.compare(title2) > 0){
        return 1;
    } else{
        return 0;
    }
}

bool Playlist::artistComparisonAscending(Song* element1, Song* element2){
    string artist1 = lowercase(element1->getArtist());
    string artist2 = lowercase(element2->getArtist());
    if(artist1.compare(artist2) < 0){
        return 1;
    } else{
        return 0;
    }
}

bool Playlist::artistComparisonDescending(Song* element1, Song* element2){
    string artist1 = lowercase(element1->getArtist());
    string artist2 = lowercase(element2->getArtist());
    if(artist1.compare(artist2) > 0){
        return 1;
    } else{
        return 0;
    }
}

void Playlist::sortSongs(int option, bool ascending){
    if(option == 1){
        if(ascending){
            sort(playlist.begin(), playlist.end(),titleComparisonAscending);
        } else{
            sort(playlist.begin(), playlist.end(),titleComparisonDescending);
        }
    } else if(option == 2){
        if(ascending){
            sort(playlist.begin(), playlist.end(),artistComparisonAscending);
        } else{
            sort(playlist.begin(), playlist.end(),artistComparisonDescending);
        }
    }
}

void Playlist::displaySongs(){
    for(const auto &element : playlist){
        cout << element->getTitle() << " - " << element->getArtist() << endl;
    }
}