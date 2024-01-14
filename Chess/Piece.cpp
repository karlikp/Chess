#include "Piece.h"
#include "Background.h"
#include "functions.h"
#include "Player.h"

set<pair<char, int>> Piece::currentMoveScope;

Piece::Piece()
{
	board = Background::getBoard();
}

Piece::~Piece()
{
	currentMoveScope.clear();
}

bool Piece::lackYourPiece(char letter, int number)
{
	bool lackOwnPiece = true;
	
	int rowIndex = 10 - number;
	int columnIndex = 4 + (letter - 'A') * 3;
	int signColumnIndex = columnIndex - 1;

	if (board[rowIndex][signColumnIndex] == Player::getCurrentSign() and
		board[rowIndex][columnIndex] != '0')
		lackOwnPiece = false;

	return lackOwnPiece;
}


bool Piece::scopeValidation()
{
	for (auto coords : currentMoveScope)
	{
		if (coords.first == letterCoord and coords.second == numberCoord)
		{
			return true;
		}
	}
	cout << "\n The position isn't access. Type in correct move position: ";
	return false;
}


pair<char, int> Piece::getFinalPosition()
{
	cout << "\nType in coordinate where you're going to do a move: ";
	pair<char, int> finalPosition;
	do
	{
		finalPosition = getPosition();
		letterCoord = finalPosition.first;
		numberCoord = finalPosition.second;

	} while (not scopeValidation());

	return finalPosition;
}

bool Piece::checkEmptinessScope()
{
	if (currentMoveScope.empty())
	{
		cout << "\nThis piece cannot move, choose another one.";
		return true;
	}
	return false;
}
