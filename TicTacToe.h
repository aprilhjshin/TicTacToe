/*
Jonah Moon
CS/IS 137
Homework 1

****************************************************************************************
						TicTacToe
----------------------------------------------------------------------------------------
	-boardArr     : int[3][3]
	-player1      : string
	-player2      : string
	-winner       : int

----------------------------------------------------------------------------------------
	+TicTacToe()
	+startMenu() : void
	-nameSetUp() : void
	-moveMenu() : void
	-setPlayer1(name : string) : bool
	-setPlayer2(name : string) : bool
	-getPlayer1(name : string) : string
	-getPlayer1(name : string) : string
	-showBoard() : void
	-checkGame() : int
	-gameWinner() : int
	-showWinner() : void
	-makeMove(playerNum : int, row : int, column : int) : bool

*/

#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <string>
using namespace std;

class TicTacToe
{
	private:

		int boardArr[3][3];
		string player1;
		string player2;
		int winner;
		bool setPlayer1(string);
		bool setPlayer2(string);
		string getPlayer1()const;
		string getPlayer2()const;
		void nameSetUp();
		void moveMenu();
		void showBoard();
		bool makeMove(int, int, int);
		int checkGame();
		int gameWinner();
		void showWinner();

	public:
		TicTacToe();
		void startMenu();


};
#endif