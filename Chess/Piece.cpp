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

bool Piece::scopeIsEnough(pair<char, int> finishPosition)
{
	bool access = false;
	for (auto i : moveScope)
	{
		if (i == finishPosition)
		{
			access = true;
			break;
		}
	}
	return access;
}


