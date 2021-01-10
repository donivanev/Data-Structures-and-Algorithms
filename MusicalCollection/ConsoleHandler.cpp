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

bool ConsoleHandler::isValidDate(int y, int m, int d)
{
	if ((d < 1 || d > 31) || (m < 1 || m > 12))
	{
		return false;
	}

	return true;
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
	std::cout << "3 - Generate and save playlist" << std::endl;
	std::cout << "4 - Load playlist by name" << std::endl;
	std::cout << "5 - Set rating" << std::endl;
	std::cout << "6 - Exit" << std::endl;
}

void ConsoleHandler::loadDataToCollections()
{
	f_inout.open("users.txt");

	std::string line;
	std::vector<std::string> arrOfData;
	std::vector<std::string> favGenres;
	std::set<Playlist> playlists;
	std::vector<std::string> songInfo;
	int index = 0, next = 0, indexOfPlaylists = 0;
	Playlist p;

	while (std::getline(f_inout, line))
	{
		if (line != "___\r")
		{
			arrOfData.push_back(line);
		}

		index++;

		if((index > 4 && index < 7) && line != "___\r")
		{
			removeSpace(line);
			strToVector(line, favGenres);
		}

		if (index > 7)
		{
			indexOfPlaylists++;
		}

		if (line.substr(0, line.find(" ")) == "Playlist")
		{
			std::string playlistName = line.substr(line.find(" ") + 1);
			indexOfPlaylists++;

			p.setName(playlistName);
		}

		if (indexOfPlaylists > 2 && line != " ")
		{
			if (line != "")
			{
				songInfo.push_back(line);
			}
		}

		if (indexOfPlaylists > 2 && line != "" && songInfo.size() == 6)
		{
			int year = stoi(songInfo[4]);
			float rating = stof(songInfo[5]);

			Song s(songInfo[0], songInfo[1], songInfo[2], songInfo[3], year, rating);
			p.addSongToPlaylist(s);
			songInfo.clear();
		}

		if (indexOfPlaylists > 1 && line == "~~~~~")
		{
			playlists.insert(p);
			Playlist newP;
			p = newP;
			indexOfPlaylists = 0;
		}

		if (line.find("___") != std::string::npos)
		{
			int y, m, d;
			toDateFromFile(arrOfData[3], y, m, d);
			Date date(y, m, d);

			//for (Playlist p : playlists)
			//{
				//std::cout << p << std::endl;
			//}

			//listOfUsers.addUser(arrOfData[0], arrOfData[1], arrOfData[2], date, favGenres, std::set<Playlist>());
			listOfUsers.addUser(arrOfData[0], arrOfData[1], arrOfData[2], date, favGenres, playlists);
			index = 0;
			arrOfData.clear();
			favGenres.clear();
			playlists.clear();
			songInfo.clear();
		}
	}

	f_inout.close();
	//listOfUsers.printUsers();
}

//A function that processes all the commands from the console
void ConsoleHandler::processCommand(std::string choice, std::string user, std::string pass, bool& flag, bool& exit)
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
			std::cin >> number;

			do
			{
				if (i != 0)
				{
					std::cout << "Wrong number. Choose a number between 1 and 8." << std::endl;

					std::cin >> number;
					i++;
				}
					
				switch (number)
				{
					case 1: listOfUsers.changeProfileData(user); break;
					case 2: listOfUsers.addSong(); break;
					case 3: listOfUsers.generateAndSavePlaylist(user);  break;
					case 4: listOfUsers.loadPlaylistByName(user); break;
					case 5: listOfUsers.setRating(user); break;
					case 6: exit = true; return; break;

					default: break;
				}
				save();
				actionsAfterLogIn();
		
			} while (!(number > 0 && number < 7));

			//save();
		}
		else
		{
			std::cout << "No such user. Please sign up first." << std::endl;
		}
	}
	else if (choice == "Sign up")
	{
		std::cout << "Please enter on a separate lines the following things: " <<
			"\nusername, password, fullname, birthdate and your favourite genres. Then type Submit." << std::endl;

		std::string info;
		std::vector<std::string> arrOfData;
		std::vector<std::string> favGenres;
		int y, m, d;
		bool notValid = false, alreadyExist = false;

		while (info != "Submit")
		{
			std::getline(std::cin, info);

			if (arrOfData.size() == 3)
			{
				try
				{
					toDate(info, y, m, d);
				}
				catch (const std::exception&)
				{
					std::cout << "Please enter date in format dd-mm-yyyy!";
				}

				if (!isValidDate(y, m, d))
				{
					std::cout << "Please enter a valid date format!" << std::endl;
					notValid = true;
				}
			}

			if (arrOfData.size() == 0)
			{
				if (listOfUsers.userExists(info, ""))
				{
					std::cout << "Sorry, but this username is already taken. Try another one." << std::endl;
					
					alreadyExist = true;
					arrOfData.clear();
				}
			}

			if (!notValid && !alreadyExist)
			{
				arrOfData.push_back(info);
			}
		}

		for (int i = 5; i < arrOfData.size(); i++)
		{
			favGenres.push_back(arrOfData[i]);
		}

		toDate(arrOfData[3], y, m, d);
		Date date(y, m, d);

		listOfUsers.addUser(arrOfData[1], arrOfData[2], arrOfData[3], date, favGenres, std::set<Playlist>()); 
		std::cout << "Successfully created user!" << std::endl;
		//listOfUsers.printUsers();
		save();
	}
	//else if (choice == "Exit")
	//{
		//save();
	//}
}
