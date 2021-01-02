#pragma once
#include <iostream>
#include <string>
#include "Date.h"

//A class that holds the information about the song

class Song
{
private:
	std::string name;
	std::string singer;
	std::string genre;
	std::string album;
	int year;
	double rating;	

public:
	Song(std::string _name, std::string _singer, std::string _genre, std::string _album, 
		int _year, double _rating);

	std::string getName();
	std::string getSinger();
	std::string getGenre();
	std::string getAlbum();
	Date getYear();
	double getRating();
	bool operator < (const Song& s) const;
	friend std::ostream& operator << (std::ostream& output, const Song& song);
};

/*
Генериране на плейлист с определен максимален размер по дадени критерии. 
Тези критерии да могат да се комбинират с логически операции И и ИЛИ и да се подреждат по приоритет. 
Плейлиста да е подреден според критериите и след това по азбучен ред на песните. 

Критерии:
Рейтинг, по-голям от определена стойност
Включване или изключване на дадено множество жанрове
Да са само от любимите на потребителя жанрове
Да са само от/след/преди определена година

Записване на текущия плейлист под дадено име
Зареждане на даден плейлист по име
Показване на информация за всички песни текущия плейлист
Задаване на рейтинг на определена песен. Общият рейтинг на песен се определя като средна стойност от 
всички гласувания на потребители. Не трябва да позволявате на потребител да гласува повече от един път 
за дадена песен.
*/
 





