#include "User.h"

//A constructor that initializes User data
User::User(std::string _username = "", std::string _password = "", std::string _fullName = "", 
	Date _birthdate = Date(), std::vector<std::string> _favouriteGenres = std::vector<std::string>())
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

	return output;
}