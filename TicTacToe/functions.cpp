#include <iostream>
#include <vector>

void greet() {
	std::cout << "Hello! Welcome to Tic Tac Toe! Here is the Board:\n" << "\n";
}

std::vector<std::vector<char>> createBoard() {
	std::vector<char> firstLine = { '_', '_', '_' };
	std::vector<char> secondLine = { '_', '_', '_' };
	std::vector<char> thirdLine = { '_', '_', '_' };

	std::vector<std::vector<char>> board;

	board.push_back(firstLine);
	board.push_back(secondLine);
	board.push_back(thirdLine);

	return board;
}

void printBoard(std::vector<std::vector<char>> boardArray) {
	std::cout << "  1  2  3 " << "\n";
	for (int i = 0; i < boardArray.size(); i++) {
		std::cout << i+1;
		for (int j = 0; j < boardArray[i].size(); j++) {
			std::cout << "|" << boardArray[i][j] << "|";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
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

bool setInput(std::vector<int> coords, std::vector<std::vector<char>> &board, bool isX) {
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

bool isGameFinished(std::vector<std::vector<char>> board) {
	bool win = false;

	//Check if theres a win horizontally
	for (std::vector<char> x : board) {
		if (x[0] != '_' && x[0] == x[1] && x[1] == x[2]) { win = true; }
	}

	//Check if theres a win vertically
	for (int i = 0; i < 3; i++) {
		if (board[0][i] != '_' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
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

bool isGameTie(std::vector<std::vector<char>> board) {
	bool tie = false;
	for (std::vector<char> x : board) {
		for (char i : x) {
			if (i != '_') { tie = true; }
			else { 
				tie = false;
				break;
			}
		}
	}
	return tie;
}