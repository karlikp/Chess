#include "PawnPiece.h"
#include "Background.h"

PawnPiece::PawnPiece(vector<string> table)
{
	board = table;

	letter = {};
	number = {};
	signRow = {};
	signColumn = {};
	sign = {};
}

PawnPiece::~PawnPiece()
{
}

void PawnPiece::getScope(pair<char, int> startPosition)
{
	letter = startPosition.first;
	number = startPosition.second;

	signRow = 10 - number;
	signColumn = 3 + (letter - 65) * 3;
	sign = board[signRow][signColumn];

	bool singleStepAccess = singleStepIsEmpty();
	bool doubleStepAccess = doubleStepIsEmpty();

	if (singleStepAccess and sign == '-')
	{
			moveScope.push_back({letter, number - 1});

		if (number == 7 and doubleStepAccess )
			moveScope.push_back({letter, number - 2});
	}
	else if (singleStepAccess and sign == ' ')
	{
		moveScope.push_back({letter, number + 1 });

		if (number == 2 and doubleStepAccess)
			moveScope.push_back({letter, number + 2});
	}

	checkAttackScope();
	
	for (auto i : moveScope)
	{
		cout << "[" << i.first << "," << i.second << "]";
	}
}

void PawnPiece::checkMovePossibility(pair<char, int> finishPosition)
{
}

bool PawnPiece::doubleStepIsEmpty()
{
	bool access = false;
	if (sign == ' ' and board[signRow - 2][signColumn + 1] == '0')
		access = true;
	else if (sign == '-' and board[signRow + 2][signColumn + 1] == '0')
		access = true;
	return access;
}

bool PawnPiece::singleStepIsEmpty()
{
	bool access = false;
	if (sign == ' ' and board[signRow - 1][signColumn + 1] == '0')
		access = true;
	else if (sign == '-' and board[signRow + 1][signColumn + 1] == '0')
		access = true;
	return access;
}

void PawnPiece::checkAttackScope()
{
	if (sign == '-')
	{
		if (board[signRow + 1][signColumn - 2] != '0'
			and lackYourPiece(char(int(letter) - 1), number - 1))
		{
			moveScope.push_back({ char(int(letter) - 1), number - 1 });
		}
		if (board[signRow + 1][signColumn + 4] != '0'
			and lackYourPiece(char(int(letter) + 1), number - 1))
		{
			moveScope.push_back({ char(int(letter) + 1), number - 1 });
		}
	}
	else
	{
		if (board[signRow - 1][signColumn - 2] != '0'
			and lackYourPiece(char(int(letter) - 1), number + 1))
		{
			moveScope.push_back({ char(int(letter) - 1), number + 1 });
		}
		if (board[signRow - 1][signColumn + 4] != '0'
			and lackYourPiece(char(int(letter) + 1), number + 1))
		{
			moveScope.push_back({ char(int(letter) + 1), number + 1 });
		}
	}
}
