#pragma once
#include <iostream>
#include <string>
#include <set>
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
	float rating;	
	std::set<std::string> usersWhoVoted;

public:
	Song(std::string _name, std::string _singer, std::string _genre, std::string _album, 
		 int _year, float _rating);

	std::string getName();
	void setName(std::string _name);
	std::string getSinger();
	void setSinger(std::string _singer);
	std::string getGenre();
	void setGenre(std::string _genre);
	std::string getAlbum();
	void setAlbum(std::string _album);
	int getYear();
	void setYear(int _year);
	float getRating();
	void setRating(float _rating);

	//void addToRating(float value);
	float getAverageRating(int numberOfUsers);

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

Тези критерии да могат да се комбинират с логически операции И и ИЛИ и да се подреждат по приоритет.
	Плейлиста да е подреден според критериите и след това по азбучен ред на песните.
	Playlist playlist;
	bool ? && ||
	1   rating > 4.5 => song.getRating() > rating => u.playlistsCollection.insert(Playlist(Song()))

	2   yes    if song.getGenre() is not contained in u.favouriteGenres => do not add
	    no     else													  => add

	3   add     addedGenresCollection    if song.getGenre() is in addedGenresCollection => add
		  remove  removedGenresCollection  if song.getGenre() is in removedGenresCollection => do not add

	4   if < year => if song.getYear() < year => u.playlistsCollection.insert(Playlist(Song()))
	       = year => if song.getYear() == year => u.playlistsCollection.insert(Playlist(Song()))
	       > year => if song.getYear() > year => u.playlistsCollection.insert(Playlist(Song()))

	playlist.addSongInPlaylist(song);

	1 && 2 || 3 && 4
 */