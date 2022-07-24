/*  TicTacToe.cpp : This file contains the 'main' function.Program execution begins and ends there.
 *  
 *  Created by: Anthony Vangegas
 *  
 *  This is a console based Tic Tac Toe game. All underlying functions for this game can be found in
 *  functions.cpp.     
*/

#include <iostream>
#include "functions.hpp"

int main()
{

    char** board;                   //Character pointer to char array conatining contents of board
    bool gameFinished = false;      //For storing the status of the game
    bool gameIsTie = false;         //Whether of not the game is a tie
    bool p1Choice;                  //Player one choice

    greet();
    board = createBoardArray();
    printBoardArr(board);
    p1Choice = getPlayerChoice();


    bool playerState = true;        //This is used to flip flop between player 1 and 2
    bool confirmInput;              //Holds status of input, if it was succuessful = true
    while(!gameFinished && !gameIsTie) {
        //Get player input
        if (playerState) { 
            std::cout << "player 1 make your choice:\n";
            confirmInput = setInput(getInput(), board, p1Choice);
        }
        else { 
            std::cout << "player 2 make your choice:\n";
            confirmInput = setInput(getInput(), board, !p1Choice);
        }

        //Check status of input
        if (confirmInput){ playerState = !playerState; }
        else { std::cout << "Position already taken!\n\n"; }

        printBoardArr(board);

        //Functions to check on game status
        gameFinished = isGameFinished(board);
        gameIsTie = isGameTie(board);

    }
    
    //Logic to display games final status
    if (!gameIsTie) {
        if (!playerState) {
            std::cout << "player 1 won!";
        }
        else {
            std::cout << "player 2 won!";
        }
    }
    else {
        std::cout << "game is tie!";
    }

    delete(board);
}


