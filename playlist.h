// creating playlist and song classes
#include <iostream>
#include <string>

class Song {

    public: 
    // creates a null song if no song name or artist is given
    Song();
    // creates song if name and artist is given
    Song(std::string song_name, std::string sartist);
    // overload == operator for comparing a song to another song
    bool operator==(const Song &other);
    // shows title;artist of song
    void show();

    private:
    // stores the string of the song name
    std::string song;
    // stores the string of the artists name
    std::string artist;
};

class Playlist {

    public:
    // creates a playlist type with array size 0
    Playlist();
    // changes the playlist array to have size n
    Playlist(int n);
    // copy function
    Playlist(const Playlist& other);

    Playlist& operator=(const Playlist& other);
    // adds a song to the playlist if conditions are met
    Playlist& addSong(Song& B);
    // deletes song in position n from playlist if conditions are met
    Playlist& deletesong(int n);
    // plays song in position n of playlist if conditions are met
    void playsong(int n);

    ~Playlist();

    private:
    // stores the size of the playlist created
    int playlist_size;
    // keeps track of how many songs have been added to the playlist
    int songs_in{0};
    // creates a nullSong object to fill the unused spaces of the array
    Song nullSong;
    // pointed to the array of songs used to store the songs of the playlist
    Song *songs;
};