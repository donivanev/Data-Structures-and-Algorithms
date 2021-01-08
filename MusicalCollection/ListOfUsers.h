#pragma once
#include <iostream>
#include <fstream>
#include <set>
#include <unordered_set>
#include <queue>
#include "User.h"
#include "Song.h"
#include "ExpressionTree.cpp"
 
//A class that holds the information about all users

class ListOfUsers
{

private:
	std::fstream f_inout;
	std::vector<User> listOfUsers;
	std::set<Song> listOfSongs;  
	ExpressionTree<std::string> t;

public:
	void toDate(std::string& str, int& y, int& m, int& d);
	void strToVector(std::string genres, std::vector<std::string>& genresCollection);
	int strToInt(std::string s);
	void reverseStr(std::string& str);
	void removeSpace(std::string& str);
	bool userExists(std::string user, std::string pass);
	void saveSong(std::set<Song> listOfSongs);
	void processExpression(std::string expression, std::vector<std::string>& arr);
	void addUser(std::string _username, std::string _password, std::string _fullName, Date _birthdate,
				 std::vector<std::string> _favouriteGenres, std::set<Playlist> _playlistsCollection);
	void printUsers();
	void returnSongsToCollection();
	void changeProfileData(std::string user);
	void addSong();
	void generatePlaylist(std::string user);
	void loadPlaylistByName(std::string user);
	void setRating(std::string user);
	friend std::ostream& operator << (std::ostream& output, const ListOfUsers& listOfUsers);
};