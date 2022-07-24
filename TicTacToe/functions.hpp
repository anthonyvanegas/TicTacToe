#pragma once
#include <vector>
void greet();
char** createBoardArray();
void printBoardArr(char** board);
bool getPlayerChoice();
bool setInput(char** board, bool isX);
bool isGameFinished(char** board);
bool isGameTie(char** board);
