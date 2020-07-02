#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include "Game.h"
#include "Movie.h"

//Add functions
void addGame(std::vector<Game> &gamesList);
void addMovie(std::vector<Movie> &movieList);

//Remove functions
void removeGame(std::vector<Game> &gamesList);
void removeMovie(std::vector<Movie>& movieList);

//Display functions
void displayAllGames(std::vector<Game> gamesList);
void displayAllMovies(std::vector<Movie> movieList);

//Save/load games
void saveGames(std::vector<Game> gamesList);
void loadGames(std::vector<Game>& gamesList);

//Save/load movies
void saveMovies(std::vector<Movie> movieList);
void loadMovies(std::vector<Movie>& movieList);

//Video game console functions
std::string pickConsole();
std::string pickConsoleHelper(std::string path);

//Ratings/format function
std::string pickRatingFormat(std::string filePath, std::string type);

int search(std::string searchType, std::string title);
#endif // !FUNCTIONS_H