/*
Jonah Moon
CSIS137 dfsfasdf
Homework 1
*/

#include "TicTacToe.h"
#include <iostream>
#include <cctype>
using namespace std;

int main()
{
	char selection;
	string name;

	cout << "Welcome to the Tic Tac Toe Game! Would you like to play? Y for yes, N for no." << endl;
	cin >> selection;
	selection = toupper(selection);
	cin.ignore();

	do
	{



		if (selection == 'Y')
		{
			TicTacToe game;

			cout << "What is the name of player 1?" << endl;
			cin >> name;
			cin.ignore();
			game.setPlayer1(name);
			cout << "What is the name of player 2?" << endl;
			cin >> name;
			cin.ignore();
			while (game.setPlayer2(name) == false)
			{
				cout << "Please enter a different name as player 1!" << endl;
				cin >> name;
				cin.ignore();
			}
			//game.showBoard();
			do
			{
				for (int i = 1; i < 3; i++)
				{
					int a, b;
					cout << "Player " << i << ", make your move! Enter row and column." << endl;
					game.showBoard();
					cin >> a;
					cin.ignore();
					cin >> b;
					if (game.makeMove(i, a, b) == false)
					{
						cout << "A player has moved there already, pick another spot!" << endl;
						i--;
					}
					else if (game.makeMove(i, a, b) == true)
					{
						cout << "Nice move!" << endl;
					}
				}
			
			} while (game.gameOver() == false);

			if (game.gameWinner() == 1)
			{
				cout << "Congratulations! " << game.getPlayer1() << ", you are the winner!" << endl;
			}
			else if (game.gameWinner() == 2)
			{
				cout << "Congratulations! " << game.getPlayer2() << ", you are the winner!" << endl;
			}
			
			
		}

		cout << "Would you like to play again? Y for yes, N for no" << endl;
		cin >> selection;
		selection = toupper(selection);
		cin.ignore();
	} while (selection != 'N');

	system("PAUSE");
	return 0;
}