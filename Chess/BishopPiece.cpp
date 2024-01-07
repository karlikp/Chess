#include "BishopPiece.h"

BishopPiece::BishopPiece(vector<string> table)
{
	board = table;
}

BishopPiece::~BishopPiece()
{
}

void BishopPiece::getScope(pair<char, int> startPosition)
{
	vector<pair<int, int>> bishopStep = { {1,1}, {1,-1}, {-1,-1}, {-1,1} };

	{		
		for (int i = 0; i < 4; i++)
		{
			char letter = startPosition.first;
			int number = startPosition.second;

			for (int j = 0; j < 7; j++)
			{
				letter = char(int(letter) + bishopStep[i].first);
				number += bishopStep[i].second;

				if ((number > 8 or number < 1) or 
					(int(letter) > int('H') or int(letter) < int('A')))
					break;

				if(lackYourPiece(letter, number))
					moveScope.push_back({ letter, number });

				int rowIndex = 10 - number;
				int columnIndex = 4 + (letter - 65) * 3;

				if (board[rowIndex][columnIndex] != '0')
					break;
			}
		}
	}
	for (auto i : moveScope)
	{
		cout << "[" << i.first << "," << i.second << "]";
	}
}

void BishopPiece::checkMovePossibility(pair<char, int> finishPosition)
{
}
