#include "Playlist.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

Playlist::Playlist(){}

string trim(const string& str) {
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first) {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

vector<string> parseLine(const string& line) {
    vector<string> tokens;
    string currentToken;
    bool insideQuotes = false;

    tokens.reserve(5);

    for (size_t i = 0; i < line.length(); ++i) {
        char ch = line[i];
        if (ch == '"') {
            if(insideQuotes && i + 1 < line.length() && line[i + 1] != ','){
                currentToken += ch;
            } else{
                insideQuotes = !insideQuotes;
            }
        } else if (ch == ',' && !insideQuotes) {
            currentToken = trim(currentToken);
            tokens.push_back(currentToken);
            currentToken.clear();
        } else {
            currentToken += ch;
        }
    }
    if (!currentToken.empty()) {
        currentToken = trim(currentToken);
        tokens.push_back(currentToken);
    }

    return tokens;
}

void Playlist::enqueueTrackData(string file){
    ifstream ReadFile(file);
    string line;

    if (!ReadFile.is_open()) {
        cout << "The file didn't open successfully\n";
        return;
    }

    while (getline(ReadFile, line)) {
        auto tokens = parseLine(line);
        if (tokens.size() < 5) {
            cerr << "Invalid line format: " << line << endl;
            continue; // Skip this line
        }

        string track = tokens[0];
        string artist = tokens[1];
        string album = tokens[2];
        int duration = stoi(tokens[3]);
        int popularity = stoi(tokens[4]);

        playlist.push_back(new Song(track, artist, album, duration, popularity));
    }

    ReadFile.close();
}

string Playlist::lowercase(string word){
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    return word;
}

// The comparison functions tell the sort when the first element goes before
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

bool Playlist::albumComparisonAscending(Song* element1, Song* element2){
    string album1 = lowercase(element1->getAlbum());
    string album2 = lowercase(element2->getAlbum());
    if(album1.compare(album2) < 0){
        return 1;
    } else{
        return 0;
    }
}

bool Playlist::albumComparisonDescending(Song* element1, Song* element2){
    string album1 = lowercase(element1->getAlbum());
    string album2 = lowercase(element2->getAlbum());
    if(album1.compare(album2) > 0){
        return 1;
    } else{
        return 0;
    }
}

bool Playlist::durationComparisonAscending(Song* element1, Song* element2){
    int duration1 = element1->getDuration();
    int duration2 = element2->getDuration();
    if(duration1 < duration2){
        return 1;
    } else{
        return 0;
    }
}

bool Playlist::durationComparisonDescending(Song* element1, Song* element2){
    int duration1 = element1->getDuration();
    int duration2 = element2->getDuration();
    if(duration1 > duration2){
        return 1;
    } else{
        return 0;
    }
}

bool Playlist::popularityComparisonAscending(Song* element1, Song* element2){
    int popularity1 = element1->getPopularity();
    int popularity2 = element2->getPopularity();
    if(popularity1 < popularity2){
        return 1;
    } else{
        return 0;
    }
}

bool Playlist::popularityComparisonDescending(Song* element1, Song* element2){
    int popularity1 = element1->getPopularity();
    int popularity2 = element2->getPopularity();
    if(popularity1 > popularity2){
        return 1;
    } else{
        return 0;
    }
}

void Playlist::sortSongs(Options optionChosen, OrderType orderChosen){
    if(optionChosen == Options::Title){
        if(orderChosen == OrderType::Ascending){
            sort(playlist.begin(), playlist.end(),titleComparisonAscending);
        } else if(orderChosen == OrderType::Descending){
            sort(playlist.begin(), playlist.end(),titleComparisonDescending);
        }
    } else if(optionChosen == Options::Artist){
        if(orderChosen == OrderType::Ascending){
            sort(playlist.begin(), playlist.end(),artistComparisonAscending);
        } else if(orderChosen == OrderType::Descending){
            sort(playlist.begin(), playlist.end(),artistComparisonDescending);
        }
    } else if(optionChosen == Options::Album){
        if(orderChosen == OrderType::Ascending){
            sort(playlist.begin(), playlist.end(),artistComparisonAscending);
        } else if(orderChosen == OrderType::Descending){
            sort(playlist.begin(), playlist.end(),artistComparisonDescending);
        }
    } else if(optionChosen == Options::Duration){
        if(orderChosen == OrderType::Ascending){
            sort(playlist.begin(), playlist.end(),artistComparisonAscending);
        } else if(orderChosen == OrderType::Descending){
            sort(playlist.begin(), playlist.end(),artistComparisonDescending);
        }
    } else if(optionChosen == Options::Popularity){
        if(orderChosen == OrderType::Ascending){
            sort(playlist.begin(), playlist.end(),artistComparisonAscending);
        } else if(orderChosen == OrderType::Descending){
            sort(playlist.begin(), playlist.end(),artistComparisonDescending);
        }
    }
}

void Playlist::displaySongs(){
    for(const auto &element : playlist){
        cout << element->getTitle() << " - Artist/s: " << element->getArtist() << " - Album: " << element->getAlbum() << endl;
    }
}

void Playlist::storeTrackData(string originalFile){
    string tempFile = originalFile + ".tmp";
    ofstream playlistFile(tempFile);

    if (!playlistFile.is_open()) {
        cout << "The file didn't open successfully\n";
        return;
    }

    for (const auto &element : playlist) {
        playlistFile << "\"" << element->getTitle() << "\", "
                     << "\"" << element->getArtist() << "\", "
                     << "\"" << element->getAlbum() << "\", "
                     << "\"" << element->getDuration() << "\", "
                     << "\"" << element->getPopularity() << "\n";
    }

    playlistFile.close();

    if (!playlistFile.good()) {
        remove(tempFile.c_str());
    }

    if (remove(originalFile.c_str()) != 0) {
        remove(tempFile.c_str());
    }

    rename(tempFile.c_str(), originalFile.c_str());

    playlist.clear();
}