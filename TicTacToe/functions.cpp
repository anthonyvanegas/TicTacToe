#include <iostream>
#include <vector>

/*
* Function to display greeting message to user.
*/
void greet() {
	std::cout << "Hello! Welcome to Tic Tac Toe!" << "\n";
	std::cout << "Created By: Anthony Vanegas" << "\n\n";
}

/*
* This function creates an empty board and returns a pointer to the multi-dim char array.
*/
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

/*
* This function prints the contents of a given multi-dim char array. 
* We also add some formatting to the output for read-ablity.
*/
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

/*
* We get the player choice and the return it using a boolean.
* True = X
* False = O
*/
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

/*
* This function sets the given coordinate values in the board, given a pointer to the board and the players tally.
*/
bool setInput(char** board, bool isX) {

	int row;
	int column;

	//Get row
	std::cout << "Enter Row (1-3): ";
	std::cin >> row;

	//Get column
	std::cout << "Enter Column (1-3): ";
	std::cin >> column;
	std::cout << "\n";

	//To match array locations
	row = row - 1;
	column = column - 1;

	if (board[row][column] == '_') {
		if (isX) {
			board[row][column] = 'X';
		}
		else {
			board[row][column] = 'O';
		}
		return true;
	}
	else {
		return false;
	}
}


/*
* This function checks the status of the board. Game logic is given below.
*/
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

/*
* This function also checks the board for a tie, game logic is given below.
*/
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