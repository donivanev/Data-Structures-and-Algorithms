#pragma once
#include <iostream>
#include <fstream>
#include "ListOfUsers.h"

//The main class in which the important functions are implemented 

class ConsoleHandler
{
private:
	std::fstream f_inout;
	ListOfUsers listOfUsers;

	void toDate(std::string& str, int& y, int& m, int& d);
	void toDateFromFile(std::string& str, int& y, int& m, int& d);
	bool isValidDate(int y, int m, int d);
	void strToVector(std::string genres, std::vector<std::string>& genresCollection);
	void removeSpace(std::string& str);
	void save();
	void actionsAfterLogIn();
	bool isAlreadyRegisteredUser(std::string username);
	void loadDataToCollections();

public:
	void processCommand(std::string choice, std::string user, std::string pass, bool& flag);
};