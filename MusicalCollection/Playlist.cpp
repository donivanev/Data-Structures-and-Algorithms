#include "Playlist.h"

std::string Playlist::getName()
{
	return this->name;
}

void Playlist::setName(std::string _name)
{
	name = _name;
}

int Playlist::getNumber()
{
	return this->number;
}

void Playlist::setNumber(int _number)
{
	number = _number;
}

bool Playlist::operator < (const Playlist& other) const
{
	return number < other.number;
}

void Playlist::addSongToPlaylist(Song song)
{
	listOfSongs.push_back(song);
}
