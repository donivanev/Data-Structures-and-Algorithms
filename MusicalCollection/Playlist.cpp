#include "Playlist.h"

bool Playlist::operator < (const Playlist& other) const
{
	return number < other.number;
}

void Playlist::addSongToPlaylist(Song song)
{
	listOfSongs.push_back(song);
}
