//Oblig 1 Task, TicTacToe

#include <iostream>
#include <string>
#include <Windows.h>

char place[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

bool gameWon = false;
bool p1Turn = true;

int playerChoice = 99;


bool calculateWin()
{


	return true;
}

void printBoard() {
	
	// Generate / Update the play board.
	char board[5][16] = 
	{
		{"-------------"},
		{'|',' ', place[0], ' ', '|', ' ',place[1], ' ', '|', ' ', place[2], ' ', '|'},
		{'|',' ', place[3], ' ', '|', ' ',place[4], ' ', '|', ' ', place[5], ' ', '|'},
		{'|',' ', place[6], ' ', '|', ' ',place[7], ' ', '|', ' ', place[8], ' ', '|'},
		{"-------------"}
	};

	for (int i = 0; i < 5; i++)
	{
		std::cout << "\n";
		for (int j = 0; j < 16; j++)
		{
				std::cout << board[i][j];
		}
	}
}

void editBoard(int p, bool p1TurnCheck) 
{
	if (p1TurnCheck) {
		if (place[p - 1] != 'X' || place[p - 1] != 'O') {
			place[p - 1] = 'X';
			p1Turn = false;
		}
	}
	else 
	{
		if (place[p - 1] != 'X' || place[p - 1] != 'O') {
			place[p - 1] = 'O';
			p1Turn = true;
		}
	}

}

int main()
{
	std::cout << "****** Welcome to Tic Tac Toe! ******\n";
	while (gameWon == false) 
	{
		printBoard();
		std::cout << p1Turn; //Debug

		if (p1Turn) {
			std::cout << "\nPlayer 1, Write a number from 1 to 9: ";
			std::cin >> playerChoice;
			editBoard(playerChoice, p1Turn);
			
		}
		else 
		{
			std::cout << "\nPlayer 2, Write a number from 1 to 9: ";
			std::cin >> playerChoice;
			editBoard(playerChoice, p1Turn);
		}
	}
	


}




//Make it so you cant change X's and O's
//Make it so when p1 places and X in an invalid spot (O or, already placed X), they keep their turn.

//Make calculateWin() Function.




/*	for (int i = 0; i < 2; i++)
	{
		std::cout << "\n";
		for (int j = 0; j < 2; j++)
		{
				std::cout << boardTest[i][j];
		}
	}
*/
