#include "playlist.h"

// creates the null song
Song::Song():
song(""),
artist("") {
}

// creates a song object and sets its private member variables
Song::Song(std::string song_name, std::string sartist): 
    song(""), artist("") {
    // makes sure the song you are trying to add isnt baby by jb or a song titled my heart will go on
    if (!((song_name == "Baby" && sartist == "Justin Bieber") || (song_name == "My Heart Will Go On"))) {
        song = song_name;
        artist = sartist;
    }
}
// overloads the == operator to compare a song to another song
bool Song::operator==(const Song &other) {
    return (this->song == other.song) && (this->artist == other.artist);
}
// shows the song in the format song;artist
void Song::show() {
    std::cout << this->song << ";" << this->artist << std::endl;
}

// constructor that creates a default playlist object if no size given
Playlist::Playlist():
playlist_size{0},
// sets the empty song to null song
songs(new Song[1]) {
    songs[0] = nullSong;
}
// creates the array used for the playlist and stores the size of the playlist
Playlist::Playlist(int n) :
    playlist_size(n),
    songs(new Song[n]) {
    // stores each element of the new array with a nullsong
    for (int k{0}; k < playlist_size; k++) {
        songs[k] = nullSong;
    }
    std::cout << "success" << std::endl;
}
// copy function used if default playlist is made and a size is added afterwards
Playlist::Playlist(const Playlist &other) :
    // copies all the member variables over
    playlist_size(other.playlist_size),
    songs_in(other.songs_in),
    nullSong(other.nullSong),
    songs(new Song[other.playlist_size]) {
    // copy  elements from other playlist to new playlist
    std::copy(other.songs, other.songs + other.playlist_size, songs);
}
// changes the = operator to set a playlist to another one
Playlist& Playlist::operator=(const Playlist& other) {
    // copies size
    this->playlist_size = other.playlist_size;
    //allocate a new array to copy songs into
    Song* new_songs = new Song[playlist_size];
    // copy songs from other playlist
    for (int i = 0; i < playlist_size; ++i) {
        new_songs[i] = other.songs[i];
    }
    // delete old songs array
    delete[] this->songs;
    // change pointer to new array
    this->songs = new_songs;
    // copy the number of songs
    this->songs_in = other.songs_in;
    // return modified playlist
    return *this;
}
// adds song to the playlist if conditions are met
Playlist& Playlist::addSong(Song& B) {
    // if adding another song to the playlist exceeds the allocated size, it faults
    if (songs_in == playlist_size) {
        std::cout << "can not insert ";
        B.show();
        // returns unchanged playlist
        return *this;
    }

    // runs through the playlist to make sure the song isn't already in it
    for (int k{0}; k < songs_in; k++) {
        if (B == this->songs[k]) {
            std::cout << "can not insert ";
            B.show();
            // ff the song is already in it, returns the unchanged playlist
            return *this;
        }
    }

    // adds the song to the playlist and increments number of songs in playlist
    this->songs[songs_in] = B;
    ++songs_in;
    std::cout << "success" << std::endl;

    // returns the modified playlist
    return *this;
}
// function that deletes song at position n if possible and returns the new playlist
Playlist& Playlist::deletesong(int n) {
    if (n >= this->songs_in) {
        std::cout << "can not erase " << n << std::endl;
        // returns unchanged playlist
        return *this;
    } else {
        // set target song to nullSong
        this->songs[n] = nullSong;

        // shift elements to the left
        for (int k = n; k < songs_in - 1; ++k) {
            this->songs[k] = this->songs[k + 1];
        }

        // set the last element to nullSong and decrement the count
        this->songs[songs_in - 1] = nullSong;
        --songs_in;

        std::cout << "success" << std::endl;
    }
    // returns the modified playlist
    return *this;
}

// function that plays the song at position n if possible
void Playlist::playsong(int n) {
    // if n is smaller than the number of songs currently in the playlist
    if (n < this->songs_in) {
        std::cout << "played " << n << " ";
        this->songs[n].show();
    // if n is larger than or equal to the number of songs in the playlist
    } else {
        std::cout << "can not play " << n << std::endl;
    }
}

Playlist::~Playlist() {
    delete[] this->songs;
    this->songs = nullptr;
}