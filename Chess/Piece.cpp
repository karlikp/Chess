#include "Piece.h"
#include "Background.h"

Piece::Piece()
{
}

Piece::Piece(vector<string> table)
{
	board = table;
}

Piece::~Piece()
{
}

void Piece::checkDetection()
{
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


