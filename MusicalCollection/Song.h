#pragma once
#include <iostream>
#include <string>
#include "Date.h"

class Song
{
private:
	std::string name;
	std::string singer;
	std::string genre;
	std::string album;
	Date year;
	double rating;

public:
	Song(std::string _name, std::string _singer, std::string _genre, std::string _album, 
		Date _year, double _rating);
};