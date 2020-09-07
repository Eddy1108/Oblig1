//Oblig 1 Task, TicTacToe

#include <iostream>
#include <string>
#include <Windows.h>

char place[9] = { '1', '2', '3','4','5','6','7','8','9' };

void calculateWin() 
{

}

void printBoard() {
	
	char board[5][16] = 
	{
		" -------------\n",
		"| " + place[0] + " | 2 | 3 | \n",
		"| 4 | 5 | 6 | \n",
		"| 7 | 8 | 9 | \n",
		"------------- \n"
	};

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			if (board[i][j] == place[0]) {
				std::cout << "X";
			}
			else {
				std::cout << board[i][j];
			}
		}
	}
}

int main()
{
	std::cout << "****** Welcome to Tic Tac Toe! ******\n\n";

	//system("cls");
	printBoard();

}
