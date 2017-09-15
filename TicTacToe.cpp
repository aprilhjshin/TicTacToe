/*
Jonah Moon
CSIS 137
Homework 1
*/

#include "TicTacToe.h"
#include <iostream>
using namespace std;

// default constructor to initialize the board array to zeroes
// initialize private winner variable to zero for program to run
TicTacToe::TicTacToe()
{

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			boardArr[i][j] = 0;
		}

	}
	winner = 0;
}

//private showBoard function to display the board
void TicTacToe::showBoard()
{
	cout << "	Column\n       1  2  3" << endl ;
	for (int i = 0; i < 3; i++)
	{
		cout <<"Row " << i +1 << " " ;
		for (int j = 0; j < 3; j++)
		{
			cout << "|" << boardArr[i][j] << "|";
		}

		cout << endl;
	}
}

// function to make a move
//the player that is moving, the row and column that was chosen to insert their move
bool TicTacToe::makeMove(int player, int row, int col)
{
	bool posStatus;

	if (boardArr[row-1][col-1] == 0)
	{
		boardArr[row-1][col-1] = player;
		posStatus = true;

	}
	else
	{
		posStatus = false;
	}

	return posStatus;
}

// checks for win or draw
int TicTacToe::checkGame()
{
	int zeroes = 0;
	if (boardArr[0][0] == boardArr[1][1] && boardArr[1][1] == boardArr[2][2])
	{
		if (boardArr[0][0] == 1)
		{
			winner = 1;
		}
		else if (boardArr[0][0] == 2)
		{
			winner = 2;
		}
	}
	if (boardArr[0][2] == boardArr[1][1] && boardArr[1][1] == boardArr[2][0])
	{
		if (boardArr[0][2] == 1)
		{
			winner = 1;
		}
		else if (boardArr[0][2] == 2)
		{
			winner = 2;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (boardArr[i][0] != 0)
		{
			if (boardArr[i][0] == boardArr[i][1] && boardArr[i][1] == boardArr[i][2])
			{
				if (boardArr[i][0] == 1)
				{
					winner = 1;
				}
				else if (boardArr[i][0] == 2)
				{
					winner = 2;
				}
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (boardArr[0][i] != 0)
		{
			if (boardArr[0][i] == boardArr[1][i] && boardArr[1][i] == boardArr[2][i])
			{
				if (boardArr[0][i] == 1)
				{
					winner = 1;
				}
				else if (boardArr[0][i] == 2)
				{
					winner = 2;
				}

			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (boardArr[i][j] == 0)
			{
				zeroes++;
			}
		}
	}
	if (zeroes == 0 && winner == 0)
	{
		winner = 3;
	}
	return winner;
}
//set player1 name
bool TicTacToe::setPlayer1(string name)
{
	player1 = name;
	return true;
}
//set player2 name is the name is taken return false
bool TicTacToe::setPlayer2(string name)
{
	if (name != player1)
	{
		player2 = name;
		return true;
	}
	else
	{
		return false;
	}
}
//function to return winner or draw
int TicTacToe::gameWinner()
{
	return winner;
}
string TicTacToe::getPlayer1()const
{
	return player1;
}
string TicTacToe::getPlayer2()const
{
	return player2;
}
void TicTacToe::moveMenu()
{
	int a, b;
	//a loop to have the players' moves alternate
	for (int i = 1; i < 3; i++)
	{
		showBoard();
		cout << "\nPlayer " << i << ", make your move! Enter row and press enter, "
			<<"enter column and press enter." << endl;
		cin >> a;
		cin.ignore();
		cin >> b;
		cin.ignore();
		if (makeMove(i, a, b) == false)
		{
			cout << "A player has moved there already, pick another spot!" << endl;
			i--;
		}
		if (makeMove(i, a, b) == true)
			// this block never gets executed but i dont know why
		{

		}
		if (checkGame() != 0)
		{
			// set i to a number bigger than 2 so that it will exit the loop
			i = 10;
		}
	}
}
void TicTacToe::nameSetUp()
{
	string name;
	cout << "What is the name of player 1?" << endl;
	cin >> name;
	cin.ignore();
	setPlayer1(name);
	cout << "What is the name of player 2?" << endl;
	cin >> name;
	cin.ignore();
	while (setPlayer2(name) == false)
	{
		cout << "Please enter a different name as player 1!" << endl;
		cin >> name;
		cin.ignore();
	}
}
void TicTacToe::showWinner()
{
	if (gameWinner() == 1)
	{
		cout << "Congratulations! " << getPlayer1() << ", you are the winner!" << endl;
		showBoard();
	}
	else if (gameWinner() == 2)
	{
		cout << "Congratulations! " << getPlayer2() << ", you are the winner!" << endl;
		showBoard();
	}
	else if (gameWinner() == 3)
	{
		cout << "This game is a draw!" << endl;
		showBoard();
	}
}
void TicTacToe::startMenu()
{
	char selection;
	cout << "Welcome to the Tic Tac Toe Game! Would you like to play? Y for yes, N for no." << endl;
	cin >> selection;
	selection = toupper(selection);
	cin.ignore();
	while (selection != 'Y' && selection != 'N')
	{
		cout << "Invalid input! Enter Y for yes or N for no!" << endl;
		cin >> selection;
		selection = toupper(selection);
		cin.ignore();
	}
	do
	{
		if (selection == 'Y')
		{
			nameSetUp();
			while (checkGame() == 0)
			{
				moveMenu();
			}
			showWinner();
		}
		cout << "Would you like to run the program again? Y for yes, N for no" << endl;
		cin >> selection;
		selection = toupper(selection);
		cin.ignore();
	} while (selection != 'N');
}