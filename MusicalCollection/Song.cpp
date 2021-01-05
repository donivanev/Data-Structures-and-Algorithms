#include "Song.h"

Song::Song(std::string _name = "", std::string _singer = "", std::string _genre = "", std::string _album = "",
           int _year = 0, float _rating = 0)
{
    name = _name;
    singer = _singer;
    genre = _genre;
    album = _album;
    year = _year;
    rating = _rating;
}

std::string Song::getName()
{
    return this->name;
}

std::string Song::getSinger()
{
    return this->singer;
}

std::string Song::getGenre()
{
    return this->genre;
}

std::string Song::getAlbum()
{
    return this->album;
}

Date Song::getYear()
{
    return this->year;
}

float Song::getRating()
{
    return this->rating;
}

bool Song::operator < (const Song& s) const
{
    return name < s.name;
}

std::ostream& operator << (std::ostream& output, const Song& song)
{
    output << song.name << std::endl;
    output << song.singer << std::endl;
    output << song.genre << std::endl;
    output << song.album << std::endl;
    output << song.year << std::endl;
    output << song.rating << std::endl;

    return output;
}