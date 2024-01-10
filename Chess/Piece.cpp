#include "Piece.h"
#include "Background.h"

Piece::Piece()
{
}

Piece::~Piece()
{
}

void Piece::insertMoveScope(vector <pair<char, int>> tempMoveScope)
{
	moveScope = tempMoveScope;
}


bool Piece::lackYourPiece(char letter, int number)
{
	bool lackOwnPiece = true;
	board = Background::getBoard();

	int rowIndex = 10 - number;
	int columnIndex = 4 + (letter - 'A') * 3;
	int signColumnIndex = columnIndex - 1;

	if (board[rowIndex][signColumnIndex] == Background::tempSign and
		board[rowIndex][columnIndex] != '0')
		lackOwnPiece = false;

	return lackOwnPiece;
}


bool Piece::checkMoveAccess()
{
	if (scopeIsEnough() and lackCheck())
		return true;
	else
		return false;
}

bool Piece::scopeIsEnough()
{
	bool access = false;
	for (auto coords : moveScope)
	{
		if (coords.first == letterCoord and coords.second == numberCoord)
		{
			access = true;
			break;
		}
	}
	return access;
}

bool Piece::lackCheck()
{
	
	int rowIndex = 10 - numberCoord;
	int columnIndex = 4 + (letterCoord - 'A') * 3;
	
	if (board[rowIndex][columnIndex] != '6')
		return true;
	else
		return false;

}

pair<char, int> Piece::getFinalPosition()
{
	cout << "\nType in coordinate where you're going to do a move: ";

	pair<char,int> finalPosition =  getPosition();
	
	letterCoord = finalPosition.first;
	numberCoord = finalPosition.second;
	return  finalPosition;
}


