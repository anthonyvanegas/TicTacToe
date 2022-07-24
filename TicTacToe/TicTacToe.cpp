// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "functions.hpp"

int main()
{

    char** board;
    bool gameFinished = false;
    bool gameIsTie = false;
    bool p1Choice;

    greet();
    board = createBoardArray();
    printBoardArr(board);
    p1Choice = getPlayerChoice();


    bool playerState = true;
    bool confirmInput;
    while(!gameFinished && !gameIsTie) {
        //get player 1s input
        if (playerState) { 
            std::cout << "player 1 make your choice:\n";
            confirmInput = setInput(getInput(), board, p1Choice);
        }
        else { 
            std::cout << "player 2 make your choice:\n";
            confirmInput = setInput(getInput(), board, !p1Choice);
        }

        if (confirmInput){ playerState = !playerState; }
        else { std::cout << "Position already taken!\n\n"; }

        printBoardArr(board);

        //now here we add function that checks to see if the game is won or not
        gameFinished = isGameFinished(board);
        gameIsTie = isGameTie(board);

    }
    if (!gameIsTie) {
        if (!playerState) {
            std::cout << "player 1 won!";
        }
        else {
            std::cout << "player 2 won!";
        }
    } else {
        std::cout << "game is tie!";
    }

    delete(board);
}


