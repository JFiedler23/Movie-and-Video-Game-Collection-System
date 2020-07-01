#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include "Game.h"
#include "Movie.h"

void addGame(std::vector<Game> &gamesList);
void addMovie(std::vector<Movie> &movieList);

void displayAllGames(std::vector<Game> gamesList);
void displayAllMovies(std::vector<Movie> movieList);

void saveGames(std::vector<Game> gamesList);
void loadGames(std::vector<Game>& gamesList);

void saveMovies(std::vector<Movie> movieList);
void loadMovies(std::vector<Movie>& movieList);

//Video game console functions
std::string pickConsole();
std::string pickConsoleHelper(std::string path);
#endif // !FUNCTIONS_H