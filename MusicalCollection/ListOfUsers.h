#pragma once
#include <iostream>
#include <fstream>
#include <set>
#include "User.h"
#include "Song.h"
 
//A class that holds the information about all users

class ListOfUsers
{

private:
	std::vector<User> listOfUsers;
	std::fstream f_inout;
	std::set<Song> listOfSongs;

public:
	void toDate(std::string& str, int& y, int& m, int& d);
	void strToVector(std::string genres, std::vector<std::string>& genresCollection);
	void removeSpace(std::string& str);
	bool userExists(std::string user, std::string pass);
	void saveSong(std::set<Song> listOfSongs);
	void addUser(std::string _username, std::string _password, std::string _fullName, Date _birthdate,
				 std::vector<std::string> _favouriteGenres);
	void printUsers();
	void returnSongsToCollection();
	void changeProfileData(std::string user);
	void addSong();
	friend std::ostream& operator << (std::ostream& output, const ListOfUsers& listOfUsers);
};