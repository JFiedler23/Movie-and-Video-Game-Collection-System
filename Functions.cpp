#include "Functions.h"
#include <string>
#include <iostream>
#include <fstream>

//Adds a new game to the system
void addGame(std::vector<Game>& gamesList)
{
	std::string title, genre, console, rating;

	std::cout << "\n";
	std::cout << "----------Add Game----------\n";

	std::cout << "Enter game title: ";
	std::cin.ignore();
	std::getline(std::cin, title);

	std::cout << "Enter game genre: ";
	std::getline(std::cin, genre);

	std::cout << "Enter game console: ";
	std::cin >> console;

	std::cout << "Enter game rating: ";
	std::cin >> rating;

	//Replaces any spaces in title with -
	for (int i = 0; i < title.size(); i++)
	{
		if (title[i] == ' ')
		{
			title.replace(i, 1, "-");
		}
	}

	//Replaces any spaces in genre with -
	for (int i = 0; i < genre.size(); i++)
	{
		if (genre[i] == ' ')
		{
			genre.replace(i, 1, "-");
		}
	}

	Game newGame(title, genre, console, rating);

	gamesList.push_back(newGame);

	saveGames(gamesList);
}

//Adds a new movie to the system
void addMovie(std::vector<Movie>& movieList)
{
	std::string title, genre, format, rating;

	std::cout << "\n";
	std::cout << "----------Add Movie----------\n";

	std::cout << "Enter movie title: ";
	std::cin.ignore();
	std::getline(std::cin, title);

	std::cout << "Enter movie genre: ";
	std::getline(std::cin, genre);

	std::cout << "Enter movie format: ";
	std::cin >> format;

	std::cout << "Enter movie rating: ";
	std::cin >> rating;

	//Replaces any spaces in title with -
	for (int i = 0; i < title.size(); i++)
	{
		if (title[i] == ' ')
		{
			title.replace(i, 1, "-");
		}
	}

	//Replaces any spaces in genre with -
	for (int i = 0; i < genre.size(); i++)
	{
		if (genre[i] == ' ')
		{
			genre.replace(i, 1, "-");
		}
	}

	Movie newMovie(title, genre, format, rating);

	movieList.push_back(newMovie);

	saveMovies(movieList);
}

//Displays all games in the system
void displayAllGames(std::vector<Game> gamesList)
{
	for (int i = 0; i < gamesList.size(); i++)
	{
		std::cout << "\n";
		std::cout << "----------Game #" << i + 1 << "----------\n";
		gamesList[i].printGame();
	}
}

//Displays all movies in the system
void displayAllMovies(std::vector<Movie> movieList)
{
	for (int i = 0; i < movieList.size(); i++)
	{
		std::cout << "\n";
		std::cout << "----------Movie #" << i + 1 << "----------\n";
		movieList[i].printMovie();
	}
}

void saveGames(std::vector<Game> gamesList)
{
	std::ofstream outFile;

	outFile.open("saves/SaveData-Games.txt");

	if (outFile.is_open())
	{
		//Writing each class object to a file
		for (int i = 0; i < gamesList.size(); i++)
		{
			outFile << gamesList[i];
		}

		outFile.close();
	}
	else
	{
		std::cout << "Unable to open file" << "\n";
	}
}

void loadGames(std::vector<Game> &gamesList)
{
	std::ifstream inputFile;

	inputFile.open("saves/SaveData-Games.txt");

	if (inputFile.is_open())
	{
		for (Game temp; inputFile >> temp;)
		{
			gamesList.push_back(temp);
		}

		inputFile.close();
	}
	else
	{
		std::cout << "Unable to open file" << "\n";
	}
}

void saveMovies(std::vector<Movie> movieList)
{
	std::ofstream outFile;

	outFile.open("saves/SaveData-Movies.txt");

	if (outFile.is_open())
	{
		//Writing each class object to a file
		for (int i = 0; i < movieList.size(); i++)
		{
			outFile << movieList[i];
		}

		outFile.close();
	}
	else
	{
		std::cout << "Unable to open file" << "\n";
	}
}

void loadMovies(std::vector<Movie>& movieList)
{
	std::ifstream inputFile;

	inputFile.open("saves/SaveData-Movies.txt");

	if (inputFile.is_open())
	{
		for (Movie temp; inputFile >> temp;)
		{
			movieList.push_back(temp);
		}

		inputFile.close();
	}
}
