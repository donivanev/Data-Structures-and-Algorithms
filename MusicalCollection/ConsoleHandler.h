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
	void save();

public:
	void processCommand(std::string choice, std::string user, std::string pass);
};