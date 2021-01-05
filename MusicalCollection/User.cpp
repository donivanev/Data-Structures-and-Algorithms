#include "User.h"

//A constructor that initializes User data
User::User(std::string _username = "", std::string _password = "", std::string _fullName = "", 
	       Date _birthdate = Date(), std::vector<std::string> _favouriteGenres = std::vector<std::string>(),
		   std::set<Playlist> _playlistsCollections = std::set<Playlist>())
{
	username = _username;
	password = _password;
	fullName = _fullName;
	birthdate = _birthdate;

	for (std::string s : _favouriteGenres)
	{
		favouriteGenres.push_back(s);
	}
}

std::string User::getUsername()
{
	return this->username;
}

void User::setUsername(std::string _username)
{
	username = _username;
}

std::string User::getPassword()
{
	return this->password;
}

void User::setPassword(std::string _password)
{
	password = _password;
}

std::string User::getFullName()
{
	return this->fullName;
}

void User::setFullName(std::string _fullName)
{
	fullName = _fullName;
}

Date User::getBirthdate()
{
	return this->birthdate;
}

void User::setBirthdate(Date _birthday)
{
	birthdate = _birthday;
}

void User::addGenre(std::string genre)
{
	favouriteGenres.push_back(genre);
}

void User::removeSpace(std::string& str)
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

void User::removeSpaces(std::string& str)
{
	std::string strWithoutSpacesAfter;

	for (int i = 0; str[i]; i++)
	{
		if (str[i] == ' ' && str[i + 1] == ' ')
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

std::string User::getGenres()
{
	std::string allGenres;

	for (std::string str : favouriteGenres)
	{
		removeSpaces(str);
		allGenres += str + " ";
	}

	removeSpace(allGenres);
	return allGenres;
}

void User::removeGenre(std::string genre)
{
	int index = 0;

	for (int i = 0; i < favouriteGenres.size(); i++)
	{
		if (genre == favouriteGenres[i])
		{
			index = i;
		}
	}

	favouriteGenres.erase(favouriteGenres.begin() + index);
}

bool User::isFromFavourites(std::string genre)
{
	for (std::string s : favouriteGenres)
	{
		if (genre == s)
		{
			return true;
		}
	}

	return false;
}

void User::pushInPlaylist(Playlist playlist)
{
	playlistsCollection.insert(playlist);
}

void User::printUser()
{
	std::cout << username << std::endl;
	std::cout << password << std::endl;
	std::cout << fullName << std::endl;
	std::cout << birthdate << std::endl;

	for (std::string genre : favouriteGenres)
	{
		std::cout << genre << " ";
	}

	if (!playlistsCollection.empty())
	{
		for (Playlist p : playlistsCollection)
		{
			std::cout << p << std::endl;
		}
	}

	std::cout << std::endl;
}

std::ostream& operator << (std::ostream& output, const User& user)
{
	output << user.username << std::endl;
	output << user.password << std::endl;
	output << user.fullName << std::endl;
	output << user.birthdate << std::endl;

	for (std::string genre : user.favouriteGenres)
	{
		output << genre << " ";
	}

	if (!user.playlistsCollection.empty())
	{
		for (Playlist p : user.playlistsCollection)
		{
			output << p;
		}
	}

	return output;
}