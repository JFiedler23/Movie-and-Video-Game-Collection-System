#include "Game.h"
#include <iostream>

Game::Game()
{
	title = "";
	genre = "";
	console = "";
	rating = "";
}

Game::Game(std::string title, std::string genre, std::string console, std::string rating)
{
	this->title = title;
	this->genre = genre;
	this->console = console;
	this->rating = rating;
}

void Game::printGame()
{
	std::cout << "Title: " << title << std::endl;
	std::cout << "Genre: " << genre << std::endl;
	std::cout << "Console: " << console << std::endl;
	std::cout << "Rating: " << rating << std::endl;
}

std::ostream& operator << (std::ostream& out, const Game& obj)
{
	out << obj.title << "\n" << obj.genre << "\n" << obj.console << "\n" << obj.rating << std::endl;
	return out;
}

std::istream& operator >> (std::istream& in, Game& obj)
{
	in >> obj.title;
	in >> obj.genre;
	in >> obj.console;
	in >> obj.rating;
	return in;
}