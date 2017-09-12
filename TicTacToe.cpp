/*
Jonah Moon
CSIS 137
Homework 1
*/

#include "TicTacToe.h"
#include <iostream>
using namespace std;

// default constructor to initialize the board array to zeroes
TicTacToe::TicTacToe()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			boardArr[i][j] = 0;
		}

	}
	gameState = false;
	winner = 0;
}

void TicTacToe::showBoard()
{
	//enum choice { X = 1, O = 2 };
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

bool TicTacToe::makeMove(int player, int row, int col)
{
	//enum choice { X = 1, O = 2 };
	bool posStatus;

	if (boardArr[row-1][col-1] == 0)
	{
		boardArr[row-1][col-1] = player;
		posStatus = true;
		
		for (int i = 0; i < 3; i++)
		{
			if (boardArr[i][0] + boardArr[i][1] + boardArr[i][2]  == 3)
			{	
				if (boardArr[i][0] == boardArr[i][1] && boardArr[i][0] == boardArr[i][2])
				{
					winner = 1;
					gameState = 1;
				}
			}
			else if (boardArr[i][0] + boardArr[i][1] + boardArr[i][2] == 6)
			{
				if (boardArr[i][0] == boardArr[i][1] && boardArr[i][0] == boardArr[i][2])
				{
					winner = 2;
					gameState = 1;
				}
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (boardArr[0][i] + boardArr[1][i] + boardArr[2][i]  == 3)
			{
				if (boardArr[i][0] == boardArr[i][1] && boardArr[i][0] == boardArr[i][2])
				{
					winner = 1;
					gameState = 1;
				}
			}
			else if (boardArr[0][i] + boardArr[1][i] + boardArr[2][i] == 6)
			{
				if (boardArr[i][0] == boardArr[i][1] && boardArr[i][0] == boardArr[i][2])
				{
					winner = 2;
					gameState = 1;
				}
			}
		}





	}
	else
	{
		posStatus = false;
	}

	return posStatus;
}

bool TicTacToe::setPlayer1(string name)
{
	player1 = name;
	return true;
}

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

int TicTacToe::gameWinner()
{
	return winner;
}

bool TicTacToe::gameOver()
{
	return gameState;
}

string TicTacToe::getPlayer1()
{
	return player1;
}

string TicTacToe::getPlayer2()
{
	return player2;
}

