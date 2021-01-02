#pragma once
#include <iostream>
#include <list>
#include "Song.h"

class Playlist
{

private:
	int number;
	std::list<Song> listOfSongs;

public:

	bool operator < (const Playlist& other) const;
	void addSongToPlaylist(Song song);
};

