#include <iostream>
#include <iomanip>
#include "Functions.h"


int main()
{
	int choice = -1;
	int searchIndex;
	std::vector<Game> gamesList;//stores all games in the system
	std::vector<Movie> movieList;//stores all movies in the system

	loadGames(gamesList);
	loadMovies(movieList);

	while (choice != 9)
	{
		//Main menu
		std::cout << "\n";
		std::cout << "----------Movie and Video Game Collection System----------\n";
		std::cout << "\n";
		std::cout << "Main Menu\n";
		std::cout << "---------\n";
		std::cout << "1. Add game\n";
		std::cout << "2. Add movie\n";
		std::cout << "3. Remove game\n";
		std::cout << "4. Remove movie\n";
		std::cout << "5. Game search\n";
		std::cout << "6. Movie Search\n";
		std::cout << "7. Display All Games\n";
		std::cout << "8. Display All Movies\n";
		std::cout << "9. Quit\n";
		std::cout << "\n";

		//Prompting user for their menu choice
		std::cout << "Enter the menu option number your choice >";
		std::cin >> choice;

		switch (choice)
		{
			case 1:
				addGame(gamesList);
				break;
			case 2:
				addMovie(movieList);
				break;
			case 3:
				removeGame(gamesList);
				break;
			case 4:
				removeMovie(movieList);
				break;
			case 5:
				searchIndex = search("game");
				std::cout << "\n----------Search Results----------\n";

				if (searchIndex > -1)
					gamesList[searchIndex].printGame();
				else
					std::cout << "Game not found in system\n";
				break;
			case 6:
				searchIndex = search("movie");
				std::cout << "\n----------Search Results----------\n";

				if (searchIndex > -1)
					movieList[searchIndex].printMovie();
				else
					std::cout << "Movie not found in system\n";
				break;
			case 7:
				displayAllGames(gamesList);
				break;
			case 8:
				displayAllMovies(movieList);
				break;
			case 9:
				std::cout << "Have a nice day!\n";
				break;
			default:
				std::cout << "\n";
				std::cout << "Invalid choice\n";
				break;
		}
	}
}
