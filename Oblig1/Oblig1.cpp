//Oblig 1 Task, TicTacToe

#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>

const char placeOriginal[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };		//constant board values, used for resetting

char place[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };					//the board used in play

bool gameWon = false;
bool p1Turn = true;		//true = p1's turn, false = p2's turn.

int roundCount{ 0 };

char playAgain = ' ';
char playerChoice = ' ';			//Stores which spot on the board the player wants to claim


void resetGame()
{
	for (int i = 0; i < 9; i++) {
		place[i] = placeOriginal[i];		//Replaces the edited board with a copy of the clean board.
	}
	gameWon = false;
	p1Turn = true;
	roundCount = 0;
}

bool calculateWin(char p)
{

	//Horizontal Wins
	if (place[0] == p && place[1] == p && place[2] == p) 
		return true;
	if (place[3] == p && place[4] == p && place[5] == p) 
		return true;
	if (place[6] == p && place[7] == p && place[8] == p)
		return true;
	
	//Vertical Wins
	if (place[0] == p && place[3] == p && place[6] == p)
		return true;
	if (place[1] == p && place[4] == p && place[7] == p)
		return true;
	if (place[2] == p && place[5] == p && place[8] == p)
		return true;

	//Diagonal Wins
	if (place[0] == p && place[4] == p && place[8] == p)
		return true;
	if (place[2] == p && place[4] == p && place[6] == p)
		return true;
	
	roundCount++;

	return false;
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

void editBoard(char p, bool p1TurnCheck) 
{
	int pInt = p - '0';		//Convert the char (playerChoice) to int so that it is actually usefull.

	if (pInt < 10)
	{

		if (p1TurnCheck) {	//if its player 1s turn
			if (place[pInt - 1] != 'X' && place[pInt - 1] != 'O') {		//Checks if there is already an X or O in the selected spot
				place[pInt - 1] = 'X';
				p1Turn = false;
			}
		}
		else
		{
			if (place[pInt - 1] != 'X' && place[pInt - 1] != 'O') {		
				place[pInt - 1] = 'O';
				p1Turn = true;
			}
		}
	}
}

int main()
{
	while (true){

		while (gameWon == false)	//This is where the game happens
		{
			system("cls");
			std::cout << "****** Welcome to Tic Tac Toe! ******\n";
			printBoard();											//Prints the board each turn
			std::cout << roundCount;
			if (roundCount >= 9)
			{
				gameWon = true;
				break;
			}

			if (p1Turn) {
				std::cout << "\nPlayer 1, Write a number from 1 to 9: ";
				playerChoice = _getch();
				editBoard(playerChoice, p1Turn);						//Replaces the values on the board the player chose.
				gameWon = calculateWin('X');
			}
			else
			{
				std::cout << "\nPlayer 2, Write a number from 1 to 9: ";
				playerChoice = _getch();
				editBoard(playerChoice, p1Turn);
				gameWon = calculateWin('O');
			}
		}

		//Post-game
		system("cls");
		printBoard();
		//Print the results!
		if (p1Turn == false && roundCount <= 8) {		//p1Turn is flipped for this part. false == p1, true == p2
			std::cout << "\n\nPlayer 1 wins!";
		}
		else if(p1Turn == true && roundCount <= 8)
		{
			std::cout << "\n\nPlayer 2 wins!";
		}

		if (roundCount >= 9) 
		{
			std::cout << "\n\nIts a Tie!";
		}

		std::cout << "\n\nWould you like to play again? (Y/N)   \n";
		playAgain = _getch();
		if (playAgain == 'N' || playAgain == 'n') 
		{
			return 0;		//Ends the program
		}
		resetGame();
		system("pause");
	}
}