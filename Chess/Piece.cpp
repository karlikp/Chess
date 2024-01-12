#include "Piece.h"
#include "Background.h"

Piece::Piece()
{
}

Piece::~Piece()
{
}

//void Piece::insertMoveScope(vector <pair<char, int>> tempMoveScope)
//{
//	moveScope = tempMoveScope;
//}


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


bool Piece::moveValidation()
{
	if (scopeValidation() and lackCheck())
		return true;
	else
		return false;
}

bool Piece::scopeValidation()
{
	for (auto coords : moveScope)
	{
		if (coords.first == letterCoord and coords.second == numberCoord)
		{
			return true;
		}
	}
	cout << "\n The position isn't access. Type in coorect move position: ";
	return false;
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
	return moveScope.empty();
}
