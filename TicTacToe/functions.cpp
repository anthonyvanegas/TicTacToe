#include <iostream>
#include <vector>

void greet() {
	std::cout << "Hello! Welcome to Tic Tac Toe!" << "\n";
	std::cout << "Created By: Anthony Vanegas" << "\n\n";
}

//Create a empty board and return it using a multi array, we return a pointer to it
char** createBoardArray() {
	char** c = new char*[3];
	for (int i = 0; i <= 2; i++) {
		c[i] = new char[3];
		for (int j = 0; j <= 2; j++) {
			c[i][j] = '_';
		}
	}
	return c;
}

void printBoardArr(char** board) {
	std::cout << "\tTIC TAC TOE: " << "\n";
	std::cout << "\t  1  2  3 " << "\n";
	for (int i = 0; i <= 2; i++) {
		std::cout << "\t" << i + 1;
		for (int j = 0; j <= 2; j++) {
			std::cout << "|" << board[i][j] << "|";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

bool getPlayerChoice() {
	//get choice from user
	bool p1Choice = false;  //true = x
	char choice;

	std::cout << "Player 1: Choose Your Tally (X/O) - ";
	std::cin >> choice;
	std::cout << "\n";
	
	if (choice == 'X') { p1Choice = !p1Choice; }

	return choice;
}

std::vector<int> getInput() {
	int row;
	int column;

	//Get row
	std::cout << "Enter Row (1-3): ";
	std::cin >> row;

	//Get column
	std::cout << "Enter Column (1-3): ";
	std::cin >> column;
	std::cout << "\n";
	
	std::vector<int> coords = {row-1, column-1};
	return coords;
}

bool setInput(std::vector<int> coords, char** board, bool isX) {
	if (board[coords[0]][coords[1]] == '_') {
		if (isX) {
			board[coords[0]][coords[1]] = 'X';
		}
		else {
			board[coords[0]][coords[1]] = 'O';
		}
		return true;
	}
	else {
		return false;
	}
}

bool isGameFinished(char** board) {
	bool win = false;

	//Check if theres a win horizontally
	for (int i = 0; i <= 2; i++) {
		if (board[i][0] != '_' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) { win = true; }
	}

	//Check if theres a win vertically
	for (int j = 0; j < 3; j++) {
		if (board[0][j] != '_' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
			win = true;
		}
	}

	//Check if there is a win diagonlly up
	if (board[0][0] != '_' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
		win = true;
	}

	//Check if there is a win diagonlly down
	if (board[2][0] != '_' && board[2][0] == board[1][1] && board[1][1] == board[0][2]) {
		win = true;
	}

	return win;
}

bool isGameTie(char** board) {
	bool tie = false;
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			if (board[i][j] != '_') { tie = true; }
			else { 
				tie = false;
				break;
			}
		}
	}
	return tie;
}