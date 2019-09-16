// music_manager.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Create a song class
class Song {
private:
	string name;
public:
	Song(string n);
	string song_name();
};
//Create a consrutor for song that takes in the name of the song
Song::Song(string n) {
	name = n;
}
//Returns the name of the song
string Song::song_name() {
	return name;
}
//Create a class called album
class Album {
private:
	string name;
	string year;
	vector<Song> s;
	vector<Song>::iterator it = s.begin();
public:
	Album(std::string n, std::string y);
	string album_name();
	string album_year();
};
//The constructor takes in the name and the year the album was made
Album::Album(string n, string y) {
	name = n;
	year = y;
}

string Album::album_name() {
	return name;
}

string Album::album_year() {
	return year;
}
//Create a playlist class 
class Playlist {
private:
	string name;
	vector<Song> songs;
	vector<Song>::iterator it = songs.begin();
public:
	Playlist(string n);
	string list_name();
	void getsongs();
	void addSong(Song s);
};
//constructor for playlist takes in the name 
Playlist::Playlist(string n) {
	name = n;
}
string Playlist::list_name() {
	return name;
}
//Returns all of the songs that have been added to the playlist
void Playlist::getsongs() {
	cout << "Playlist Name: " << list_name() << "\n";
	cout << "Songs: " << "\n";
	while(it != songs.end()) {
		Song temp = *it;
		std::string temp_string = temp.song_name();
		cout << temp_string << "\n";
		it++;
	}
}
//Add a song to the playist 
void Playlist::addSong(Song s) {
	songs.push_back(s);

}
//Create a class named Artist
class Artist {
private:
	string name;
	vector<Album> al;
public:
	Artist(string n);
	string artist_name();
	void addAlbum(Album album);
	void showAlbums();
};
//Constructor for artist class takes in a name
Artist::Artist(string n) {
	name = n;
}

string Artist::artist_name() {
	return name;
}
//Add an album to the artists catalogue
void Artist::addAlbum(Album album) {
	al.push_back(album);

}
//Display all of the albums added to the artist
void Artist::showAlbums() {
cout << "Albums for " << artist_name() << "\n";
for(int i = 0; i < al.size(); i++){
	cout << al[i].album_name() << " - " << al[i].album_year() << "\n";
	}
}
//Create the artists vector to hold the names of all the artists in the collection
vector<Artist> artists;
vector<Album> albums;

void stuff() {
	bool condition = false;
	string user_selection;
	while (condition == false) {
		cout << "Enter the name of a new artist: ";
		getline(cin, user_selection);
		Artist a(user_selection);
		artists.push_back(a);
		vector<Artist>::iterator itr = artists.begin();
		cout << "Artists: " << "\n";
		while (itr != artists.end()) {
			Artist temp_artist = *itr;
			string name_of = temp_artist.artist_name();
			cout << name_of << "\n";
			itr++;
		}
		string y_n;
		cout << "Would you like to add a album to this artist (y/n)?: ";
		getline(cin, y_n);
		if (y_n.compare("y") == 0) {
			cout << "Enter the name of the Album: ";
			string al_name;
			getline(cin, al_name);
			cout << "What year was the album released?: ";
			string al_year;
			getline(cin, al_year);
			Album user_album(al_name, al_year);
			a.addAlbum(user_album);
			a.showAlbums();
		}
		else if (y_n.compare("n") == 0) {
			string choice;
			cout << "Would you like to add another artist (y/n)? : ";
			getline(cin, choice);
			if (choice.compare("y") == 0) {
				stuff();
			}
			else if (choice.compare("n") == 0) {
				exit(0);
			}
		}
	}
}

void stuff_2() {
	bool condition = false;
	while (condition == false) {
		cout << "Enter the name of the album: ";
		string album_name;
		getline(cin, album_name);
		cout << "What year was the album released?: ";
		string album_year;
		getline(cin, album_year);
		Album input_album(album_name, album_year);


	}

}

void start() {
	cout << "Welcome to the music manager system!" << "\n";
	cout << "Would you like to add an artist or album (y/n)?: ";
	stuff();

}






int main()
{
	start();
	
	system("pause");
	return 0;
}

