#include "ConsoleHandler.h"

void message()
{
	std::cout << "Please type one of the following commands: " << std::endl;
	std::cout << "[Sign in] - For users who already have registration." << std::endl;
	std::cout << "[Sign up] - For users who don't have accounts." << std::endl;
}

//A function that converts a date in format "dd-mm-yyyy" to date in with integers in order to 
//eventually comparing dates
void ConsoleHandler::toDate(std::string& str, int& y, int& m, int& d)
{
	int place = 0;
	std::string token, delimeter = "-";
	std::vector<std::string> v;

	while ((place = str.find(delimeter)) != std::string::npos)
	{
		token = str.substr(0, place);
		v.push_back(token);
		str.erase(0, place + delimeter.length());
	}
	v.push_back(str);

	y = stoi(v.at(0));
	m = stoi(v.at(1));
	d = stoi(v.at(2));
}

//Save data in a file
void ConsoleHandler::save()
{
	f_inout.open("users.txt", std::ios::out);
	//f_inout.clear();
	f_inout << listOfUsers;
	f_inout.close();
}

//Message for the logged user
void actionsAfterLogIn()
{
	std::cout << "Choose one of the following: " << std::endl;
	std::cout << "1 - Change profile data" << std::endl;
	std::cout << "2 - Add song" << std::endl;
	std::cout << "3 - Generate playlist" << std::endl;
	std::cout << "4 - Save this playlist" << std::endl;
	std::cout << "5 - Load playlist" << std::endl;
	std::cout << "6 - Information about all the songs in this playlist" << std::endl;
	std::cout << "7 - Set rating" << std::endl;
}

//A function that processes all the commands from the console
void ConsoleHandler::processCommand(std::string choice, std::string user, std::string pass)
{
	if (choice == "Sign in")
	{
		if (listOfUsers.userExists(user, pass))
		{
			std::cout << "Successfully logged in." << std::endl;
			std::cout << std::endl;
			actionsAfterLogIn();
			listOfUsers.printUsers();

			int number, i = 0;

			do
			{
				if (i != 0)
				{
					std::cout << "Wrong number. Choose a number between 1 and 7." << std::endl;
				}
				std::cin >> number;
				i++;

			} while (!(number > 0 && number < 8));

			switch (number)
			{
				case 1: //listOfUsers.changeProfileData(user); break;
				case 2: /*addSong();*/ break;
				case 3: /*generatePlaylist();*/ break;

				default: break;
			}
		}
		else
		{
			std::cout << "No such user. Please sign up first.";
		}
	}
	else if (choice == "Sign up")
	{
		std::cout << "Please enter on a separate lines the following things: " <<
			"\nusername, password, fullname, birthdate and your favourite genres." << std::endl;

		std::string info;
		std::vector<std::string> arrOfData;

		while (info != "Submit")
		{
			arrOfData.push_back(info);
			std::getline(std::cin, info);
		}

		std::vector<std::string> favGenres;
		for (int i = 5; i < arrOfData.size(); i++)
		{
			favGenres.push_back(arrOfData[i]);
		}

		int y, m, d;
		toDate(arrOfData[4], y, m, d);
		Date date(y, m, d);

		listOfUsers.addUser(arrOfData[1], arrOfData[2], arrOfData[3], date, favGenres);
		listOfUsers.printUsers();
		save();
	}
}
