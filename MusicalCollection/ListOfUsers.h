#pragma once
#include <iostream>
#include <fstream>
#include "User.h"

//A class that holds the information about all users

class ListOfUsers
{

private:
	std::vector<User> listOfUsers;
	std::fstream f_inout;

public:
	void toDate(std::string& str, int& y, int& m, int& d);
	bool userExists(std::string user, std::string pass);
	void addUser(std::string _username, std::string _password, std::string _fullName, Date _birthdate,
				 std::vector<std::string> _favouriteGenres);
	void printUsers();
	void changeProfileData(std::string user);
	friend std::ostream& operator << (std::ostream& output, const ListOfUsers& listOfUsers);
};