#include "Song.h"

Song::Song(std::string _name = "", std::string _singer = "", std::string _genre = "", std::string _album = "",
    Date _year = Date(), double _rating = 0)
{
    name = _name;
    singer = _singer;
    genre = _genre;
    album = _album;
    year = _year;
    rating = _rating;
}