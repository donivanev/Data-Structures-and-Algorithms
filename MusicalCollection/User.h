#pragma once
#include <string>
#include <vector>
#include <set>
#include <map>
#include "Date.h"
#include "Playlist.h"

//A class that holds the information about the user

class User
{
private:
	std::string username;
	std::string password;
	std::string fullName;
	Date birthdate;
	std::vector<std::string> favouriteGenres;
	std::set<Playlist> playlistsCollection;
	std::map<std::string, bool> hasAlreadyVoted;

public:
	User(std::string _username, std::string _password, std::string _fullName, Date _birthdate, 
		 std::vector<std::string> _favouriteGenres, std::set<Playlist> _playlistsCollections);

	std::string getUsername();
	void setUsername(std::string _username);
	std::string getPassword();
	void setPassword(std::string _password);
	std::string getFullName();
	void setFullName(std::string _fullName);
	Date getBirthdate();
	void setBirthdate(Date _birthdate);
	void removeSpace(std::string& str);
	void removeSpaces(std::string& str);
	std::vector<std::string> getGenres();
	void addGenre(std::string genre);
	void removeGenre(std::string genre);
	std::set<Playlist> getPlaylists();
	bool getHasAlreadyVoted(std::string songName);
	void setHasAlreadyVoted(std::string songName, bool _hasAlreadyVoted);

	bool isFromFavourites(std::string genre);
	void pushInPlaylist(Playlist playlist);
	void printUser();
	friend std::ostream& operator << (std::ostream& output, const User& user);
};
