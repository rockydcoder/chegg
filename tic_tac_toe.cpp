#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
char square[10] = { '0','1','2','3','4','5','6','7','8' };
string name;
int splashScreen()//displays game and developer?s information
{
	cout << "Tic Tac Toe" << endl;
	cout << "Developed by XXYYZZ" << endl;
}
int askForUserNames()//requests for username
{
	cout << "Enter the player name:" << endl;
	getline(cin, name);
	return 0;
}
int validateUserName(string name)//validate username
{
	for (int i = 0; i<name.length(); i++)
	{
		if ((name[i] >= 'a' || name[i] >= 'A') && (name[i] <= 'z' || name[i] <= 'Z'))
		{
		}
		else
		{
			return 0;
		}
	}
	return 1;
}
int switchPlayer(int player)//switch from one player to another
{
	player++;
	return player % 2;
}
int resetGame()//reset the game when one concludes; this includes filling the array with vales 0-8
{
	for (int i = 0; i<9; i++)
	{
		square[i] = (char)(i + 48);
	}
	return 0;
}
int displayGrid()//display the grid after each player makes a move
{
	cout << "Player 1 (" << name << ") - Player 2 (O)" << endl << endl;
	cout << endl;
	cout << "   |   | " << endl;
	cout << " " << square[0] << " | " << square[1] << " | " << square[2] << endl;
	cout << "___|___|___" << endl;
	cout << "   |   | " << endl;
	cout << " " << square[3] << " | " << square[4] << " | " << square[5] << endl;
	cout << "___|___|___" << endl;
	cout << "   |   | " << endl;
	cout << " " << square[6] << " | " << square[7] << " | " << square[8] << endl;
	cout << "   |   | " << endl << endl;
	return 0;
}
int validatePlayersMove(int choice)//validates that user entry X is such that 0<=X<=8
{
	if (choice >= 0 && choice <= 8)
	{
		return 1;
	}
	return 0;
}
int checkPositionAvailability(int choice)//check that the position selected by the user is available
{
	if (square[choice] != 'O' && square[choice] != 'X')
	{
		return 1;
	}
	return 0;
}
int playerMakeMove()//prompts player to make a move, invokes validatePlayersMove, checkPositionAvailability
{
	int choice;
	while (1)
	{
		cout << " Make a move: " << endl;
		cin >> choice;
		if (validatePlayersMove(choice))
		{
			if (checkPositionAvailability(choice))
			{
				break;
			}
			else
			{
				cout << "invalid move";
			}
		}
		else
			cout << "invalid move";
	}
	char mark;
	mark = 'X';
	if (choice == 0 && square[0] == '0')
		square[0] = mark;
	else if (choice == 1 && square[1] == '1')
		square[1] = mark;
	else if (choice == 2 && square[2] == '2')
		square[2] = mark;
	else if (choice == 3 && square[3] == '3')
		square[3] = mark;
	else if (choice == 4 && square[4] == '4')
		square[4] = mark;
	else if (choice == 5 && square[5] == '5')
		square[5] = mark;
	else if (choice == 6 && square[6] == '6')
		square[6] = mark;
	else if (choice == 7 && square[7] == '7')
		square[7] = mark;
	else if (choice == 8 && square[8] == '8')
		square[8] = mark;
}
int checkWin()//check for a winning player
{
	if (square[0] == square[1] && square[1] == square[2])
		return 1;
	else if (square[3] == square[4] && square[4] == square[5])
		return 1;
	else if (square[6] == square[7] && square[7] == square[8])
		return 1;
	else if (square[0] == square[3] && square[3] == square[6])
		return 1;
	else if (square[1] == square[4] && square[4] == square[7])
		return 1;
	else if (square[2] == square[5] && square[5] == square[8])
		return 1;
	else if (square[0] == square[4] && square[4] == square[8])
		return 1;
	else if (square[2] == square[4] && square[4] == square[6])
		return 1;
	else
		return 0;
}
int checkTie()//check for a tie
{
	if (square[1] != '1' && square[2] != '2' && square[3] != '3'
		&& square[4] != '4' && square[5] != '5' && square[6] != '6'
		&& square[7] != '7' && square[8] != '8' && square[0] != '0')
		return 1;
	return 0;
}
int makeBestMove()//select best option
{
}
int computerMakeMove()//used to make the move, in other words populate the array
{
	int choice;
	do
	{
		choice = rand() % 9;
		if (square[choice] != 'X'&& square[choice] != 'O')
		{
			break;
		}
	} while (1);
	char mark = 'O';
	if (choice == 0 && square[0] == '0')
		square[0] = mark;
	else if (choice == 1 && square[1] == '1')
		square[1] = mark;
	else if (choice == 2 && square[2] == '2')
		square[2] = mark;
	else if (choice == 3 && square[3] == '3')
		square[3] = mark;
	else if (choice == 4 && square[4] == '4')
		square[4] = mark;
	else if (choice == 5 && square[5] == '5')
		square[5] = mark;
	else if (choice == 6 && square[6] == '6')
		square[6] = mark;
	else if (choice == 7 && square[7] == '7')
		square[7] = mark;
	else if (choice == 8 && square[8] == '8')
		square[8] = mark;
	return 0;
}
int main()
{
	int player = 1;
	splashScreen();
	while (1)
	{
		askForUserNames();
		if (validateUserName(name))
		{
			break;
		}
		else
			cout << "invalid name" << endl;
	}
	displayGrid();
	while (1)
	{
		if (player == 1)
			playerMakeMove();
		else
			computerMakeMove();
		displayGrid();
		if (checkWin())
		{
			if (player == 1)
			{
				cout << "Player " << name << " win" << endl;
			}
			else
				cout << "Computer win" << endl;
			break;
		}
		else if (checkTie())
		{
			cout << "tie" << endl;
			break;
		}
		player = switchPlayer(player);
	}
	return 0;
}