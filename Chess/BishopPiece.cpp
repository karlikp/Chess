#include "BishopPiece.h"
#include "functions.h"

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


				if (lackYourPiece(letter, number)
					and positionIncludeInBoard(letter, number))
				{
					moveScope.push_back({ letter, number });
				}

				if (occupiedPosition(letter, number))
					break;
			}
		}
	}
	for (auto i : moveScope)
	{
		cout << "[" << i.first << "," << i.second << "]";
	}
}

bool BishopPiece::checkMoveAccess(pair<char, int> finishPosition)
{
}
