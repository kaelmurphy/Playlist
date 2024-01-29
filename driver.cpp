// ECE 250 Lab 1, Section 202
// Kael Murphy, 21040352

#include <iostream>
#include <string>
#include "playlist.h"

int main() {
    // creates a new playlist object that will be added to and used
    Playlist newPlaylist;
    // program will keep running until this condition becomes false
    bool test = true;
    // while loop that will continuously read the line and fulfill the commands
    while (test) {
        // creates an instance of nullSong to be used later
        Song nullSong;
        // the getline string will be stored here
        std::string read;
        // get's the line from the test file
        std::getline(std::cin, read);
        // stores where the space after the command is located
        size_t pos1 = read.find(" ");
        // only used when parsing the song and artist names when adding a song to playlist
        size_t pos2 = read.find(";");
        // stores the command that is to be run
        std::string cmd = read.substr(0, pos1);
        // creating playlist of size n
        if (cmd == "m") {
            // converts the string length to an int
            int length = std::stoi(read.substr(pos1 + 1));
            // create a temporary playlist
            Playlist temp(length);
            // use the copy function to assign temp to newPlaylist
            newPlaylist = temp;
        // terminates the program
        } else if (cmd == "done") {
            return 0;
        // adds song to playlist if conditions are met
        } else if (cmd == "i") {
            // splices the read string into a song string
            std::string song = read.substr(pos1 + 1, pos2 - pos1 - 1);
            // splices the read string into an artist string
            std::string artist = read.substr(pos2 + 1);
            // creates a new song by song and artist
            Song newSong(song, artist);
            // if song is baby by jb or anything titled my heart will go on the song object will be nullsong
            if (newSong == nullSong) {
                std::cout << "can not insert " << song << ";" << artist << std::endl;
            } else {
                // newSong gets added to the playlist
                newPlaylist.addSong(newSong);
            }  
        // deletes song at position n from the playlist
        } else if (cmd == "e") {
            // turns the string number into an int that can be passed into the delete function
            int del = std::stoi(read.substr(pos1 + 1));
            newPlaylist.deletesong(del);
        } else if (cmd == "p") {
            // turns the string number into an int that can be passed into the playsong function
            int play = std::stoi(read.substr(pos1 + 1));
            newPlaylist.playsong(play);
        }
    }
}