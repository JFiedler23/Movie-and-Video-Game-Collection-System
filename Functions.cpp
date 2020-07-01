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
	std::cout << "Type \"cancel\" at any time to go back to the main menu\n\n";

	//Getting game title
	std::cout << "Enter game title: ";
	std::cin.ignore();
	std::getline(std::cin, title);

	//Returning if user typed cancel
	if (title == "cancel")
	{
		return;
	}

	//Getting genre
	std::cout << "Enter game genre: ";
	std::getline(std::cin, genre);

	//Returning if user typed cancel
	if (genre == "cancel")
	{
		return;
	}

	//Getting console
	console = pickConsole();

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
	std::cout << "Type \"cancel\" at any time to go back to the main menu\n\n";

	//Getting title
	std::cout << "Enter movie title: ";
	std::cin.ignore();
	std::getline(std::cin, title);

	//Returning if user typed cancel
	if (title == "cancel")
	{
		return;
	}

	//Getting genre
	std::cout << "Enter movie genre: ";
	std::getline(std::cin, genre);

	//Returning if user typed cancel
	if (genre == "cancel")
	{
		return;
	}

	//Getting format
	std::cout << "Enter movie format: ";
	std::cin >> format;

	//Getting rating
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
	std::cout << "----------Video Game Collection----------\n";
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
	std::cout << "----------Movie Collection----------\n";
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

std::string pickConsole()
{
	int choice;
	std::string console;

	std::cout << "\n";
	std::cout << "\nPlease choose the make of your console or choose PC\n\n";
	
	do
	{
		std::cout << "1. Atari\n";
		std::cout << "2. Microsoft\n";
		std::cout << "3. Nintendo\n";
		std::cout << "4. Sega\n";
		std::cout << "5. Sony\n";
		std::cout << "6. PC\\VR\n";
		std::cout << "Enter your choice: ";
		std::cin >> choice;

		switch (choice)
		{
			case 1:
				console = pickConsoleHelper("consoles/atari.txt");
				break;
			case 2:
				console = pickConsoleHelper("consoles/microsoft.txt");
				break;
			case 3:
				console = pickConsoleHelper("consoles/nintendo.txt");
				break;
			case 4:
				console = pickConsoleHelper("consoles/sega.txt");
				break;
			case 5:
				console = pickConsoleHelper("consoles/sony.txt");
				break;
			case 6:
				console = pickConsoleHelper("consoles/pc.txt");
				break;
			default:
				std::cout << "Invalid choice\n";
				break;
		}
	} while (choice < 1 || choice > 6 || console == "back");

	return console;
}

//Returns name of console
std::string pickConsoleHelper(std::string path)
{
	std::ifstream inputFile;
	std::vector<std::string> consoleList;
	int choice;

	inputFile.open(path);

	//Opening and reading in console list from file
	if (inputFile.is_open())
	{
		for (std::string temp; inputFile >> temp;)
		{
			consoleList.push_back(temp);
		}
	}
	else
	{
		std::cout << "Could not open file\n";
	}
	
	//Allowing the user to pick the console
	do
	{
		std::cout << "\n";
		//Display console options found in file
		for (int i = 0; i < consoleList.size(); i++)
		{
			std::cout << i + 1 << ". " << consoleList[i] << "\n";
		}
		std::cout << consoleList.size() + 1 << ". Go Back\n";
		std::cout << "Enter you choice: ";
		std::cin >> choice;

	} while (choice < 1 || choice > consoleList.size()+1);

	if (choice == consoleList.size() + 1)
	{
		return "back";
	}
	else
	{
		return consoleList[choice - 1];
	}
}