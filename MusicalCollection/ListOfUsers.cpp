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

//A function that print all the users
void ListOfUsers::printUsers()
{
	for (User u : listOfUsers)
	{
		u.printUser();
	}
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
				case 'U': std::cout << "Please type your new username: "; std::cin >> strData;
						  u.setUsername(strData); break;
				case 'P': std::cout << "Please type your new password: "; std::cin >> strData;
						  u.setPassword(strData); break;
				case 'F': std::cout << "Please type your new fullname: "; std::cin >> strData;
						  u.setFullName(strData); break;
				case 'B': std::cout << "Please type your new birthdate: "; std::cin >> strData; break;
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

std::ostream& operator << (std::ostream& output, const ListOfUsers& list)
{
	for (User user : list.listOfUsers)
	{
		output << user << "\n___\r\n";
	}

    return output;
}
