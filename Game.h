#pragma once
#ifndef GAME_H
#define GAME_H

#include <string>

class Game
{
	public:
	std::string title, genre, console, rating;

	Game();
	Game(std::string title, std::string genre, std::string console, std::string rating);
	void printGame();
	friend std::ostream& operator << (std::ostream& out, const Game& obj);
	friend std::istream& operator >> (std::istream& in, Game& obj);
};

std::ostream& operator << (std::ostream& out, const Game& obj);
std::istream& operator >> (std::istream& in, Game& obj);

#endif // !GAME_H

