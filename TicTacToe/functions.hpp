#pragma once
#include <vector>
void greet();
char** createBoardArray();
void printBoardArr(char** board);
bool getPlayerChoice();
std::vector<int> getInput();
bool setInput(std::vector<int> coords, char** board, bool isX);
bool isGameFinished(char** board);
bool isGameTie(char** board);
