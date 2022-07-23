#pragma once
#include <vector>
void greet();
std::vector<std::vector<char>> createBoard();
void printBoard(std::vector<std::vector<char>> boardArray);
std::vector<int> getInput();
bool setInput(std::vector<int> coords, std::vector<std::vector<char>> &board, bool isX);
bool isGameFinished(std::vector<std::vector<char>> board);
bool isGameTie(std::vector<std::vector<char>> board);