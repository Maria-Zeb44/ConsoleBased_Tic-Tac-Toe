#include<iostream>
#include"TTT.h"
using namespace std;

TTT::TTT()
{
	size = 3;
	Cplayer = 'O';

	board = new char* [size];
	for (int i = 0; i < size; i++)
	{
		board[i] = new char[size];

		for (int j = 0; j < size; j++)
		{
			board[i][j] = ' ';
		}
	}
}

TTT::~TTT()
{
	for (int i = 0; i < size; i++)
		delete[]board[i];
	delete[]board;
}


void TTT::makeMove(int r, int c)
{
	if (isVAlidMove(r, c)) {
		board[r][c] = Cplayer;

		display();

		if (checkWin())
		{
			cout << "player " << Cplayer << " has won!";
			return;
		}
		else if (isDraw())
		{
			cout << "game drawn!";
			return;
		}
		if (Cplayer == 'X') {
			Cplayer = 'O';

		}
		else if (Cplayer == 'O') {
			Cplayer = 'X';
		}
	}

	else cout << "invalid move!\n";
}

void TTT::display()
{
	for (int i = 0; i < size; i++)
	{
		cout << " | ";
		for (int j = 0; j < size; j++)
		{
			cout << board[i][j] << " | ";

		}cout << endl;
	}
}
bool TTT::isVAlidMove(int r, int c)
{
	return (r >= 0 && r < size && c >= 0 && c < size && board[r][c] == ' ');
}

bool TTT::checkWin() {

	for (int i = 0; i < size; i++) {

		if (board[i][0] == Cplayer && board[i][1] == Cplayer && board[i][2] == Cplayer)
			return true;
		if (board[0][i] == Cplayer && board[1][i] == Cplayer && board[2][i] == Cplayer)
			return true;
	}

	if (board[0][0] == Cplayer && board[1][1] == Cplayer && board[2][2] == Cplayer)
		return true;
	if (board[0][2] == Cplayer && board[1][1] == Cplayer && board[2][0] == Cplayer)
		return true;

	return false;
}

bool TTT::isDraw()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (board[i][j] == ' ')
				return false;
		}
	}
	return true;
}
void TTT::resetBoard() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			board[i][j] = ' ';
		}
	}
	Cplayer = 'O';

}

void TTT::play()
{
	int r, c;
	while (true)
	{

		cout << "player " << Cplayer << " , enter row ,col (0-2) :";
		cin >> r >> c;
		makeMove(r, c);


		if (checkWin() || isDraw())
		{
			char furtherPlay;
			cout << "if you want to play further press 'Y'";
			cin >> furtherPlay;
			if (furtherPlay == 'Y' || furtherPlay == 'y')
			{
				resetBoard();
				display();
				continue;

			}
			else {
				break;
			}

		}
	}
}


