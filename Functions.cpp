#include "Functions.h"
#include <string>
#include <sstream> //sstringstream
#include <iostream> //cout, cin
#include <fstream> //file i/o
#include <locale> //tolower and locale

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

	//Getting game rating, passing in text file path and type (i.e., rating or format)
	rating = pickRatingFormat("ratings/game_ratings.txt", "rating");

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

	//Creating new game object
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

	//Getting format, passing in movie formats file path and type (i.e., rating or format)
	format = pickRatingFormat("movie_formats.txt", "format");

	//Getting rating, passing in movie ratings file path and type
	rating = pickRatingFormat("ratings/movie_ratings.txt", "rating");

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

	//Creating new movie object
	Movie newMovie(title, genre, format, rating);

	movieList.push_back(newMovie);

	saveMovies(movieList);
}

//Removes a game from the system
void removeGame(std::vector<Game>& gamesList)
{
	std::string title;
	int index;

	std::cout << "\nPlease enter the title of the game you want to remove\n";
	std::cout << ">";
	std::cin.ignore();
	std::getline(std::cin, title);

	index = search("game", title);

	if (index > -1)
	{
		//Removing found game
		gamesList.erase(gamesList.begin() + index);
		std::cout << "Game has been removed from the system\n";

		//saving game list
		saveGames(gamesList);
	}
	else
	{
		std::cout << "Game not found in system\n";
	}
}

//Removes a movie from the system
void removeMovie(std::vector<Movie>& movieList)
{
	std::string title;
	int index;

	std::cout << "\nPlease enter the title of the movie you want to remove\n";
	std::cout << ">";
	std::cin.ignore();
	std::getline(std::cin, title);

	index = search("movie", title);

	if (index > -1)
	{
		//Removing found game
		movieList.erase(movieList.begin() + index);
		std::cout << "Movie has been removed from the system\n";

		//saving movie list
		saveMovies(movieList);
	}
	else
	{
		std::cout << "Game not found in system\n";
	}
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

//Saves games list to a text file
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
	}
	else
	{
		std::cout << "Unable to open file" << "\n";
	}
	outFile.close();
}

//Loads games from text file into vector
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
	}
	else
	{
		std::cout << "Unable to open file" << "\n";
	}

	inputFile.close();
}

//Saves movie list to a text file
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
	}
	else
	{
		std::cout << "Unable to open file" << "\n";
	}

	outFile.close();
}

//Loads movies from text file into vector
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
	}
	else
	{
		std::cout << "Unable to open file" << "\n";
	}

	inputFile.close();
}
//Returns name of console
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
		std::cout << "Choose your console\n";
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

//Allows the user to pick a rating for a game/movie based on a predefined list
std::string pickRatingFormat(std::string filePath, std::string type)
{
	int choice;
	std::ifstream inputFile;
	std::vector<std::string> ratingsList;

	inputFile.open(filePath);

	if (inputFile.is_open())
	{
		std::string line;
		int i = 1;

		std::cout << "\n";
		std::cout << "\nPlease choose the appropriate " << type << "\n\n";

		//Getting ratings list
		while (std::getline(inputFile, line))
		{
			ratingsList.push_back(line);

			//Printing rating options
			std::cout << i << ". " << line << "\n";
			i++;
		}

		//Looping until user makes a valid choice
		do
		{
			std::cout << "Enter your choice: ";
			std::cin >> choice;

			//Checking if user made a valid choice
			if (choice < 1 || choice > ratingsList.size())
			{
				std::cout << "Invalid choice\n";
			}
			else
			{
				return ratingsList[choice-1];
			}


		} while (choice < 1 || choice > ratingsList.size());
	}
	else
	{
		return "N/A";
	}

	inputFile.close();
}

//Searches for a game or movie and returns the index of the found title
int search(std::string searchType, std::string title)
{
	int index;
	std::locale loc;
	std::string searchTemp;
	std::string listTemp;

	//lowercasing users search title
	for (int j = 0; j < title.size(); j++)
	{
		searchTemp.push_back(std::tolower(title[j], loc));
	}

	if (searchType == "game")
	{
		std::vector<Game> gameList;
		loadGames(gameList);

		//checking each title
		for (int i = 0; i < gameList.size(); i++)
		{
			//lowercasing game titles
			for (int j = 0; j < gameList[i].title.size(); j++)
			{
				//finding dashes and replacing them with spaces
				if (gameList[i].title[j] == '-')
				{
					listTemp.push_back(' ');
				}
				//otherwise lowercase each character
				else
				{
					listTemp.push_back(std::tolower(gameList[i].title[j], loc));
				}
			}

			//Checking if there is a match
			if (listTemp == searchTemp)
			{
				return i;
			}
			else
			{
				index = -1;
			}

			//clearing temp string
			listTemp.clear();
		}
	}
	else
	{
		std::vector<Movie> movieList;
		loadMovies(movieList);

		//checking each title
		for (int i = 0; i < movieList.size(); i++)
		{
			//lowercasing game titles
			for (int j = 0; j < movieList[i].title.size(); j++)
			{
				//finding dashes and replacing them with spaces
				if (movieList[i].title[j] == '-')
				{
					listTemp.push_back(' ');
				}
				//otherwise lowercase each character
				else
				{
					listTemp.push_back(std::tolower(movieList[i].title[j], loc));
				}
			}

			//Checking if there is a match
			if (listTemp == searchTemp)
			{
				return i;
			}
			else
			{
				index = -1;
			}

			//clearing temp string
			listTemp.clear();
		}
	}
	return index;
}