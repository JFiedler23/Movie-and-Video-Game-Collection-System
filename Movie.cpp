#include "Movie.h"
#include <iostream>

Movie::Movie()
{
	title = "";
	genre = "";
	format = "";
	rating = "";
}
Movie::Movie(std::string title, std::string genre, std::string format, std::string rating)
{
	this->title = title;
	this->genre = genre;
	this->format = format;
	this->rating = rating;
}

void Movie::printMovie()
{
	std::cout << "Title: " << title << std::endl;
	std::cout << "Genre: " << genre << std::endl;
	std::cout << "Format: " << format << std::endl;
	std::cout << "Rating: " << rating << std::endl;
}

std::ostream& operator << (std::ostream& out, const Movie& obj)
{
	out << obj.title << "\n" << obj.genre << "\n" << obj.format << "\n" << obj.rating << std::endl;
	return out;
}

std::istream& operator >> (std::istream& in, Movie& obj)
{
	in >> obj.title;
	in >> obj.genre;
	in >> obj.format;
	in >> obj.rating;
	return in;
}