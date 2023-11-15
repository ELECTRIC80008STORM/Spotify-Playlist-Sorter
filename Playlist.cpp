#include "Playlist.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

Playlist::Playlist(){}

// Analyze for further comprehension
vector<string> parseLine(const string& line) {
    vector<string> tokens;
    string currentToken;
    bool insideQuotes = false;

    for (char ch : line) {
        if (ch == '"') {
            insideQuotes = !insideQuotes;
        } else if (ch == ',' && !insideQuotes) {
            tokens.push_back(currentToken);
            currentToken.clear();
        } else {
            currentToken += ch;
        }
    }
    if (!currentToken.empty()) {
        tokens.push_back(currentToken);
    }

    return tokens;
}

string trimQuotes(const string& str) {
    size_t firstQuote = str.find('"');
    size_t lastQuote = str.rfind('"');
    if (firstQuote != string::npos && lastQuote != string::npos && firstQuote != lastQuote) {
        return str.substr(firstQuote + 1, lastQuote - firstQuote - 1);
    }
    return str;
}

// Analyze for improvements
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

        string track = trimQuotes(tokens[0]);
        string artist = trimQuotes(tokens[1]);
        string album = trimQuotes(tokens[2]);
        int duration = stoi(trimQuotes(tokens[3]));
        int popularity = stoi(trimQuotes(tokens[4]));

        playlist.push_back(new Song(track, artist, album, duration, popularity));
    }

    ReadFile.close();
}

string Playlist::lowercase(string word){
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    return word;
}

bool Playlist::titleComparisonAscending(Song* element1, Song* element2){    
    string title1 = lowercase(element1->getTitle());
    string title2 = lowercase(element2->getTitle());
    if(title1.compare(title2) > 0){
        return 1;
    } else{
        return 0;
    }
}

bool Playlist::titleComparisonDescending(Song* element1, Song* element2){    
    string title1 = lowercase(element1->getTitle());
    string title2 = lowercase(element2->getTitle());
    if(title1.compare(title2) < 0){
        return 1;
    } else{
        return 0;
    }
}

bool Playlist::artistComparisonAscending(Song* element1, Song* element2){
    string artist1 = lowercase(element1->getArtist());
    string artist2 = lowercase(element2->getArtist());
    if(artist1.compare(artist2) > 0){
        return 1;
    } else{
        return 0;
    }
}

bool Playlist::artistComparisonDescending(Song* element1, Song* element2){
    string artist1 = lowercase(element1->getArtist());
    string artist2 = lowercase(element2->getArtist());
    if(artist1.compare(artist2) < 0){
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
    }
}

void Playlist::displaySongs(){
    for(const auto &element : playlist){ // TODO: Improve readibility
        cout << element->getTitle() << " - Artist/s: " << element->getArtist() << " - Album: " << element->getAlbum() << endl;
    }
}

void Playlist::storeTrackData(){ // TODO: Declare the storeTrackData method

}