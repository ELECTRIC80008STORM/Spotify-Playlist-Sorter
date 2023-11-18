/* Spotify Playlist Sorter */

#include "Playlist.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/**
 * Constructor por default.
 *
 * @param
 * @return Objeto "Playlist".
 */
Playlist::Playlist(){}

/**
 * Permite eliminar los espacios en blanco antes y después de los atributos
 * que se guardaran.
 * @param const string& str: la string que se recortara.
 * @return string: la string modificada.
*/
string trim(const string& str) {
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first) {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

/**
 * Analiza una línea de tipo CSV y la divide en tokens individuales, considerando
 * las comas como delimitadores. Esta función permite mantener cualquier coma o
 * comilla que pertenezcan a la string almacenada.
 *
 * @param const string& line: La línea de texto que será analizada.
 * @return vector<string>: Un vector de los tokens extraídos.
 */
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

/**
 * Lee el archivo con las canciones de la playlist y los añade al deque "playlist".
 * Procesa cada línea del archivo, esperando encontrar datos del título, artista, álbum, duración y popularidad.
 * Omite las líneas que no sigan este formato y añade las pistas válidas a la lista de reproducción.
 *
 *
 * @param string file: El nombre del archivo que contiene los datos de las canciones.
 * @return
 */
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

/**
 * Convierte y retorna una cadena de texto a minúsculas.
 *
 * @param string word: La cadena de texto a convertir.
 * @return string: La cadena que se convirtió a minúsculas.
 */
string Playlist::lowercase(string word){
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    return word;
}

/**
 * Compara dos canciones de manera ascendente por su título.
 * 
 * @param Song* element1: Primer elemento de la comparación.
 * @param Song* element2: Segundo elemento de la comparación.
 * @return bool: Retorna 'true' si el título del primer elemento es menor alfabéticamente que el del segundo,
 * de lo contrario retorna 'false'.
 */
bool Playlist::titleComparisonAscending(Song* element1, Song* element2){    
    string title1 = lowercase(element1->getTitle());
    string title2 = lowercase(element2->getTitle());
    if(title1.compare(title2) < 0){
        return 1;
    } else{
        return 0;
    }
}

/**
 * Compara dos canciones de manera descendente por su título.
 * 
 * @param Song* element1: Primer elemento de la comparación.
 * @param Song* element2: Segundo elemento de la comparación.
 * @return bool: Retorna 'true' si el título del primer elemento es mayor alfabéticamente que el del segundo,
 * de lo contrario retorna 'false'.
 */
bool Playlist::titleComparisonDescending(Song* element1, Song* element2){    
    string title1 = lowercase(element1->getTitle());
    string title2 = lowercase(element2->getTitle());
    if(title1.compare(title2) > 0){
        return 1;
    } else{
        return 0;
    }
}

/**
 * Compara dos canciones de manera ascendente por el nombre del artista.
 * 
 * @param Song* element1: Primer elemento de la comparación.
 * @param Song* element2: Segundo elemento de la comparación.
 * @return bool: Retorna 'true' si el nombre del artista del primer elemento es menor alfabéticamente que el del segundo,
 * de lo contrario retorna 'false'.
 */
bool Playlist::artistComparisonAscending(Song* element1, Song* element2){
    string artist1 = lowercase(element1->getArtist());
    string artist2 = lowercase(element2->getArtist());
    if(artist1.compare(artist2) < 0){
        return 1;
    } else{
        return 0;
    }
}

/**
 * Compara dos canciones de manera descendente por el nombre del artista.
 * 
 * @param Song* element1: Primer elemento de la comparación.
 * @param Song* element2: Segundo elemento de la comparación.
 * @return bool: Retorna 'true' si el nombre del artista del primer elemento es mayor alfabéticamente que el del segundo,
 * de lo contrario retorna 'false'.
 */
bool Playlist::artistComparisonDescending(Song* element1, Song* element2){
    string artist1 = lowercase(element1->getArtist());
    string artist2 = lowercase(element2->getArtist());
    if(artist1.compare(artist2) > 0){
        return 1;
    } else{
        return 0;
    }
}

/**
 * Compara dos canciones de manera ascendente por el nombre del álbum.
 * 
 * @param Song* element1: Primer elemento de la comparación.
 * @param Song* element2: Segundo elemento de la comparación.
 * @return bool: Retorna 'true' si el nombre del álbum del primer elemento es menor alfabéticamente que el del segundo,
 * de lo contrario retorna 'false'.
 */
bool Playlist::albumComparisonAscending(Song* element1, Song* element2){
    string album1 = lowercase(element1->getAlbum());
    string album2 = lowercase(element2->getAlbum());
    if(album1.compare(album2) < 0){
        return 1;
    } else{
        return 0;
    }
}

/**
 * Compara dos canciones de manera descendente por el nombre del álbum.
 * 
 * @param Song* element1: Primer elemento de la comparación.
 * @param Song* element2: Segundo elemento de la comparación.
 * @return bool: Retorna 'true' si el nombre del álbum del primer elemento es mayor alfabéticamente que el del segundo,
 * de lo contrario retorna 'false'.
 */
bool Playlist::albumComparisonDescending(Song* element1, Song* element2){
    string album1 = lowercase(element1->getAlbum());
    string album2 = lowercase(element2->getAlbum());
    if(album1.compare(album2) > 0){
        return 1;
    } else{
        return 0;
    }
}

/**
 * Compara dos canciones de manera ascendente por su duración.
 * 
 * @param Song* element1: Primer elemento de la comparación.
 * @param Song* element2: Segundo elemento de la comparación.
 * @return bool: Retorna 'true' si la duración del primer elemento es menor que la del segundo,
 * de lo contrario retorna 'false'.
 */
bool Playlist::durationComparisonAscending(Song* element1, Song* element2){
    int duration1 = element1->getDuration();
    int duration2 = element2->getDuration();
    if(duration1 < duration2){
        return 1;
    } else{
        return 0;
    }
}

/**
 * Compara dos canciones de manera descendente por su duración.
 * 
 * @param Song* element1: Primer elemento de la comparación.
 * @param Song* element2: Segundo elemento de la comparación.
 * @return bool: Retorna 'true' si la duración del primer elemento es mayor que la del segundo,
 * de lo contrario retorna 'false'.
 */
bool Playlist::durationComparisonDescending(Song* element1, Song* element2){
    int duration1 = element1->getDuration();
    int duration2 = element2->getDuration();
    if(duration1 > duration2){
        return 1;
    } else{
        return 0;
    }
}

/**
 * Compara dos canciones de manera ascendente por su popularidad.
 * 
 * @param Song* element1: Primer elemento de la comparación.
 * @param Song* element2: Segundo elemento de la comparación.
 * @return bool: Retorna 'true' si la popularidad del primer elemento es menor que la del segundo,
 * de lo contrario retorna 'false'.
 */
bool Playlist::popularityComparisonAscending(Song* element1, Song* element2){
    int popularity1 = element1->getPopularity();
    int popularity2 = element2->getPopularity();
    if(popularity1 < popularity2){
        return 1;
    } else{
        return 0;
    }
}

/**
 * Compara dos canciones de manera descendente por su popularidad.
 * 
 * @param Song* element1: Primer elemento de la comparación.
 * @param Song* element2: Segundo elemento de la comparación.
 * @return bool: Retorna 'true' si la popularidad del primer elemento es mayor que la del segundo,
 * de lo contrario retorna 'false'.
 */
bool Playlist::popularityComparisonDescending(Song* element1, Song* element2){
    int popularity1 = element1->getPopularity();
    int popularity2 = element2->getPopularity();
    if(popularity1 > popularity2){
        return 1;
    } else{
        return 0;
    }
}

/**
 * Ordena las canciones en la lista de reproducción según el criterio y el orden especificados.
 * El criterio de ordenación puede ser por título, artista, álbum, duración o popularidad.
 * El orden puede ser ascendente o descendente. La función selecciona el método de comparación
 * correspondiente basado en las opciones proporcionadas.
 *
 * @param Options optionChosen: Criterio de ordenación seleccionado.
 * @param OrderType orderChosen: Tipo de orden seleccionado.
 * @return
 */
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

/**
 * Muestra las canciones de la lista de reproducción en la consola.
 * Cada canción se muestra con su título, artistas y álbum.
 * @param
 * @return
 */
void Playlist::displaySongs(){
    for(const auto &element : playlist){
        cout << element->getTitle() << " - Artist/s: " << element->getArtist() << " - Album: " << element->getAlbum() << endl;
    }
}

/**
 * Guarda los datos de las canciones de la lista de reproducción en el archivo de la playlist.
 * Escribe los datos de cada pista en un archivo temporal y luego renombra
 * este archivo como el archivo original. Si ocurre un error durante el proceso,
 * el archivo temporal se elimina. Al final del proceso, la lista de reproducción
 * se limpia.
 *
 * @param string originalFile: Nombre del archivo original donde se guardarán los datos.
 */
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