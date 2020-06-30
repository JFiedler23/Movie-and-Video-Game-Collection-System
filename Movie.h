#pragma once
#ifndef MOVIE_H
#define MOVIE_H

#include <string>

class Movie
{
public:
	std::string title, genre, format, rating;

	Movie();
	Movie(std::string title, std::string genre, std::string format, std::string rating);
	void printMovie();

	friend std::ostream& operator << (std::ostream& out, const Movie& obj);
	friend std::istream& operator >> (std::istream& in, Movie& obj);
};

std::ostream& operator << (std::ostream& out, const Movie& obj);
std::istream& operator >> (std::istream& in, Movie& obj);
#endif