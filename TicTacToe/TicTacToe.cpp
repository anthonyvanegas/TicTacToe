// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "functions.h"

int main()
{
    std::vector<std::vector<char>> board = createBoard();
    bool gameFinished = false;
    bool gameIsTie = false;

    greet();
    printBoard(board);

    //Get choice from user
    bool p1Choice = false;  //True = X
    char choice;
    std::cout << "Player 1: Choose your tally (X/O) - ";
    std::cin >> choice;
    std::cout << "\n";
    if (choice == 'X') { p1Choice = !p1Choice; }

    bool playerState = true;
    bool confirmInput;
    while(!gameFinished && !gameIsTie) {
        //Get player 1s input
        if (playerState) { 
            std::cout << "Player 1 make your choice:\n";
            confirmInput = setInput(getInput(), board, p1Choice);
        }
        else { 
            std::cout << "Player 2 make your choice:\n";
            confirmInput = setInput(getInput(), board, !p1Choice);
        }

        if (confirmInput){ playerState = !playerState; }
        else { std::cout << "Position already taken!\n\n"; }

        printBoard(board);

        //Now here we add function that checks to see if the game is won or not
        gameFinished = isGameFinished(board);
        gameIsTie = isGameTie(board);

        //Debug Area
        std::cout << "Size of board: " << sizeof(board) << "\n";

    }
    if (!gameIsTie) {
        if (!playerState) {
            std::cout << "Player 1 won!";
        }
        else {
            std::cout << "Player 2 won!";
        }
    } else {
        std::cout << "Game is tie!";
    }
}


