#pragma once
#include <iostream>
#include <list>
#include "Song.h"

class Playlist
{

private:
	std::string name;
	int number;
	std::list<Song> listOfSongs;

public:
	std::string getName();
	void setName(std::string _name);
	int getNumber();
	void setNumber(int _number);
	bool operator < (const Playlist& other) const;
	void addSongToPlaylist(Song song);
};

