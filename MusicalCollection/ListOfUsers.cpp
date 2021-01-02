#include "ListOfUsers.h"

//A function that converts a date in format "dd-mm-yyyy" to date in with integers in order to 
//eventually comparing dates
void ListOfUsers::toDate(std::string& str, int& y, int& m, int& d)
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

	d = stoi(v.at(0));
	m = stoi(v.at(1));
	y = stoi(v.at(2));
}

void ListOfUsers::strToVector(std::string genres, std::vector<std::string>& genresCollection)
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

int strToInt(std::string s)
{
	int number = 0, power = 0;

	for (int i = s.length() - 1; i >= 0; i--)
	{
		number += (s[i] - '0') * pow(10, power);
		power++;
	}

	return number;
}

void ListOfUsers::removeSpace(std::string& str)
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

void ListOfUsers::saveSong(std::set<Song> listOfSongs)
{
	f_inout.open("songs.txt", std::ios::out);
	//f_inout.clear();
	for (Song song : listOfSongs)
	{
		f_inout << song << "\n-----";
		f_inout << std::endl;
	}
	f_inout.close();
}

void ListOfUsers::processExpression(std::string expression, std::vector<std::string>& arr)
{
	int place = 0;
	std::string token, delimeter = " ";

	while ((place = expression.find(delimeter)) != std::string::npos)
	{
		token = expression.substr(0, place);
		arr.push_back(token);
		expression.erase(0, place + delimeter.length());
	}

	arr.push_back(token);
}

//A function that searches the file for an user
bool ListOfUsers::userExists(std::string username, std::string password)
{
	/*for (User user : listOfUsers)
	{
		if (user.getUsername() == username && user.getPassword() == password)
		{
			return true;
		}
	}

	return false;*/

	f_inout.open("users.txt");

	std::string line;
	bool usr = false, pas = false;

	while (std::getline(f_inout, line)) 
	{
		if (line.find(username) != std::string::npos) 
		{
			if (username == line)
			{
				usr = true;
			}
		}
 		if (line.find(password) != std::string::npos)
		{
			if (password == line)
			{
				pas = true;
			}
		}
		if (usr && pas)
		{
			break;
		}
		if (line == "___\r")
		{
			usr = false;
			pas = false;
		}
	}
	
	f_inout.close();

	return usr && pas;
} 

//A function that adds an user
void ListOfUsers::addUser(std::string _username, std::string _password, std::string _fullName, Date _birthdate,
				          std::vector<std::string> _favouriteGenres)
{
	listOfUsers.push_back(User(_username, _password, _fullName, _birthdate, _favouriteGenres));
}

//A function that prints all the users
void ListOfUsers::printUsers()
{
	for (User u : listOfUsers)
	{
		u.printUser();
	}
}

void ListOfUsers::returnSongsToCollection()
{
	f_inout.open("songs.txt");

	std::string line;
	std::vector<std::string> arrOfData;

	while (std::getline(f_inout, line))
	{
		if (line != "-----\r")
		{
			arrOfData.push_back(line);
		}

		if (line.find("-----") != std::string::npos)
		{
			Song song(arrOfData[0], arrOfData[1], arrOfData[2], arrOfData[3], stoi(arrOfData[4]), 
					  atof(arrOfData[5].c_str()));
			listOfSongs.insert(song);
			arrOfData.clear();
		}
	}

	f_inout.close();
}

void ListOfUsers::changeProfileData(std::string user)
{
	std::cout << "Please choose one of the following: " << std::endl;
	std::cout << "Type U to change your username." << std::endl;
	std::cout << "Type P to change your password." << std::endl;
	std::cout << "Type F to change your fullname." << std::endl;
	std::cout << "Type B to change your birthdate." << std::endl;
	std::cout << "Type G to change your favourite genres." << std::endl;

	char choice = ' ';
	std::cin >> choice;
	std::string strData;
	int y, m, d;
	char aOrR = ' ';
	std::vector<User> listOfUsersHelper;

	for (User u : listOfUsers)
	{
		if (u.getUsername() == user)
		{
			switch (choice)
			{
				case 'U': std::cout << "Please type your new username: "; std::cin.ignore();
					std::getline(std::cin, strData); u.setFullName(strData); break;
						  u.setUsername(strData); break;

				case 'P': std::cout << "Please type your new password: "; std::cin.ignore();
					std::getline(std::cin, strData); u.setFullName(strData); break;
						  u.setPassword(strData); break;

				case 'F': std::cout << "Please type your new fullname: "; std::cin.ignore(); 
					std::getline(std::cin, strData); u.setFullName(strData); break;

				case 'B': std::cout << "Please type your new birthdate: "; std::cin.ignore();
					std::getline(std::cin, strData); u.setFullName(strData); break;

				case 'G': std::cout << "-Type A to add a favourite genre." << std::endl;
						  std::cout << "-Type R to remove a favourite genre." << std::endl;
						  std::cin >> aOrR; break;
				default: break;
			}

			if (choice == 'B')
			{
				toDate(strData, y, m, d);
				Date date(y, m, d);
				u.setBirthdate(date);
			}

			if (aOrR == 'A')
			{
				std::string g;
				std::cin >> g;

				u.addGenre(g);
			}
			else if (aOrR == 'R')
			{
				std::string g;
				std::cin >> g;

				u.removeGenre(g); 
			}
		}
		std::vector<std::string> favGenres;
		strToVector(u.getGenres(), favGenres); 
	
		listOfUsersHelper.push_back(User(u.getUsername(), u.getPassword(), u.getFullName(), u.getBirthdate(), favGenres));
	}

	listOfUsers = listOfUsersHelper;
	//printUsers();
}

void ListOfUsers::addSong()
{
	std::cout << "Please enter on a separate lines the following things: " <<
		"\nname, singer, genre, album, year, rating." << std::endl;

	std::string info;
	std::vector<std::string> arrOfData; 

	while (info != "Submit")
	{
		std::getline(std::cin, info);
		arrOfData.push_back(info);
	}

	Song song(arrOfData[1], arrOfData[2], arrOfData[3], arrOfData[4], stoi(arrOfData[5]), atof(arrOfData[6].c_str()));

	returnSongsToCollection();
	listOfSongs.insert(song);
	saveSong(listOfSongs);
}

/*
Генериране на плейлист с определен максимален размер по дадени критерии.
Тези критерии да могат да се комбинират с логически операции И и ИЛИ и да се подреждат по приоритет.
Плейлиста да е подреден според критериите и след това по азбучен ред на песните.

Критерии:
Рейтинг, по - голям от определена стойност
Включване или изключване на дадено множество жанрове
Да са само от любимите на потребителя жанрове
Да са само от / след / преди определена година
*/

void ListOfUsers::generatePlaylist(std::string user)
{
	returnSongsToCollection();
	std::cout << "Please choose from those following criteria and type one or more: " << std::endl;
	std::cout << "1. Rating bigger than a certain value (> [value])." << std::endl;
	std::cout << "2. Add or remove genres. (add/remove {genres})" << std::endl;
	std::cout << "3. Only from your favourite genres (y/n)." << std::endl;
	std::cout << "4. From/after/before a certain year (</=/> [year])." << std::endl;
	
	std::cout << "Enter an expression in the form: [criteria &&/|| criteria &&/|| criteria"
			  << "&&/|| criteria]\n";

	std::cin.ignore();
	std::string expression;
	std::getline(std::cin, expression);
	std::vector<std::string> arr;

	processExpression(expression, arr);

	//processCriteria(arr);

	char choice = ' ';
	//std::cin >> choice;
	std::string year;
	double rating;
	std::string genres;
	bool favourites = false;
	char criteria = ' ';
	std::string path[6] = { "L", "R", "RL", "RR", "RRL", "RRR" };
	int index = 0, indexArr = 1;

	t.addNode(arr.at(indexArr).c_str(), "");
	indexArr += 2;

	for (User u : listOfUsers)  
	{
		if (u.getUsername() == user)
		{
			Playlist playlist;

			for (Song song : listOfSongs)
			{
				for (int i = 0; i < arr.size(); i++)
				{
					if (arr[i] == "1")
					{
						std::cout << "Please enter rating: ";
						std::cin >> rating;

						song.getRating() < rating ? t.addNode("T", path[index].c_str())
												  : t.addNode("F", path[index].c_str());
						index++;
					}
					else if (arr[i] == "2")
					{
						std::cout << "Please enter add/remove [genres]: ";
						std::getline(std::cin, genres);
						std::unordered_set<std::string> s;
						char empty = ' ';

						int place = 0;
						std::string token, delimeter = " ";

						while ((place = expression.find(delimeter)) != std::string::npos)
						{
							token = expression.substr(0, place);
							s.insert(token);
							expression.erase(0, place + delimeter.length());
						}

						s.insert(token);

						if (*(s.begin()) == "add")
						{
							
						}
						else if (*(s.begin()) == "remove")
						{

						}

						for (auto iter = s.begin(); iter != s.end(); ++iter) 
						{
							if (*iter == "a")
							{
								
							}
							else if (*iter == "r")
							{

							}
							else
							{
								std::cout << "Wrong command!";
							}
						}
					}
					else if (arr[i] == "3")
					{
						std::cin.ignore();
						std::cout << "Do you want the songs to be only from your favourite genres? ";
						std::cin >> choice;

						if (choice == 'y')
						{
							u.isFromFavourites(song.getGenre()) ? t.addNode("T", path[index].c_str())
															    : t.addNode("F", path[index].c_str());
							index++;
						}
					}
					else if (arr[i] == "4")
					{
						std::cout << "Please enter <, = or > [year] to select your filtering: ";
						std::getline(std::cin, year);

						int y = strToInt(year.substr(2));

						switch (year[0])
						{
							case '>': song.getYear() > y ? t.addNode("T", path[index].c_str())
														 : t.addNode("F", path[index].c_str()); 
								break;
							case '=': song.getYear() == y ? t.addNode("T", path[index].c_str())
														  : t.addNode("F", path[index].c_str());
								break;
							case '<': song.getYear() < y ? t.addNode("T", path[index].c_str())
													     : t.addNode("F", path[index].c_str());
								break;
							default: break;
						}

						index++;
					}

					t.addNode(arr.at(indexArr), path[index].c_str());
					index++;
					indexArr += 2;
				}

				//if (t.evaluateExpression())
				//{
					//playlist.addSongToPlaylist(song);
				//}
			}

			//u.pushInPlaylist(playlist);
		}
	}

	//Тези критерии да могат да се комбинират с логически операции И и ИЛИ и да се подреждат по приоритет.
	//Плейлиста да е подреден според критериите и след това по азбучен ред на песните.
	//Playlist playlist;
	//bool ? && ||
	//1   rating > 4.5 => song.getRating() > rating => u.playlistsCollection.insert(Playlist(Song()))

	//2   yes    if song.getGenre() is not contained in u.favouriteGenres => do not add
	//    no     else													  => add

	//3   add     addedGenresCollection    if song.getGenre() is in addedGenresCollection => add
	//	  remove  removedGenresCollection  if song.getGenre() is in removedGenresCollection => do not add

	//4   if < year => if song.getYear() < year => u.playlistsCollection.insert(Playlist(Song()))
	//       = year => if song.getYear() == year => u.playlistsCollection.insert(Playlist(Song()))
 	//       > year => if song.getYear() > year => u.playlistsCollection.insert(Playlist(Song()))

	//playlist.addSongInPlaylist(song);

	//1 && 2 || 3 && 4
}

std::ostream& operator << (std::ostream& output, const ListOfUsers& list)
{
	for (User user : list.listOfUsers)
	{
		output << user << "\n___\r\n";
	}

    return output;
}
