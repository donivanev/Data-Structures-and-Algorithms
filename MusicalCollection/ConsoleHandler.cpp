#include "ConsoleHandler.h"

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

void ConsoleHandler::toDateFromFile(std::string& str, int& y, int& m, int& d)
{
	int place = 0;
	std::string token, delimeter = " ";
	std::vector<std::string> v;

	while ((place = str.find(delimeter)) != std::string::npos)
	{
		token = str.substr(0, place);
		v.push_back(token);
		str.erase(0, place + delimeter.length());
	}
	v.push_back(str);

	d = stoi(v.at(0));
	m = stoi(v.at(1));
	y = stoi(v.at(2));
}

void ConsoleHandler::strToVector(std::string genres, std::vector<std::string>& genresCollection)
{
	int place = 0;
	std::string token, delimeter = " ";

	while ((place = genres.find(delimeter)) != std::string::npos)
	{
		token = genres.substr(0, place);
		genresCollection.push_back(token);
		genres.erase(0, place + delimeter.length());
	}

	genresCollection.push_back(genres);
}

void ConsoleHandler::removeSpace(std::string& str)
{
	std::string strWithoutSpacesAfter;

	for (int i = 0; str[i]; i++)
	{
		if (str[i] == ' ' && str[i + 1] == '\0')
		{
			break;
		}
		else
		{
			strWithoutSpacesAfter += str[i];
		}
	}

	str = strWithoutSpacesAfter;
}

//Save data in a file
void ConsoleHandler::save()
{
	f_inout.open("users.txt", std::ios::out);
	//f_inout.clear();
	f_inout << listOfUsers;
	f_inout << std::endl;
	f_inout.close();
}

//Message for the logged user
void ConsoleHandler::actionsAfterLogIn()    
{
	std::cout << "Choose one of the following: " << std::endl;
	std::cout << "1 - Change profile data" << std::endl;
	std::cout << "2 - Add song" << std::endl;
	std::cout << "3 - Generate playlist" << std::endl;
	std::cout << "4 - Save this playlist" << std::endl;
	std::cout << "5 - Load playlist" << std::endl;
	std::cout << "6 - Information about all the songs in this playlist" << std::endl;
	std::cout << "7 - Set rating" << std::endl;
	std::cout << "8 - Exit" << std::endl;
}

bool ConsoleHandler::isAlreadyRegisteredUser(std::string username)
{
	f_inout.open("users.txt");
	std::string line;
	bool isAlreadyInCollection = false;

	while (std::getline(f_inout, line))
	{
		if (line == username)
		{
			isAlreadyInCollection = true;
		}
	}

	f_inout.close();

	return isAlreadyInCollection;
}

void ConsoleHandler::loadDataToCollections()
{
	f_inout.open("users.txt");

	std::string line;
	std::vector<std::string> arrOfData;
	std::vector<std::string> favGenres;
	int index = 0, next = 0;

	while (std::getline(f_inout, line))
	{
		if (line != "___\r")
		{
			arrOfData.push_back(line);
		}

		index++;

		if(index > 4 && line != "___\r")
		{
			removeSpace(line);
			strToVector(line, favGenres);
		}

		if (line.find("___") != std::string::npos)
		{
			int y, m, d;
			toDateFromFile(arrOfData[3], y, m, d);
			Date date(y, m, d);

			listOfUsers.addUser(arrOfData[0], arrOfData[1], arrOfData[2], date, favGenres, std::set<Playlist>());
			index = 0;
			arrOfData.clear();
			favGenres.clear();
		}
	}

	f_inout.close();
	//listOfUsers.printUsers();
}

//A function that processes all the commands from the console
void ConsoleHandler::processCommand(std::string choice, std::string user, std::string pass, bool& flag)
{
	if (!flag)
	{
		loadDataToCollections();
		flag = true;
	}

	if (choice == "Sign in")
	{
		if (listOfUsers.userExists(user, pass))
		{
			std::cout << "Successfully logged in." << std::endl;
			std::cout << std::endl;
			actionsAfterLogIn();
			//listOfUsers.printUsers();

			int number, i = 0;

			do
			{
				if (i != 0)
				{
					std::cout << "Wrong number. Choose a number between 1 and 8." << std::endl;
				}
				std::cin >> number;
				i++;

			} while (!(number > 0 && number < 9));

			switch (number)
			{
				case 1: listOfUsers.changeProfileData(user); break;
				case 2: listOfUsers.addSong(); break;
				case 3: listOfUsers.generatePlaylist(user);  break;
				case 4: /*listOfUsers.savePlaylistAs();*/ break;
				case 5: /*listOfUsers.loadPlaylistByName();*/ break;
				case 6: /*listOfUsers.showPlaylistInformation();*/ break;
				case 7: /*listOfUsers.setRating();*/ break;
				case 8: return; break; 

				default: break;
			}
			save();
		}
		else
		{
			std::cout << "No such user. Please sign up first." << std::endl;
		}
	}
	else if (choice == "Sign up")
	{
		std::cout << "Please enter on a separate lines the following things: " <<
			"\nusername, password, fullname, birthdate and your favourite genres." << std::endl;

		std::string info;
		std::vector<std::string> arrOfData;
		std::vector<std::string> favGenres;

		while (info != "Submit")
		{
			arrOfData.push_back(info);
			std::getline(std::cin, info);
			if (isAlreadyRegisteredUser(info))
			{
				std::cout << "Sorry, but this username is already taken." << std::endl;
				std::cout << std::endl;
				return;
			}
		}

		for (int i = 5; i < arrOfData.size(); i++)
		{
			favGenres.push_back(arrOfData[i]);
		}

		int y, m, d;
		toDate(arrOfData[4], y, m, d);
		Date date(y, m, d);

		listOfUsers.addUser(arrOfData[1], arrOfData[2], arrOfData[3], date, favGenres, std::set<Playlist>()); 
		//listOfUsers.printUsers();
		save();
	}
	//else if (choice == "Exit")
	//{
		//save();
	//}
}
