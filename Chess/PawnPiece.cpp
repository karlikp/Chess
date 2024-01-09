#include "PawnPiece.h"
#include "Background.h"

PawnPiece::PawnPiece(vector<string> table)
{
	board = table;
	letter = {};
	number = {};
	sign = {};
}

PawnPiece::~PawnPiece()
{
}

vector<pair<char, int>> PawnPiece::getScope(pair<char, int> startPosition)
{

	letter = startPosition.first;
	number = startPosition.second;

	int signRow = 10 - number;
	int signColumn = 3 + (letter - 65) * 3;
	sign = board[signRow][signColumn];

	bool singleStepAccess = singleStepIsEmpty();
	bool doubleStepAccess = doubleStepIsEmpty();

	if (singleStepAccess and sign == '-'
		and positionIncludeInBoard(letter, number - 1))
	{
		tempMoveScope.push_back({ letter, number - 1 });

		if (number == 7 and doubleStepAccess
			and positionIncludeInBoard(letter, number - 2))
			tempMoveScope.push_back({ letter, number - 2 });
	}
	else if (singleStepAccess and sign == ' '
		and positionIncludeInBoard(letter, number + 1))
	{
		tempMoveScope.push_back({letter, number + 1 });

		if (number == 2 and doubleStepAccess 
			and positionIncludeInBoard(letter, number + 2))
			tempMoveScope.push_back({letter, number + 2});
	}

	checkAttackScope();
	
	showAccessPositions(tempMoveScope);
	return tempMoveScope;
}

bool PawnPiece::checkMoveAccess(pair<char, int> finishPosition)
{
	return 0;
}

bool PawnPiece::doubleStepIsEmpty()
{
	bool access = false;

	if (sign == ' ' and not occupiedPosition(letter, number + 2))
		access = true;
	else if (sign == '-' and not occupiedPosition(letter, number - 2))
		access = true;

	return access;
}

bool PawnPiece::singleStepIsEmpty()
{
	bool access = false;
	
	if (sign == ' ' and (not occupiedPosition(letter, number + 1)))
		access = true;
	else if (sign == '-' and (not occupiedPosition(letter, number - 1)))
		access = true;

	return access;
}

void PawnPiece::checkAttackScope()
{
	if (sign == '-')
	{
		if (occupiedPosition(char(int(letter) - 1 ), number - 1)
			and lackYourPiece(char(int(letter) - 1), number - 1)
			and positionIncludeInBoard(char(int(letter) - 1), number - 1))
		{
			tempMoveScope.push_back({ char(int(letter) - 1), number - 1 });
		}
		if (occupiedPosition(char(int(letter) + 1), number - 1)
			and lackYourPiece(char(int(letter) + 1), number - 1)
			and positionIncludeInBoard(char(int(letter) + 1), number - 1))
		{
			tempMoveScope.push_back({ char(int(letter) + 1), number - 1 });
		}
	}
	else
	{
		if (occupiedPosition(char(int(letter) - 1), number + 1)
			and lackYourPiece(char(int(letter) - 1), number + 1)
			and positionIncludeInBoard(char(int(letter) - 1), number + 1))
		{
			tempMoveScope.push_back({ char(int(letter) - 1), number + 1 });
		}
		if (occupiedPosition(char(int(letter) + 1), number + 1)
			and lackYourPiece(char(int(letter) + 1), number + 1)
			and positionIncludeInBoard(char(int(letter) + 1), number + 1))
		{
			tempMoveScope.push_back({ char(int(letter) + 1), number + 1 });
		}
	}
}
